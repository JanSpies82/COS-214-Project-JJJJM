/// @author Jake Mahloko

#ifndef __VehicleObserver_h__
#define __VehicleObserver_h__

#include "Observer.h"
#include <exception>

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
