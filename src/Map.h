#ifndef __Map_h__
#define __Map_h__

#include <exception>
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
		 * Exceptions : If x/y coordinate is greater than map size or less than 0
		 * 
		 * @param x : int - The x coordinate of the location to be returned
		 * @param y : int - The y coordinate of the location to be returned
		 * @return Location* 
		 */
		Location* getLocation(int x, int y);

	private:
		Location* topLeft;
};

#endif
