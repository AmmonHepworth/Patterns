#ifndef ATTR_H
#define ATTR_H

#include <string>

#include "Node.H"

namespace dom
{
	class Document;
	class Element;

	/** ABSTRACT FACTORY PATTERN - AbstractProduct 
	 */
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

/** ABSTRACT FACTORY PATTERN - Product
 */
class Attr_Impl : public virtual dom::Attr, Node_Impl
{
protected:
	Attr_Impl(const std::string & tagName, dom::Document * document);
	Attr_Impl(const std::string & tagName, const std::string & value, dom::Document * document);
public:
	friend class Document_Impl;
	friend class Element_Impl;
	friend class DOMFactory;

	virtual ~Attr_Impl();

	virtual const std::string &	getName(void);
	virtual const std::string &	getValue(void);
	virtual void			setValue(const std::string & value);
	virtual dom::Element *		getOwnerElement(void);
};

#endif // ATTR_H
