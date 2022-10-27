#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include <exception>
#include "Neighbour.h"

class Location;
// class Neighbour;
class BottomNeighbour;

class BottomNeighbour: public Neighbour
{
	public:
		/**
		 * @brief The constructor for bottom neighbour
		 * 
		 * @param _location : Location* - adds this location as the bottom neighbour of a location 
		 */
		BottomNeighbour(Location* _location);

		/**
		 * @brief Set the bottomLocation object to the passed in _bottom parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the bottomLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

	private: 
		//StateType* addedState;
		Location* bottomLocation;
};

#endif
