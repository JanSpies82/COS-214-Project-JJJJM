#include <exception>
using namespace std;

#ifndef __MapState_h__
#define __MapState_h__

#include "SimulationState.h"

// class SimulationState;
class MapState;

class MapState: public SimulationState
{
	private: std::time_t timestamp;

	public: MapState(Map* m);

	public: virtual void simulationState();
};

#endif
