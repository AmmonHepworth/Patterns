#include <string>
#include <fstream>
#include <ios>

#include "Node.H"

//TEMPLATE METHOD - AbstractClass
class XMLSerializer
{
protected:
	std::fstream		file;
	int			indentationLevel;


	//variant operations
	virtual void		prettyIndentation() = 0;
	virtual std::string getLineEnding() = 0;
	virtual void serializeDocument(dom::Node * node) = 0;
	virtual void serializeAttribute(dom::Node * node) = 0;
	virtual void serializeText(dom::Node * node) = 0;

public:
	XMLSerializer(const std::string & filename) : indentationLevel(0), file(filename.c_str(), std::ios_base::out)	{}
	virtual ~XMLSerializer() {}

	void serialize(dom::Node * node);
};

//TEMPLATE METHOD - ConcreteClass
class MinimalXMLSerializer: virtual public XMLSerializer
{
protected:
	virtual void		prettyIndentation();
	virtual std::string getLineEnding();
	virtual void serializeDocument(dom::Node * node);
	virtual void serializeAttribute(dom::Node * node);
	virtual void serializeText(dom::Node * node);
public:
	MinimalXMLSerializer(const std::string & filename): XMLSerializer(filename) { ; };
};

//TEMPLATE METHOD - ConcreteClass
class PrettyXMLSerializer: virtual public XMLSerializer
{
protected:
	virtual void		prettyIndentation();
	virtual std::string getLineEnding();
	virtual void serializeDocument(dom::Node * node);
	virtual void serializeAttribute(dom::Node * node);
	virtual void serializeText(dom::Node * node);

public:
	PrettyXMLSerializer(const std::string & filename): XMLSerializer(filename) {};

};