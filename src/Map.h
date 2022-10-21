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
	public:
		Location* locations;
		SimulationManager* simulationManagers;

		/**
		 * @brief Construct a new Map object with all locations initialized
		 * 
		 */
		Map();

		/**
		 * @brief Destroy the Map object by deallocating all the location objects
		 * 
		 */
		~Map();

		/**
		 * @brief Construct a copy of the passed in map pointer
		 * 
		 * @param map : Map* - the pointer to be copied into the new map
		 */
		Map(Map* map);

		/**
		 * @brief Get the Location object with matching x and y coordinates
		 * 
		 * @param x : int - The x coordinate of the location to be returned
		 * @param y : int - The y coordinate of the location to be returned
		 * @return Territory* 
		 */
		Territory* getLocation(int x, int y);
};

#endif
