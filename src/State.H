#ifndef STATE_H
#define STATE_H

#include "XMLTokenizer.H"
#include "Node.H"
#include "Document.H"

class DOMBuilder;
class XMLTokenizer;

//STATE PATTERN - State
class State
{
    protected:
    DOMBuilder * context;

    public:
    virtual dom::Document * buildDocument() = 0;
    virtual dom::Node * buildElement(std::string token, dom::Document * d) = 0;
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d) = 0;
    virtual dom::Node * buildText(std::string token, dom::Document * d) = 0;

};

//STATE PATTERN - ConcreteState
class UncreatedState: public State
{
    virtual dom::Document * buildDocument();
    virtual dom::Node * buildElement(std::string token, dom::Document * d);
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d);
    virtual dom::Node * buildText(std::string token, dom::Document * d);
};

//STATE PATTERN - ConcreteState
class InsideDocumentState: public State
{
    virtual dom::Document * buildDocument();
    virtual dom::Node * buildElement(std::string token, dom::Document * d);
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d);
    virtual dom::Node * buildText(std::string token, dom::Document * d);
};

//STATE PATTERN - ConcreteState
class InsideElementState: public State
{
    virtual dom::Document * buildDocument();
    virtual dom::Node * buildElement(std::string token, dom::Document * d);
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d);
    virtual dom::Node * buildText(std::string token, dom::Document * d);
};

//STATE PATTERN - ConcreteState
class InsideAttributeState: public State
{
    virtual dom::Document * buildDocument();
    virtual dom::Node * buildElement(std::string token, dom::Document * d);
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d);
    virtual dom::Node * buildText(std::string token, dom::Document * d);
};

//STATE PATTERN - ConcreteState
class InsideTextState: public State
{
    virtual dom::Document * buildDocument();
    virtual dom::Node * buildElement(std::string token, dom::Document * d);
    virtual dom::Node * buildAttribute(std::string token, dom::Document * d);
    virtual dom::Node * buildText(std::string token, dom::Document * d);
};

#endif