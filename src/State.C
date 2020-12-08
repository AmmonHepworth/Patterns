#include "State.H"
#include <iostream>
#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"


dom::Document * UncreatedState::buildDocument()
{
    dom::Document* document = context->domFactory->createDocument();
    context->setDocument(document);
    context->setState(new InsideDocumentState());
    return document;

}

dom::Node * UncreatedState::buildElement(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * UncreatedState::buildAttribute(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}
dom::Node * UncreatedState::buildText(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}

dom::Document * InsideDocumentState::buildDocument()
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}
dom::Node * InsideDocumentState::buildElement(std::string token, dom::Document * document)
{
    context->setState(new InsideElementState());
    return context->domFactory->createElement(token, document);

    
}
dom::Node * InsideDocumentState::buildAttribute(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}
dom::Node * InsideDocumentState::buildText(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}

dom::Document * InsideElementState::buildDocument()
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
    
}
dom::Node * InsideElementState::buildElement(std::string token, dom::Document * document)
{
    return context->domFactory->createElement(token, document);
}
dom::Node * InsideElementState::buildAttribute(std::string token, dom::Document * document)
{
    return context->domFactory->createAttribute(token, document);
}
dom::Node * InsideElementState::buildText(std::string token, dom::Document * document)
{
    return context->domFactory->createText(token, document);
}

dom::Document * InsideAttributeState::buildDocument()
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideAttributeState::buildElement(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideAttributeState::buildAttribute(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideAttributeState::buildText(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}

dom::Document * InsideTextState::buildDocument()
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideTextState::buildElement(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideTextState::buildAttribute(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}
dom::Node * InsideTextState::buildText(std::string token, dom::Document * document)
{
    std::cout << "That action is invalid in this state" << std::endl;
    exit(10);
}