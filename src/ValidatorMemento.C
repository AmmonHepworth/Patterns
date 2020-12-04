#include "ValidatorMemento.H"
#include <vector>

std::vector<ValidChildren * > ValidatorMemento::getState()
{
    return state;
} 

void ValidatorMemento::setState(std::vector<ValidChildren *> s)
{
    state = s;
}