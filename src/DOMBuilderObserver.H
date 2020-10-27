#include "Observer.H"
#include <iostream>
#include "XMLTokenizer.H"
#include "StateExchangerMediator.H"
#include "Colleague.H"

//OBSERVER PATTERN - ConcreteObserver
//MEDIATOR PATTERN - ConcreteColleague
class DOMBuilderObserver: public Observer, public Colleague
{
    private:
    DOMBuilder * subject;
    XMLTokenizer::XMLToken * state;
    public:
    DOMBuilderObserver(DOMBuilder* b, StateExchangerMediator* m);
    virtual void update();
    XMLTokenizer::XMLToken * getState();
    void setState(XMLTokenizer::XMLToken* s);
    virtual void notifyChangedState();

};
