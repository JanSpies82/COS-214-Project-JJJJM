#include <exception>
using namespace std;

#ifndef __Map_h__
#define __Map_h__

// #include "Location.h"
// #include "SimulationManager.h"
#include "Territory.h"

class Location;
class SimulationManager;
class Territory;
class Map;

class Map
{
	public: Location* locations;
	public: SimulationManager* simulationManagers;

	public: Territory getLocation(int x, int y);
};

#endif
