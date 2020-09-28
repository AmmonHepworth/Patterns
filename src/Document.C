#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"
#include "NodeList.H"

Document_Impl::Document_Impl(void) : Node_Impl("", dom::Node::DOCUMENT_NODE)
{
	Node_Impl::document	= this;
}

Document_Impl::~Document_Impl() {}

dom::Element *	Document_Impl::createElement(const std::string & tagName)
{
	return new Element_Impl(tagName, this);
}

dom::Text *	Document_Impl::createTextNode(const std::string & data)
{
	return new Text_Impl(data, this);
}

dom::Attr *	Document_Impl::createAttribute(const std::string & name)
{
	return new Attr_Impl(name, this);
}

dom::Element * Document_Impl::getDocumentElement()
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
		if (dynamic_cast<dom::Element *>(*i.operator->()) != 0)
			return dynamic_cast<dom::Element *>(*i.operator->());

	return 0;
}

/** STRATEGY PATTERN 
 * Implementation of whitespace strategy inferface from Node
 **/
std::string Document_Impl::serialize(int indentation)
{
		std::stringstream file;
		file <<  "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
		file << wsStrategy->getWhiteSpace();
		file << this->getDocumentElement()->serialize(indentation);
		return file.str();
}



DocumentConcreteDecorator::DocumentConcreteDecorator(Document_Impl* doc, XMLValidator* val):Node_Impl("",dom::Node::DOCUMENT_NODE)
{
	decoratedDocument = doc;
	validator = val;
}


dom::Element *	DocumentConcreteDecorator::createElement(const std::string & tagName)
{
	return decoratedDocument->createElement(tagName);
}

dom::Text *	DocumentConcreteDecorator::createTextNode(const std::string & data)
{
	return decoratedDocument->createTextNode(data);
}

dom::Attr *	DocumentConcreteDecorator::createAttribute(const std::string & name)
{
	return decoratedDocument->createAttribute(name);
}

dom::Element * DocumentConcreteDecorator::getDocumentElement()
{
	for (dom::NodeList::iterator i = getChildNodes()->begin(); i != getChildNodes()->end(); i++)
		if (dynamic_cast<dom::Element *>(*i.operator->()) != 0)
			return dynamic_cast<dom::Element *>(*i.operator->());

	return 0;
}

dom::Node * DocumentConcreteDecorator::appendChild(dom::Node * child)
{
	if (validator->canRootElement("document"))
	{
		decoratedDocument->appendChild(child);
	}
	else
	{
		printf("Attempted invalid schema operation.");
		exit(0);
	}
	return decoratedDocument->appendChild(child);
}

std::string DocumentConcreteDecorator::serialize(int indentationLevel)
{
	return decoratedDocument->serialize(indentationLevel);
}

void DocumentConcreteDecorator::setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy* s)
{
	decoratedDocument->setWhiteSpaceStrategyRecursive(s);
}