
#ifndef __SimulationManager_h__
#define __SimulationManager_h__

// #include "Map.h"
// #include "SimulationState.h"
// #include "Superpower.h"
// #include "Backup.h"

class Map;
class SimulationState;
class Superpower;
class Backup;
class SimulationManager;

class SimulationManager
{
	public: Map* maps;
	public: SimulationState* simulationStates;
	public: Superpower* superpowers;
	public: Backup* backups;
};

#endif
