#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include "NodeList.H"
#include "WhiteSpaceStrategy.H"

namespace dom
{
	class Document;

	/** STRATEGY PATTERN - Strategy
	 *  Node operates as the "Strategy" class in this pattern
	 *  Below we see the common interface method "serialize" that 
	 *   the ConcreteStrategies (Text_Impl, Attr_Impl, Element_Impl) will implement
	 *  This will then be used by the XMLSerializer to write the appropriate data
	 **/
	/** STRATEGY PATTERN - Context
	 * The Nodes also play the part of a context, having swappable WhiteSpaceStrategies
	 *  that will help determine the kind of whitespace to use in their serialization
	 * In this way, there is a nested Strategy Pattern. This strategy will in turn 
	 *  use yet another strategy.
	 **/
	class Node
	{
	public:
		static const short		ATTRIBUTE_NODE	= 0;
		static const short		DOCUMENT_NODE	= 1;
		static const short		ELEMENT_NODE	= 2;
		static const short		TEXT_NODE	= 3;

		virtual ~Node() {}

		virtual const std::string &	getNodeName(void)				= 0;
		virtual const std::string &	getNodeValue(void)				= 0;
		virtual void			setNodeValue(const std::string & nodeValue)	= 0;
		virtual short			getNodeType(void)				= 0;
		virtual Node *			getParentNode(void)				= 0;
		virtual NodeList *		getChildNodes(void)				= 0;
		virtual Node *			getFirstChild(void)				= 0;
		virtual Node *			getLastChild(void)				= 0;
		virtual Node *			getPreviousSibling(void)			= 0;
		virtual Node *			getNextSibling(void)				= 0;
		virtual Document *		getOwnerDocument(void)				= 0;
		virtual Node *			insertBefore(Node * newChild, Node * refChild)	= 0;
		virtual Node *			replaceChild(Node * newChild, Node * oldChild)	= 0;
		virtual Node *			removeChild(Node * oldChild)			= 0;
		virtual Node *			appendChild(Node * newChild)			= 0;
		virtual bool			hasChildNodes(void)				= 0;
		virtual const std::string &	getLocalName(void)				= 0;
		virtual std::string     serialize(int indentlevel=0)                   = 0;
		virtual void 			setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy * strategy) = 0;
	};

	class DOMException
	{
	private:
		int		reason;
		std::string	description;
	public:
		DOMException(int r, const std::string & d) : reason(r), description(d) {}

		virtual ~DOMException() {}

		int			getReason(void)		{ return reason; }
		const std::string &	getDescription(void)	{ return description; }

		static const int	WRONG_DOCUMENT_ERR		= 0;
		static const int	INUSE_ATTRIBUTE_ERR		= 1;
		static const int	INDEX_SIZE_ERR			= 2;
		static const int	NOT_FOUND_ERR			= 3;
		static const int	NO_MODIFICATION_ALLOWED_ERR	= 4;
		static const int	INVALID_CHARACTER_ERR		= 5;
		static const int	HIERARCHY_REQUEST_ERR		= 6;
	};
};

class Node_Impl : public virtual dom::Node
{
private:
	std::string	name;
	std::string	value;
	short		nodeType;
	dom::Node *	parent;
	dom::NodeList	nodes;

	dom::Node *			getSibling(int direction);
protected:
	dom::Document *	document;
	WhiteSpaceStrategy*  wsStrategy;

	Node_Impl(const std::string & name, short type);
public:
	virtual ~Node_Impl();

	virtual const std::string &	getNodeName(void);
	virtual const std::string &	getNodeValue(void);
	virtual void			setNodeValue(const std::string & nodeValue);
	virtual short			getNodeType(void);
	virtual dom::Node *		getParentNode(void);
	virtual dom::NodeList *		getChildNodes(void);
	virtual dom::Node *		getFirstChild(void);
	virtual dom::Node *		getLastChild(void);
	virtual dom::Node *		getPreviousSibling(void);
	virtual dom::Node *		getNextSibling(void);
	virtual dom::Document *		getOwnerDocument(void);
	virtual dom::Node *		insertBefore(dom::Node * newChild, dom::Node * refChild);
	virtual dom::Node *		replaceChild(dom::Node * newChild, dom::Node * oldChild);
	virtual dom::Node *		removeChild(dom::Node * oldChild);
	virtual dom::Node *		appendChild(dom::Node * newChild);
	virtual bool			hasChildNodes(void);
	virtual const std::string &	getLocalName(void);
	//Methods from strategy implementation
	virtual std::string     serialize(int indentLevel=0);
	virtual void 			setWhiteSpaceStrategyRecursive(WhiteSpaceStrategy * strategy);

	virtual void setParent(dom::Node * parent);
};

#endif // NODE_H
