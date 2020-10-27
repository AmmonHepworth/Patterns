#ifndef SEMEDIATOR_H
#define SEMEDIATOR_H
#include "Mediator.H"
#include "Colleague.H"

//MEDIATOR PATTERN - ConcreteMediator
class StateExchangerMediator: public Mediator
{
    public:
    //exchanges updates so all mediated colleagues get them
    virtual void colleagueUpdated(Colleague *);
    virtual void addColleague(Colleague * );

};

#endif