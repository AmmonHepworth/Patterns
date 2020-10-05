#include "Attr.H"

Attr_Impl::Attr_Impl(const std::string & tagName, dom::Document * document) : Node_Impl(tagName, dom::Node::ATTRIBUTE_NODE)
{
	Node_Impl::document	= document;
}

Attr_Impl::Attr_Impl(const std::string & tagName, const std::string & value, dom::Document * document) :
  Node_Impl(tagName, dom::Node::ATTRIBUTE_NODE)
{
	Node_Impl::document	= document;
	setValue(value);
}

Attr_Impl::~Attr_Impl() {}

const std::string &	Attr_Impl::getName(void)
{
	return Node_Impl::getNodeName();
}

const std::string &	Attr_Impl::getValue(void)
{
	return Node_Impl::getNodeValue();
}

void			Attr_Impl::setValue(const std::string & value)
{
	Node_Impl::setNodeValue(value);
}

dom::Element *		Attr_Impl::getOwnerElement(void)
{
	return (dom::Element *)Node_Impl::getParentNode();
}


/** COMPOSITE
 * Prevent this leaf node from adding children
 * The others children functions from Node_Impl should work fine,
 *  since they'll just return empty lists that can be dealt with
 **/
dom::Node *		Attr_Impl::insertBefore(dom::Node * newChild, dom::Node * refChild)
{
	//do nothing, child cannot be added
	return 0;
	
}

dom::Node *		Attr_Impl::replaceChild(dom::Node * newChild, dom::Node * oldChild)
{
	//do nothing, child cannot be added
	return 0;
}

dom::Node *		Attr_Impl::removeChild(dom::Node * oldChild)
{
	//do nothing, child cannot be added
	return 0;
}

dom::Node *		Attr_Impl::appendChild(dom::Node * newChild)
{
	//do nothing, child cannot be added
	return 0;
}