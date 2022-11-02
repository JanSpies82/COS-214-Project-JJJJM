#ifndef __MapState_h__
#define __MapState_h__

#include <ctime>
#include "Map.h"

class MapState
{
	
	public:
		/**
		 * @brief Construct a new Map State object from a passed in Map pointer. Calls copy contructor of the Map class passing in m as parameter and sets mapState equal to the result.
		 * 
		 * @param _m : Map* - Pointer to the Map object to be made into a state.
		 */
		MapState(Map* _m);

		/**
		 * @brief Destructor for the MapState class. Deletes tha map state object held by the class.
		 * 
		 */
		~MapState();

		/**
		 * @brief Return a clone of the mapState object. 
		 * 
		 * @return Map* 
		 */
		Map* clone();
		
	private: 
		Map* mapState;
		std::time_t timestamp;

};

#endif
