#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include <exception>
#include "Neighbour.h"

// class Neighbour;
class Location;
class TopNeighbour;


class TopNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for top neighbour
		 * 
		 * @param _location : Location* - adds this location as the top neighbour of a location 
		 */
		TopNeighbour(Location* _location);

		/**
		 * @brief Set the topLocation object to the passed in _top parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the topLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

	private: 
		//StateType* addedState;
		Location* topLocation;
};

#endif
