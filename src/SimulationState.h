#include <exception>
using namespace std;

#ifndef __SimulationState_h__
#define __SimulationState_h__

// #include "SimulationManager.h"
// #include "Memento.h"

class SimulationManager;
class Memento;
class SimulationState;

__abstract class SimulationState
{
	public: SimulationManager* simulationManagers;
	public: Memento* mementos;

	public: virtual SimulationState();
};

#endif
