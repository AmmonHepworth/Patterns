#include "StateExchangerMediator.H"
#include <iostream>

void StateExchangerMediator::colleagueUpdated(Colleague * updated)
{
    for(auto && c: colleagues)
    {
        std::cout << "exchanging state" << std::endl;
    }

}

void StateExchangerMediator::addColleague(Colleague * newC)
{
    colleagues.push_back(newC);
}
