#ifndef ATTR_H
#define ATTR_H

#include <string>

#include "Node.H"

namespace dom
{
	class Document;
	class Element;

	class Attr : public virtual Node
	{
	public:
		virtual ~Attr() {}

		virtual const std::string &	getName(void)				= 0;
		virtual const std::string &	getValue(void)				= 0;
		virtual void			setValue(const std::string & value)	= 0;
		virtual Element *		getOwnerElement(void)			= 0;
	};
};

/** COMPOSITE PATTERN - Leaf
 * This pattern is a leaf participant since it should have no children
 *  and so implements those functions as do-nothing operations.
 * It also implements the Component class (Node)
 **/
class Attr_Impl : public virtual dom::Attr, Node_Impl
{
protected:
	Attr_Impl(const std::string & tagName, dom::Document * document);
	Attr_Impl(const std::string & tagName, const std::string & value, dom::Document * document);
public:
	friend class Document_Impl;
	friend class Element_Impl;

	virtual ~Attr_Impl();

	virtual const std::string &	getName(void);
	virtual const std::string &	getValue(void);
	virtual void			setValue(const std::string & value);
	virtual dom::Element *		getOwnerElement(void);

	//COMPOSITE - Prevent leaf from adding children
	virtual dom::Node *		insertBefore(dom::Node * newChild, dom::Node * refChild);
	virtual dom::Node *		replaceChild(dom::Node * newChild, dom::Node * oldChild);
	virtual dom::Node *		removeChild(dom::Node * oldChild);
	virtual dom::Node *		appendChild(dom::Node * newChild);
};

#endif // ATTR_H
