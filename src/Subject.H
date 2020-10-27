#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.H"

//OBSERVER PATTERN - Subject
class Subject
{
	protected:
	std::vector<Observer *> _observers;

    public:
    virtual ~Subject() {};
	void attach(Observer* o);
	void detach(Observer* o);
	void notify();

    protected:
    Subject() {};

};
#endif