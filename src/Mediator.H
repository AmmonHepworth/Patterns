#ifndef MEDIATOR_H
#define MEDIATOR_H
class Colleague;
#include <vector>

//MEDIATOR PATTERN - Mediator
class Mediator
{
    protected:
    std::vector<Colleague *> colleagues;
    public:
    //exchanges updates so all mediated colleagues get them
    virtual void colleagueUpdated(Colleague *) = 0;
    virtual void addColleague(Colleague * ) = 0;

};
#endif