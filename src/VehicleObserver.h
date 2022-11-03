/// @author Jake Mahloko

#include <exception>

#ifndef __VehicleObserver_h__
#define __VehicleObserver_h__

// #include "ObserverState.h"
#include "Observer.h"
class ObserverState;

class VehicleObserver: public Observer
{
	public: 
		/**
		 * @notify observer of the changes
		**/
		virtual void update();
	private:
	 	ObserverState* observerStates;

	
};

#endif
