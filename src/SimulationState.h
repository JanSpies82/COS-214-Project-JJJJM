#include <exception>
using namespace std;

#ifndef __SimulationState_h__
#define __SimulationState_h__

// #include "SimulationManager.h"
// #include "Memento.h"

class SimulationManager;
class Memento;
class SimulationState;

class SimulationState
{
public:
	SimulationState();
	virtual ~SimulationState();
};

#endif
