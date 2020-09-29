#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <sstream>
#include <fstream>
#include <sstream>


#include "Node.H"
#include "NamedNodeMap.H"
#include "WhiteSpaceStrategy.H"
class XMLValidator;

namespace dom
{
	class Attr;
	class NodeList;
	class Document;

	/** DECORATOR PATTERN - Component
	 * This is the class that the Decorator and ConcreteDecorator will inherit
	 **/
	class Element : public virtual Node
	{
	public:
		virtual ~Element() {}

		virtual const std::string &	getAttribute(const std::string & name)					= 0;
		virtual Attr *			getAttributeNode(const std::string & name)				= 0;
		virtual NodeList *		getElementsByTagName(const std::string & tagName)			= 0;
		virtual const std::string &	getTagName(void)							= 0;
		virtual bool			hasAttribute(const std::string & name)					= 0;
		virtual void			removeAttribute(const std::string & name)				= 0;
		virtual Attr *			removeAttributeNode(Attr * oldAttr)					= 0;
		virtual void			setAttribute(const std::string & name, const std::string & value)	= 0;
		virtual Attr *			setAttributeNode(Attr * newAttr)					= 0;

		virtual dom::NamedNodeMap *	getAttributes(void)							= 0;
		virtual bool			hasAttributes(void)							= 0;
	};
};

/** STRATEGY PATTERN - ConcreteStrategy
 * This is a ConcreteStrategy, as it implements its own strategy for serialize()
 **/
/** DECORATOR PATTERN - ConcreteComponent
 * This is the class that will be decorated to include its own validation
 **/
class Element_Impl : public virtual dom::Element, public virtual Node_Impl
{
private:
	NamedNodeMap_Impl	attributes;
protected:
	Element_Impl(const std::string & tagName, dom::Document * document);
public:
	friend class Document_Impl;
	friend class DocumentConcreteDecorator;

	virtual ~Element_Impl();

	virtual const std::string &	getAttribute(const std::string & name);
	virtual dom::Attr *		getAttributeNode(const std::string & name);
	virtual dom::NodeList *		getElementsByTagName(const std::string & tagName);
	virtual const std::string &	getTagName(void);
	virtual bool			hasAttribute(const std::string & name);
	virtual void			removeAttribute(const std::string & name);
	virtual dom::Attr *		removeAttributeNode(dom::Attr * oldAttr);
	virtual void			setAttribute(const std::string & name, const std::string & value);
	virtual dom::Attr *		setAttributeNode(dom::Attr * newAttr);

	virtual dom::NamedNodeMap *	getAttributes(void)	{ return &attributes; }
	virtual bool			hasAttributes(void)	{ return attributes.size() > 0; }

	virtual std::string serialize(int level=0);
};

/** DECORATOR PATTERN - Decorator
 * This is the class that would be the base class of all Element Decorators
 * It stores a reference to the decorated class
 **/
class ElementDecorator : public virtual dom::Element
{
	protected:
	Element_Impl * decoratedElement;

};

/** DECORATOR PATTERN - ConcreteDecorator
 * This is the class that would be the base class of all Element Decorators
 * It stores a reference to the decorated class
 **/
class ElementConcreteDecorator : public virtual ElementDecorator, public virtual Node_Impl
{
	private:
	XMLValidator * validator;

	public:
	ElementConcreteDecorator(Element_Impl*, XMLValidator*);
	virtual dom::Attr*		setAttributeNode(dom::Attr * newChild);
	virtual void			setAttribute(const std::string & name, const std::string & value);
	virtual dom::Node *		appendChild(dom::Node * newChild);

	//interface completion, just forwards to decoratedElement
	virtual const std::string &	getAttribute(const std::string & name);
	virtual dom::Attr *		getAttributeNode(const std::string & name);
	virtual dom::NodeList *		getElementsByTagName(const std::string & tagName);
	virtual const std::string &	getTagName(void);
	virtual bool			hasAttribute(const std::string & name);
	virtual void			removeAttribute(const std::string & name);
	virtual dom::Attr *		removeAttributeNode(dom::Attr * oldAttr);
	virtual dom::NamedNodeMap *	getAttributes(void)	{ return decoratedElement->getAttributes(); }
	virtual bool			hasAttributes(void)	{ return decoratedElement->hasAttributes(); }

	virtual void setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy *);
	virtual std::string serialize(int level=0);
};

#endif // ELEMENT_H