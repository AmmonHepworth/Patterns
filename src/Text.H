#ifndef TEXT_H
#define TEXT_H

#include <string>

#include "Node.H"

namespace dom
{
	class Document;

	class Text : public virtual Node
	{
	public:
		virtual ~Text()	{}

		virtual const std::string &	getName(void)							= 0;
		virtual const std::string &	getData(void)							= 0;
		virtual const std::string &	getValue(void)							= 0;
		virtual void			setData(const std::string & value)				= 0;
		virtual void			setValue(const std::string & value)				= 0;
		virtual int			getLength(void)							= 0;
		virtual const std::string &	substringData(int offset, int count)				= 0;
		virtual void			appendData(const std::string & arg)				= 0;
		virtual void			insertData(int offset, const std::string & arg)			= 0;
		virtual void			deleteData(int offset, int count)				= 0;
		virtual void			replaceData(int offset, int count, const std::string & arg)	= 0;
		virtual Text *			splitText(int offset)						= 0;
	};
};

/** COMPOSITE PATTERN - Leaf
 * This pattern is a leaf participant since it should have no children
 *  and so implements those functions as do-nothing operations.
 * It also implements the Component class (Node)
 **/
class Text_Impl : public virtual dom::Text, Node_Impl
{
protected:
	Text_Impl(const std::string value, dom::Document * document);
public:
	friend class Document_Impl;

	virtual ~Text_Impl();

	virtual const std::string &	getName(void);
	virtual const std::string &	getData(void);
	virtual const std::string &	getValue(void);
	virtual void			setData(const std::string & value);
	virtual void			setValue(const std::string & value);
	virtual int			getLength(void);
	virtual const std::string &	substringData(int offset, int count);
	virtual void			appendData(const std::string & arg);
	virtual void			insertData(int offset, const std::string & arg);
	virtual void			deleteData(int offset, int count);
	virtual void			replaceData(int offset, int count, const std::string & arg);
	virtual dom::Text *		splitText(int offset);

	//COMPOSITE - Prevent leaf from adding children
	virtual dom::Node *		insertBefore(dom::Node * newChild, dom::Node * refChild);
	virtual dom::Node *		replaceChild(dom::Node * newChild, dom::Node * oldChild);
	virtual dom::Node *		removeChild(dom::Node * oldChild);
	virtual dom::Node *		appendChild(dom::Node * newChild);
};

#endif // TEXT_H
