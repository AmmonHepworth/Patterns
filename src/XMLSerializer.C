#include "XMLSerializer.H"

#include "Document.H"
#include "Element.H"
#include "Attr.H"
#include "Text.H"

void XMLSerializer::serialize(dom::Node * node)
{
	if (dynamic_cast<dom::Document *>(node) != 0)
	{
		serializeDocument(node); 
		file << getLineEnding();
		serialize(dynamic_cast<dom::Document *>(node)->getDocumentElement());
	}
	else if (dynamic_cast<dom::Element *>(node) != 0)
	{

		prettyIndentation();
		file << "<" << dynamic_cast<dom::Element *>(node)->getTagName();

		int	attrCount	= 0;

		for (dom::NamedNodeMap::iterator i = dynamic_cast<dom::Element *>(node)->getAttributes()->begin();
		  i != dynamic_cast<dom::Element *>(node)->getAttributes()->end();
		  i++)
		{
			serialize(*i);
			attrCount++;
		}

		if (attrCount > 0)
			file << " ";

		if (dynamic_cast<dom::Element *>(node)->getChildNodes()->size() == 0)
		{
			file << "/>";
			file << getLineEnding();
		}
		else
		{
			file << ">";
			file << getLineEnding();
			indentationLevel++;

			for (dom::NodeList::iterator i = dynamic_cast<dom::Element *>(node)->getChildNodes()->begin();
			  i != dynamic_cast<dom::Element *>(node)->getChildNodes()->end();
			  i++)
				if (dynamic_cast<dom::Element *>(*i) != 0 || dynamic_cast<dom::Text *>(*i) != 0)
					serialize(*i);

			indentationLevel--;
			prettyIndentation();
			file << "</" << dynamic_cast<dom::Element *>(node)->getTagName() + ">";
			file << getLineEnding();
		}
	}
	else if (dynamic_cast<dom::Attr *>(node) != 0)
	{
		  serializeAttribute(node);
	}
	else if (dynamic_cast<dom::Text *>(node) != 0)
	{
		prettyIndentation();
		serializeText(node);
		file << getLineEnding();
	}
}

void PrettyXMLSerializer::serializeDocument(dom::Node * node)
{
	file << "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
}

void PrettyXMLSerializer::serializeAttribute(dom::Node * node)
{
	file << " " << dynamic_cast<dom::Attr *>(node)->getName() << "=\"" << dynamic_cast<dom::Attr *>(node)->getValue() << "\"";
}
void PrettyXMLSerializer::serializeText(dom::Node * node)
{
	file << dynamic_cast<dom::Text *>(node)->getData();
}

void MinimalXMLSerializer::serializeDocument(dom::Node * node)
{
	file << "<? xml version=\"1.0\" encoding=\"UTF-8\"?>";
}

void MinimalXMLSerializer::serializeAttribute(dom::Node * node)
{
	file << " " << dynamic_cast<dom::Attr *>(node)->getName() << "=\"" << dynamic_cast<dom::Attr *>(node)->getValue() << "\"";
}
void MinimalXMLSerializer::serializeText(dom::Node * node)
{
	file << dynamic_cast<dom::Text *>(node)->getData();
}


void PrettyXMLSerializer::prettyIndentation()
{
	for (int i = 0; i < indentationLevel; i++)
		file << "\t";
}

void MinimalXMLSerializer::prettyIndentation()
{
	return;
}

std::string PrettyXMLSerializer::getLineEnding()
{
	return "\n";
}

std::string MinimalXMLSerializer::getLineEnding()
{
	return "";
}