#include "XMLTokenizer.H"
#include "Node.H"
#include "Document.H"
#include "Element.H"
#include "Text.H"
#include "Attr.H"
#include <iostream>
#include <stack>

DOMBuilder::DOMBuilder(DOMFactory * factory): domFactory(factory), document(0), curNode(0)
{

}

dom::Document * DOMBuilder::buildDocument()
{
    document = domFactory->createDocument();
    return document;
}

dom::Node * DOMBuilder::buildElement(XMLTokenizer::XMLToken* token)
{
    return domFactory->createElement(token->getToken(), document);
}

dom::Node * DOMBuilder::buildAttribute(XMLTokenizer::XMLToken* token)
{
    return domFactory->createAttribute(token->getToken(), document);
}

dom::Node * DOMBuilder::buildText(XMLTokenizer::XMLToken* token)
{
    return domFactory->createText(token->getToken(), document);
}

dom::Node * DOMBuilder::addChild(dom::Node * root, XMLTokenizer::XMLToken * token)
{
    if(token->toString() == "ATTRIBUTE")
        dynamic_cast<dom::Element *>(root)->setAttributeNode(domFactory->createAttribute(token->getToken(), document));
    else if(token->toString() == "ELEMENT")
        dynamic_cast<dom::Element *>(root)->appendChild(domFactory->createElement(token->getToken(), document));
    else if(token->toString() == "VALUE")
        dynamic_cast<dom::Element *>(root)->appendChild(domFactory->createText(token->getToken(), document));

    return 0;
    

}

dom::Node * DOMBuilder::getResult()
{
    return document;
}


void DOMBuilder::buildToken(XMLTokenizer::XMLToken* token)
{
    switch(token->getTokenType())
    {
        case XMLTokenizer::XMLToken::PROLOG_END:
            document = buildDocument();
            std::cout << "Building doc" << std::endl;
            break;
        case XMLTokenizer::XMLToken::ELEMENT:
            curNode = buildElement(token);
            std::cout << "adding new element" << std::endl;
            break;
        case XMLTokenizer::XMLToken::ATTRIBUTE_VALUE:
            if(document) //prevent prologue attributes from being added
            {
                addChild(stack.top(), token);
                std::cout << "adding new attr to top of stack" << std::endl;
            }
            break;
        case XMLTokenizer::XMLToken::TAG_CLOSE_START:
            //pop off of stack, multiline tag closing
            stack.pop();
            std::cout << "popping last element off stack" << std::endl;
            break;
        case XMLTokenizer::XMLToken::VALUE: //add text
            addChild(stack.top(), token);
            std::cout << "adding text to top element on stack" << std::endl;
            break;
        case XMLTokenizer::XMLToken::TAG_END:
            //push one onto stack, multiline tag opening (if not multiline, uses null_tag_end)
            stack.push(curNode);
            std::cout << "pushing new element to stack of size " << stack.size() << std::endl;
            break;
    }
}