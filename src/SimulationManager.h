
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
class WarStage;
class Country;

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
	WarStage *warStage;
	std::vector<Superpower *> *superpowers;
	Backup *backup;
	bool designMode, isRunning;
	void setSuperpowers();
	void setDesignMode();
	void setUpUK(Country *_uk);
	void setUpFrance(Country *_france);
	void setUpBalkans(Country *_balkans);
	void setUpSpainPortugal(Country *_spainPortugal);
	void setUpEastEurope(Country *_eastEurope);
	void setUpScandanavia(Country *_scandanavia);
	void setUpGermany(Country *_germany);
	void setUpItaly(Country *_italy);
};

#endif
