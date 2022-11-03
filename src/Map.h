/// @author Julian Pienaar

#ifndef __Map_h__
#define __Map_h__

class Location;
class Territory;
class MapState;

#include "Territory.h"

class Map
{

	public:
		/**
		 * @brief Construct a new Map object initializing all locations in the Map.
		 * 
		 */
		Map();

		/**
		 * @brief Construct a new Map object and set topLeft to _cloneTopLeft.
		 * 
		 * @param _cloneTopLeft 
		 */
		Map(Location* _cloneTopLeft);

		/**
		 * @brief Call delete on each location in the Map using an iterator.
		 * 
		 */
		~Map();

		/**
		 * @brief Construct a copy of the passed in map pointer.
		 * 
		 * @param map : Map* - the pointer to be copied into the new map.
		 */
		Map(Map* _oldMap);

		/**
		 * @brief Get the Location object with matching x and y coordinates.
		 * 
		 * Exceptions : std::__throw_out_of_range if _x>24 or _x<0 or _y>26 or _y<0.
		 * 
		 * @param _x : int - The x coordinate of the location to be returned.
		 * @param _y : int - The y coordinate of the location to be returned.
		 * 
		 * @return Location* 
		 */
		Location* getLocation(int _x, int _y);

		/**
		 * @brief Get the topLeft location.
		 * 
		 * @return Location* 
		 */
		Location* getTopLeft();

		/**
		 * @brief Prints to console a representation of the map. Each location will have a colour representing a country that owns said location.
		 * 
		 */
		void printMap();

		/**
		 * @brief Get the State object of the Map.
		 * 
		 * @return MapState* 
		 */
		MapState* getState();

	private:
		void printLocation(std::string _col);
		Location* topLeft;

};

#endif
