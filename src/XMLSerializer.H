#include <string>
#include <fstream>
#include <ios>
#include <iostream>

#include "Node.H"


/** STRATEGY PATTERN - Context
 * This class serves as a context to the serialization strategies that the nodes employ
 * Each of the nodes knows how to best serialize itself and its children, so the 
 * serializer will leave that work up to them.
 **/
class XMLSerializer
{
private:
	std::fstream		file;
	int			indentationLevel;

	virtual void		prettyIndentation();
public:
	XMLSerializer(const std::string & filename) : indentationLevel(0), file(filename.c_str(), std::ios_base::out)	{}
	~XMLSerializer() {}

	virtual void		serializePretty(dom::Node * node);
	virtual void		serializeMinimal(dom::Node * node);
};
