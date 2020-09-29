#include "Element.H"
#include "Attr.H"
#include "Text.H"
#include "Document.H"

Element_Impl::Element_Impl(const std::string & tagName, dom::Document * document) : Node_Impl(tagName, dom::Node::ELEMENT_NODE),
  attributes(document)
{
	Node_Impl::document	= document;
}

Element_Impl::~Element_Impl()
{
}

const std::string &	Element_Impl::getAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr->getName().compare(name) == 0)
			return attr->getValue();
	}

	static const std::string	empty_string("");
	return empty_string;
}

dom::Attr *		Element_Impl::getAttributeNode(const std::string & name)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr->getName().compare(name) == 0)
			return attr;
	}

	return 0;
}

dom::NodeList *		Element_Impl::getElementsByTagName(const std::string & tagName)
{
	dom::NodeList *	nodeList	= new dom::NodeList();

	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		dom::Element *	element;

		if ((element = dynamic_cast<dom::Element *>(*i.operator->())) && element->getTagName().compare(tagName)==0)
			nodeList->push_back(*i.operator->());
	}

	return nodeList;
}

const std::string &	Element_Impl::getTagName(void)
{
	return getNodeName();
}

bool			Element_Impl::hasAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr->getName().compare(name) == 0)
			return true;
	}

	return false;
}

void			Element_Impl::removeAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr->getName().compare(name) == 0)
		{
			attributes.erase(i);
			return;
		}
	}
}

dom::Attr *	Element_Impl::removeAttributeNode(dom::Attr * oldAttr)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
		if (*i.operator->() == oldAttr)
		{
			dom::Attr *	attribute	= (dom::Attr *)i.operator->();
			attributes.erase(i);
			return attribute;
		}

	throw dom::DOMException(dom::DOMException::NOT_FOUND_ERR, "Attribute not found.");
}

void Element_Impl::setAttribute(const std::string & name, const std::string & value)
{
	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr->getName().compare(name) == 0)
		{
			attr->setValue(value);
			return;
		}
	}

	dom::Attr *	attribute;
	attributes.push_back(attribute = new Attr_Impl(name, value, dynamic_cast<Document_Impl *>(getOwnerDocument())));
	dynamic_cast<Node_Impl *>(dynamic_cast<Node *>(attribute))->setParent(this);
}

dom::Attr *		Element_Impl::setAttributeNode(dom::Attr * newAttr)
{
	if (newAttr->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "Attribute not created by this document.");

	if (newAttr->getParentNode() != 0)
		throw dom::DOMException(dom::DOMException::INUSE_ATTRIBUTE_ERR, "Attribute in use by other element.");

	dom::Attr *	oldAttribute	= 0;

	for (dom::NodeList::iterator i = attributes.begin(); i != attributes.end(); i++)
		if (dynamic_cast<dom::Attr *>(*i)->getName().compare(newAttr->getName()) == 0)
		{
			oldAttribute	= (dom::Attr *)i.operator->();
			attributes.erase(i);
			break;
		}

	dynamic_cast<Node_Impl *>(dynamic_cast<Node *>(newAttr))->setParent(this);
	attributes.push_back(newAttr);
	return oldAttribute;
}

/** STRATEGY PATTERN 
 * This function is itself an Implementation of strategy inferface for serialization from Node
 * 
 * This function in turn uses a whitespace Strategy to determine if the whitespace is pretty or minimal
 **/
std::string Element_Impl::serialize(int indentationLevel)
{
	std::stringstream ss;
	ss << wsStrategy->getIndent(indentationLevel);
	ss << "<" << this->getTagName();

	int	attrCount	= 0;

	for (dom::NamedNodeMap::iterator i = this->getAttributes()->begin();
		i != this->getAttributes()->end();
		i++)
	{
		ss <<(*i)->serialize(indentationLevel);
		attrCount++;
	}

	if (attrCount > 0)
		ss << " ";

	if (this->getChildNodes()->size() == 0)
	{
		ss << "/>";
		ss << wsStrategy->getWhiteSpace();
	}
	else
	{
		ss << ">";
		ss << wsStrategy->getWhiteSpace();
		indentationLevel++;

		for (dom::NodeList::iterator i = this->getChildNodes()->begin();
			i != this->getChildNodes()->end();
			i++)
			if (dynamic_cast<dom::Element *>(*i) != 0 || dynamic_cast<dom::Text *>(*i) != 0)
				ss << (*i)->serialize(indentationLevel);
				//serializePretty(*i);

		indentationLevel--;
		ss << wsStrategy->getIndent(indentationLevel);
		ss << "</" << this->getTagName() + ">";
		ss << wsStrategy->getWhiteSpace();
	}
	return ss.str();
}

ElementConcreteDecorator::ElementConcreteDecorator(Element_Impl* elem, XMLValidator* val): Node_Impl("",dom::Node::ELEMENT_NODE)
{
	decoratedElement = elem;
	validator = val;
	Node_Impl::document	= elem->getOwnerDocument();
}

dom::Attr * ElementConcreteDecorator::setAttributeNode(dom::Attr * attr)
{
	if (validator->canAddAttribute(decoratedElement, attr->getName()))
	{
		return decoratedElement->setAttributeNode(attr);
	}
	else
	{
		printf("Attempted invalid schema operation.");
		exit(0);
	}
}

void ElementConcreteDecorator::setAttribute(const std::string & name, const std::string & value)
{
	if (validator->canAddAttribute(decoratedElement, "attribute"))
		decoratedElement->setAttribute(name, value);
	else
	{
		printf("Attempted invalid schema operation.");
		exit(0);
	}
}

dom::Node *	ElementConcreteDecorator::appendChild(dom::Node * child)
{
	if (validator->canAddElement(decoratedElement, "element") || validator->canAddText(decoratedElement))
	{
		decoratedElement->appendChild(child);
	}
	else
	{
		printf("Attempted invalid schema operation.");
		exit(0);
	}
}

const std::string &	ElementConcreteDecorator::getAttribute(const std::string & name)
{
	return decoratedElement->getAttribute(name);
}

dom::Attr * ElementConcreteDecorator::getAttributeNode(const std::string & name)
{
	return decoratedElement->getAttributeNode(name);
}

dom::NodeList *	ElementConcreteDecorator::getElementsByTagName(const std::string & tagName)
{
	return decoratedElement->getElementsByTagName(tagName);
}

const std::string &	ElementConcreteDecorator::getTagName(void)
{
	return decoratedElement->getTagName();
}

bool ElementConcreteDecorator::hasAttribute(const std::string & name)
{
	return decoratedElement->hasAttribute(name);
}

void ElementConcreteDecorator::removeAttribute(const std::string & name)
{
	decoratedElement->removeAttribute(name);
}

dom::Attr *	ElementConcreteDecorator::removeAttributeNode(dom::Attr * oldAttr)
{
	return decoratedElement->removeAttributeNode(oldAttr);
}

void ElementConcreteDecorator::setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy* s)
{
	decoratedElement->setWhiteSpaceStrategyRecursive(s);
}

std::string ElementConcreteDecorator::serialize(int level)
{
	return decoratedElement->serialize(level);
}