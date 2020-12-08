#ifndef VISITOR_H
#define VISITOR_H

#include <string>

namespace dom
{
    class Node;
    class Document;
    class Element;
    class Attr;
    class Text;
}

//VISITOR PATTERN - Visitor
class Visitor
{
    public:
    virtual std::string visitNode(dom::Node*) = 0;
    virtual std::string visitDocument(dom::Document*) = 0;
    virtual std::string visitElement(dom::Element*) = 0;
    virtual std::string visitAttr(dom::Attr*) = 0;
    virtual std::string visitText(dom::Text*) = 0;
};

//VISITOR PATTERN - ConcreteVisitor
class SerializeVisitor: public Visitor
{
    public:
    int indentationLevel = 0;
    virtual std::string visitNode(dom::Node*);
    virtual std::string visitDocument(dom::Document*);
    virtual std::string visitElement(dom::Element*);
    virtual std::string visitAttr(dom::Attr*);
    virtual std::string visitText(dom::Text*);

};
#endif