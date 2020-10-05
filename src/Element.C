#include "Element.H"
#include "Attr.H"
#include "Document.H"

Element_Impl::Element_Impl(const std::string & tagName, dom::Document * document) : Node_Impl(tagName, dom::Node::ELEMENT_NODE)
{
	Node_Impl::document	= document;
}

Element_Impl::~Element_Impl()
{
}

const std::string &	Element_Impl::getAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		if ((*i)->getNodeName() == name)
			return (*i)->getNodeValue();
	}

	static const std::string	empty_string("");
	return empty_string;
}

dom::Attr *		Element_Impl::getAttributeNode(const std::string & name)
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		if ((*i)->getNodeName() == name)
			return dynamic_cast<dom::Attr *>(*i);
	}

	return 0;
}

dom::NodeList *		Element_Impl::getElementsByTagName(const std::string & tagName)
{
	dom::NodeList *	nodeList	= new dom::NodeList();

	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		dom::Element *	element;

		if ((element = dynamic_cast<dom::Element *>(*i.operator->())) && element->getNodeName().compare(tagName)==0)
			nodeList->push_back(*i.operator->());
	}

	return nodeList;
}

bool			Element_Impl::hasAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		dom::Attr * attr = dynamic_cast<dom::Attr *>(*i.operator->());

		if (attr != 0 && attr->getName().compare(name) == 0)
			return true;
	}

	return false;
}

void			Element_Impl::removeAttribute(const std::string & name)
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		if ((*i)->getNodeName() == name)
		{
			getChildNodes()->erase(i);
			return;
		}
	}
}

void			Element_Impl::setAttribute(const std::string & name, const std::string & value)
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
	{
		if ((*i)->getNodeName().compare(name) == 0)
		{
			(*i)->setNodeValue(value);
			return;
		}
	}

	dom::Attr *	attribute;
	getChildNodes()->push_back(attribute = new Attr_Impl(name, value, dynamic_cast<Document_Impl *>(getOwnerDocument())));
	dynamic_cast<Node_Impl *>(dynamic_cast<Node *>(attribute))->setParent(this);
}

dom::Attr *		Element_Impl::setAttributeNode(dom::Attr * newAttr)
{
	if (newAttr->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "Attribute not created by this document.");

	if (newAttr->getParentNode() != 0)
		throw dom::DOMException(dom::DOMException::INUSE_ATTRIBUTE_ERR, "Attribute in use by other element.");

	dom::Attr *	oldAttribute	= 0;

	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
		if ((*i)->getNodeName() == newAttr->getNodeName())
		{
			oldAttribute	= (dom::Attr *)i.operator->();
			getChildNodes()->erase(i);
			break;
		}

	dynamic_cast<Node_Impl *>(dynamic_cast<Node *>(newAttr))->setParent(this);
	getChildNodes()->push_back(newAttr);
	return oldAttribute;
}
