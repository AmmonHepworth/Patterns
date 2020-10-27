#include "DOMBuilderObserver.H"
#include <iostream>

DOMBuilderObserver::DOMBuilderObserver(DOMBuilder * builder): subject(builder) {
    subject->attach(this);
};

void DOMBuilderObserver::update() 
{
    XMLTokenizer::XMLToken * token = subject->getState();
    std::cout << "builder has notified me of a new part built with token: ";
    printf("\t %s = '%s'\n", token->toString(), token->getToken().size() == 0 ? "" : token->getToken().c_str());
}