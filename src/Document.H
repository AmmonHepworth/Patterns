#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <fstream>
#include <sstream>

#include "Node.H"
#include "XMLValidator.H"
#include "WhiteSpaceStrategy.H"

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

/** STRATEGY PATTERN - ConcreteStrategy
 * This is a ConcreteStrategy, as it implements its own strategy for serialize()
 **/
/** DECORATOR PATTERN - ConcreteComponent
 * This is the class that will be decorated to include its own validation when creating nodes
 * Will also return a Decorated Element class in createElement()
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
	virtual std::string serialize(int level=0);
};

/** DECORATOR PATTERN - Decorator
 * This is the class that would be the base class of all Document Decorators
 * It stores a reference to the decorated class
 **/
class DocumentDecorator : public virtual dom::Document
{
	protected:
	Document_Impl* decoratedDocument;

};

/** DECORATOR PATTERN - ConcreteDecorator
 * This is the class that would be the base class of all Element Decorators
 * It stores a reference to the decorated class
 **/
class DocumentConcreteDecorator : public virtual DocumentDecorator, public virtual Node_Impl
{
	private:
	XMLValidator * validator;


	public:
	DocumentConcreteDecorator(Document_Impl*, XMLValidator*);

	//method forwarding to decorated document
	virtual dom::Element *	createElement(const std::string & tagName);
	virtual dom::Text *	createTextNode(const std::string & data);
	virtual dom::Attr *	createAttribute(const std::string & name);
	virtual dom::Element *	getDocumentElement();
	virtual dom::Node *  appendChild(dom::Node * child);
	virtual std::string serialize(int);
	virtual void setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy * s);

};

#endif // DOCUMENT_H
