
#ifndef __Backup_h__
#define __Backup_h__

// #include "SimulationManager.h"
// #include "Memento.h"

class SimulationManager;
class Memento;
class Backup;

class Backup
{
	public: SimulationManager* simulationManagers;
	public: Memento* mementos;
};

#endif
