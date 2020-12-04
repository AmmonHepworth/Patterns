#ifndef VALIDATOR_MEMENTO_H
#define VALIDATOR_MEMENTO_H

#include <vector>
#include "XMLValidator.H"

class ValidChildren;
class ValidatorMemento
{
    public:
    virtual ~ValidatorMemento() {};

    private:
    friend class XMLValidator;

    std::vector<ValidChildren* > state;
    std::vector<ValidChildren* > getState();
    void setState(std::vector<ValidChildren*>);

};
#endif