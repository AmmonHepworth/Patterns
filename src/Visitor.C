#include "Visitor.H"
#include "Node.H"
#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"

std::string SerializeVisitor::visitNode(dom::Node* n)
{
    return n->serialize(indentationLevel);
}

std::string SerializeVisitor::visitDocument(dom::Document* n)
{
    return n->serialize(indentationLevel);
}

std::string SerializeVisitor::visitElement(dom::Element* n)
{
    return n->serialize(indentationLevel);
}

std::string SerializeVisitor::visitAttr(dom::Attr* n)
{
    return n->serialize(indentationLevel);
}

std::string SerializeVisitor::visitText(dom::Text* n)
{
    return n->serialize(indentationLevel);
}