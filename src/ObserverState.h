
#ifndef __ObserverState_h__
#define __ObserverState_h__

// #include "CountryObserver.h"
// #include "BattalionObserver.h"
// #include "VehicleObserver.h"
class BattalionObserver;
class VehicleObserver;
class ObserverState;

class ObserverState
{
	public: BattalionObserver* battalionObservers;
	public: VehicleObserver* vehicleObservers;
};

#endif
