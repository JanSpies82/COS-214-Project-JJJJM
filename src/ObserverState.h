/// @author Janco Spies

#ifndef __ObserverState_h__
#define __ObserverState_h__

class BattalionObserver;
class VehicleObserver;
class ObserverState;

// #include "CountryObserver.h"
// #include "BattalionObserver.h"
// #include "VehicleObserver.h"

class ObserverState
{
	public: BattalionObserver* battalionObservers;
	public: VehicleObserver* vehicleObservers;
};

#endif
