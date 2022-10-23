#include <exception>
using namespace std;

#ifndef __CountryObserver_h__
#define __CountryObserver_h__

// #include "ObserverState.h"
#include "Observer.h"

class ObserverState;
class Observer;
class CountryObserver;
class Country;

class CountryObserver: public Observer
{
	private: ObserverState* state;
	private: Country* subject;
	public: ObserverState* observerStates;

	public: void update();
};

#endif
