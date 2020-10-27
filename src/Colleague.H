#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Mediator.H"
class Mediator;

//MEDIATOR PATTERN - Colleague
class Colleague
{
    protected:
    Mediator * mediator;

    public:
    Colleague(Mediator* m): mediator(m) {};

    virtual void notifyChangedState() = 0;


};

#endif 