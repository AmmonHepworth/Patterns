#include "Command.H"
#include "XMLSerializer.H"

SerializePrettyCommand::SerializePrettyCommand(dom::Document* doc):document(doc) {}
SerializeMinimalCommand::SerializeMinimalCommand(dom::Document* doc):document(doc) {}

void SerializePrettyCommand::execute()
{
	XMLSerializer xmlSerializer("pretty.xml");
	xmlSerializer.serializePretty(document);
    
}

void SerializeMinimalCommand::execute()
{
	XMLSerializer xmlSerializer("minimal.xml");
	xmlSerializer.serializeMinimal(document);
    
}