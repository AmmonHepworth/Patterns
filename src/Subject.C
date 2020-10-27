#include "Subject.H"
#include <algorithm>

void Subject::attach(Observer* o)
{
	_observers.push_back(o);
}
void Subject::detach(Observer* o)
{
	_observers.erase(std::find(_observers.begin(),_observers.end(), o));
}
void Subject::notify()
{
	for(auto && o: _observers)
	{
		o->update();
	}
}