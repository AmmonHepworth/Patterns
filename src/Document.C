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

dom::Node *		Document_Impl::insertBefore(dom::Node * newChild, dom::Node * refChild)
{
	if (getChildNodes()->size() == 1 )
		return 0;
		
	if (newChild->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "New Child is not a part of this document.");

	if (newChild->getParentNode() != 0)
		newChild->getParentNode()->removeChild(newChild);

	if (refChild == 0)
	{
		getChildNodes()->push_back(newChild);
		(dynamic_cast<Node_Impl *>(newChild))->setParent(this);
		return newChild;
	}

	dom::NodeList::iterator	index	= getChildNodes()->find(refChild);

	if (index == getChildNodes()->end())
		throw dom::DOMException(dom::DOMException::NOT_FOUND_ERR, "Reference Child is not a child of this node.");

	getChildNodes()->insert(++index, newChild);
	(dynamic_cast<Node_Impl *>(newChild))->setParent(this);

	return newChild;
}

dom::Node *		Document_Impl::appendChild(dom::Node * newChild)
{
	if (getChildNodes()->size() == 1 )
		return 0;

	if (newChild->getOwnerDocument() != getOwnerDocument())
		throw dom::DOMException(dom::DOMException::WRONG_DOCUMENT_ERR, "New Child is not a part of this document.");

	if (newChild->getParentNode() != 0)
		newChild->getParentNode()->removeChild(newChild);

	getChildNodes()->push_back(newChild);
	(dynamic_cast<Node_Impl *>(newChild))->setParent(this);

	return newChild;
}