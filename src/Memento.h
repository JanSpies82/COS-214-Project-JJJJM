
#ifndef __Memento_h__
#define __Memento_h__

// #include "Backup.h"
// #include "SimulationState.h"

class Backup;
class SimulationState;
class Memento;

class Memento
{
	private: SimulationState* state;
	public: Backup* backups;
	public: SimulationState* simulationStates;

	public: SimulationState* getState();

	public: void setState(SimulationState* s);
};

#endif
