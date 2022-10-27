#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include <exception>
#include "Neighbour.h"

// class Neighbour;
class Location;
class RightNeighbour;

class RightNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for right neighbour
		 * 
		 * @param _location : Location* - adds this location as the right neighbour of a location 
		 */
		RightNeighbour(Location* _location);

		/**
		 * @brief Set the rightLocation object to the passed in _right parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the rightLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

	private: 
		//StateType* addedState;
		Location* rightLocation;
};

#endif
