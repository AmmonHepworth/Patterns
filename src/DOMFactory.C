#include "DOMFactory.H"
#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"

dom::Document * DOMFactory::createDocument()
{
	return new Document_Impl();
}

dom::Element *	DOMFactory::createElement(const std::string & tagName, dom::Document * doc)
{
	return new Element_Impl(tagName, doc);
}

dom::Text *	DOMFactory::createText(const std::string & data, dom::Document * doc)
{
	return new Text_Impl(data, doc);
}

dom::Attr *	DOMFactory::createAttribute(const std::string & name, dom::Document * doc)
{
	return new Attr_Impl(name, doc);
}