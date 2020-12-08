#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <fstream>
#include <sstream>

#include "Node.H"
#include "WhiteSpaceStrategy.H"
#include "Visitor.H"
class Visitor;

namespace dom
{
	class Element;
	class Text;
	class Attr;
	class NodeList;

	/** DECORATOR PATTERN - Component
	 * This is the class that defines the interface for the Decorator and ConcreteDecorator
	 **/
	class Document : public virtual Node
	{
	public:
		virtual Element *	createElement(const std::string & tagName)	= 0;
		virtual Text *		createTextNode(const std::string & data)	= 0;
		virtual Attr *		createAttribute(const std::string & name)	= 0;
		virtual Element *	getDocumentElement()				= 0;
	};
};

//VISITOR PATTERN - ConcreteElement
class Document_Impl : public virtual dom::Document, public virtual Node_Impl
{
public:
	Document_Impl(void);

	virtual ~Document_Impl();

	virtual dom::Element *	createElement(const std::string & tagName);
	virtual dom::Text *	createTextNode(const std::string & data);
	virtual dom::Attr *	createAttribute(const std::string & name);
	virtual dom::Element *	getDocumentElement();
	virtual std::string serialize(int level=0);
	virtual std::string accept(Visitor * );
};


#endif // DOCUMENT_H
