#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

#include "Node.H"

namespace dom
{
	class Element;
	class Text;
	class Attr;
	class NodeList;

	class Document : public virtual Node
	{
	public:
		virtual Element *	createElement(const std::string & tagName)	= 0;
		virtual Text *		createTextNode(const std::string & data)	= 0;
		virtual Attr *		createAttribute(const std::string & name)	= 0;
		virtual Element *	getDocumentElement()				= 0;
	};
};

/** COMPOSITE PATTERN - Composite
 * Inherits the Component (Node) through Document and has children
 * This class in particular is modified more since it had
 *  attributes being stores in their own container. It has
 *  been modified so that attributes share the nodes container
 *  from Node_Impl. It also has any function that did not have
 *  unique necessary functionality for Attrs removed and will
 *  use the Node_Impl methods if possbile.
 **/
class Document_Impl : public virtual dom::Document, public virtual Node_Impl
{
public:
	Document_Impl(void);

	virtual ~Document_Impl();

	virtual dom::Element *	createElement(const std::string & tagName);
	virtual dom::Text *	createTextNode(const std::string & data);
	virtual dom::Attr *	createAttribute(const std::string & name);
	virtual dom::Element *	getDocumentElement();
	virtual dom::Node *		appendChild(dom::Node * newChild);
	virtual dom::Node *		insertBefore(dom::Node * newChild, dom::Node * refChild);
};

#endif // DOCUMENT_H
