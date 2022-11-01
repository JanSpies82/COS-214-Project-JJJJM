
#ifndef __SimulationManager_h__
#define __SimulationManager_h__

// #include "Map.h"
// #include "SimulationState.h"
// #include "Superpower.h"
// #include "Backup.h"

#include <vector>

class Map;
class SimulationState;
class Superpower;
class Backup;
class SimulationManager;

class SimulationManager
{
public:
	SimulationManager();
	virtual ~SimulationManager();
	void restoreState();
	void saveState();
	void resetSimulation();
	bool isSimulationRunning();
	void takeTurn();
	void startSimulation();

private:
	Map *map;
	std::vector<Superpower *> *superpowers;
	Backup *backup;
	bool designMode, isRunning;
	void setSuperpowers();
	void setDesignMode();
};

#endif
