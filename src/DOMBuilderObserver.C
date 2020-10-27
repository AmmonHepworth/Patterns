#include "DOMBuilderObserver.H"
#include <iostream>

DOMBuilderObserver::DOMBuilderObserver(DOMBuilder * builder, StateExchangerMediator* mediator):Colleague(mediator), subject(builder) {
    subject->attach(this);
    mediator->addColleague(this);
};

void DOMBuilderObserver::update() 
{
    state = subject->getState();
    std::cout << "builder has notified me of a new part built with token: ";
    printf("\t %s = '%s'\n", state->toString(), state->getToken().size() == 0 ? "" : state->getToken().c_str());
    std::cout << "Exchanging using mediator... " << std::endl;
    notifyChangedState();
}

XMLTokenizer::XMLToken * DOMBuilderObserver::getState()
{
    return state;
}

void DOMBuilderObserver::setState(XMLTokenizer::XMLToken* state)
{
    state = state;
    std::cout << "state set by mediator" << std::endl;
}

void DOMBuilderObserver::notifyChangedState()
{
    mediator->colleagueUpdated(this);
}