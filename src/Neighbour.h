#ifndef __Neighbour_h__
#define __Neighbour_h__

#include <exception>
#include "Location.h"

// class Location;
// class Neighbour;
class Iterator;

class Neighbour: public Location
{
	public:

		/**
		 * @brief Constructor for Neighbour class
		 * 
		 * @param _location : Location* - Pointer to the added neighbour location.
		 */
		Neighbour(Location* _location);

		/**
		 * @brief Create an Iterator object
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator();

	private:
		Location* neighbour;

};

#endif
