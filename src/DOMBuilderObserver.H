#include "Observer.H"
#include <iostream>
#include "XMLTokenizer.H"

//OBSERVER PATTERN - ConcreteObserver
class DOMBuilderObserver: public Observer
{
    private:
    DOMBuilder * subject;
    public:
    DOMBuilderObserver(DOMBuilder* b);
    virtual void update();

};
