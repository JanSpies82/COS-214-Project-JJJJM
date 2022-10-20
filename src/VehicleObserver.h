#include <exception>
using namespace std;

#ifndef __VehicleObserver_h__
#define __VehicleObserver_h__

// #include "ObserverState.h"
#include "Observer.h"

class ObserverState;
// class Observer;
class VehicleObserver;

class VehicleObserver: public Observer
{
	public: ObserverState* observerStates;

	public: virtual void update();
};

#endif
