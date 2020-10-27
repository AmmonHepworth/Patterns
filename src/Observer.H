#ifndef OBSERVER_H
#define OBSERVER_H

//OBSERVER PATTERN - Observer
class Observer
{
    
    public:
    virtual ~Observer() {};
    virtual void update() = 0;
    protected:
    Observer() {};

};

#endif
