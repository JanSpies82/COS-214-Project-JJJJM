#ifndef __MapState_h__
#define __MapState_h__

#include <exception>
#include <ctime>
#include "Map.h"

// class SimulationState;
class MapState;

class MapState
{
	public:
		/**
		 * @brief Construct a new Map State object from a passed in Map pointer. Makes a deep copy of every location in a Map
		 * 
		 * @param m : Map* - Pointer to the Map object.
		 */
		MapState(Map* m);

		
	private: 
		std::time_t timestamp;

};

#endif
