#include "XMLSerializer.H"

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
	node->serialize(file,true,0);
	return;
	if (dynamic_cast<dom::Document *>(node) != 0)
	{
		file << node->getDataSerializable();
		file << "\n";
		serializePretty(dynamic_cast<dom::Document *>(node)->getDocumentElement());
	}
	else if (dynamic_cast<dom::Element *>(node) != 0)
	{
		prettyIndentation();
		file << node->getDataSerializable();

		int	attrCount	= 0;

		for (dom::NamedNodeMap::iterator i = dynamic_cast<dom::Element *>(node)->getAttributes()->begin();
		  i != dynamic_cast<dom::Element *>(node)->getAttributes()->end();
		  i++)
		{
			serializePretty(*i);
			attrCount++;
		}

		if (attrCount > 0)
			file << " ";

		if (dynamic_cast<dom::Element *>(node)->getChildNodes()->size() == 0)
		{
			file << "/>";
			file << "\n";
		}
		else
		{
			file << ">";
			file << "\n";
			indentationLevel++;

			for (dom::NodeList::iterator i = dynamic_cast<dom::Element *>(node)->getChildNodes()->begin();
			  i != dynamic_cast<dom::Element *>(node)->getChildNodes()->end();
			  i++)
				if (dynamic_cast<dom::Element *>(*i) != 0 || dynamic_cast<dom::Text *>(*i) != 0)
					serializePretty(*i);

			indentationLevel--;
			prettyIndentation();
			file << "</" << dynamic_cast<dom::Element *>(node)->getTagName() + ">";
			file << "\n";
		}
	}
	else if (dynamic_cast<dom::Attr *>(node) != 0)
	{
		file << node->getDataSerializable();
	}
	else if (dynamic_cast<dom::Text *>(node) != 0)
	{
		prettyIndentation();
		file << node->getDataSerializable();
		file << "\n";
	}
}

void XMLSerializer::serializeMinimal(dom::Node * node)
{
	node->serialize(file,false,0);
	return;
}
