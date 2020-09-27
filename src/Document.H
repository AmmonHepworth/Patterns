#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <fstream>

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

/** STRATEGY PATTERN
 * This is a ConcreteStrategy, as it implements its own strategy for getDataSerializable()
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
	virtual std::string getDataSerializable(void);
	virtual void serialize(std::fstream&, bool, int);
};

#endif // DOCUMENT_H
