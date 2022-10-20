#include <exception>
using namespace std;

#ifndef __MilitaryState_h__
#define __MilitaryState_h__

#include "SimulationState.h"

// class SimulationState;
class MilitaryState;

class MilitaryState: public SimulationState
{
	private: std::time_t timestamp;

	public: MilitaryState(Military* m);

	public: virtual void simulationState();
};

#endif
