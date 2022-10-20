
#ifndef __Memento_h__
#define __Memento_h__

// #include "Backup.h"
// #include "SimulationState.h"

class Backup;
class SimulationState;
class Memento;

class Memento
{
public:
	Memento();
	~Memento();
	SimulationState *getState();
	void setState(SimulationState *_simulationState);

private:
	SimulationState *state;
};

#endif
