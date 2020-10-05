#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

#include "Node.H"
#include "NamedNodeMap.H"

namespace dom
{
	class Attr;
	class NodeList;
	class Document;

	class Element : public virtual Node
	{
	public:
		virtual ~Element() {}

		virtual const std::string &	getAttribute(const std::string & name)					= 0;
		virtual Attr *			getAttributeNode(const std::string & name)				= 0;
		virtual NodeList *		getElementsByTagName(const std::string & tagName)			= 0;
		virtual bool			hasAttribute(const std::string & name)					= 0;
		virtual void			removeAttribute(const std::string & name)				= 0;
		virtual void			setAttribute(const std::string & name, const std::string & value)	= 0;
		virtual Attr *			setAttributeNode(Attr * newAttr)					= 0;

	};
};

/** COMPOSITE PATTERN - Composite
 * Implements the Component (Node) and has children
 * This class in particular is modified more since it had
 *  attributes being stores in their own container. It has
 *  been modified so that attributes share the nodes container
 *  from Node_Impl. It also has any function that did not have
 *  unique necessary functionality for Attrs removed and will
 *  use the Node_Impl methods if possbile.
 **/
class Element_Impl : public virtual dom::Element, Node_Impl
{
private:
	// no longer used with Composite Pattern
	// NamedNodeMap_Impl	attributes;
protected:
	Element_Impl(const std::string & tagName, dom::Document * document);
public:
	friend class Document_Impl;

	virtual ~Element_Impl();

	virtual const std::string &	getAttribute(const std::string & name);
	virtual dom::Attr *		getAttributeNode(const std::string & name);
	virtual dom::NodeList *		getElementsByTagName(const std::string & tagName);
	virtual bool			hasAttribute(const std::string & name);
	virtual void			removeAttribute(const std::string & name);
	virtual void			setAttribute(const std::string & name, const std::string & value);
	virtual dom::Attr *		setAttributeNode(dom::Attr * newAttr);
};

#endif // ELEMENT_H
