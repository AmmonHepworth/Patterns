#include "XMLSerializer.H"
#include "WhiteSpaceStrategy.H"

#include "Document.H"
#include "Element.H"
#include "Attr.H"
#include "Text.H"

void XMLSerializer::prettyIndentation()
{
	for (int i = 0; i < indentationLevel; i++)
		file << "\t";
}

void XMLSerializer::serializePretty(dom::Node * node)
{
	node->setWhiteSpaceStrategyRecursive(new PrettySpacingStrategy());
	file << node->serialize();
	return;
}

void XMLSerializer::serializeMinimal(dom::Node * node)
{
	node->setWhiteSpaceStrategyRecursive(new MinimalSpacingStrategy());
	file << node->serialize();
	return;
}
