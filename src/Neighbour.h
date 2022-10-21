#include <exception>
using namespace std;

#ifndef __Neighbour_h__
#define __Neighbour_h__

#include "Location.h"

// class Location;
class Neighbour;

class Neighbour: public Location
{
	public:
		Location* locations;

		/**
		 * @brief Set the Neighbour object depending on which type of neighbour calls this function
		 * 
		 */
		virtual void setNeighbour();

		/**
		 * @brief Create an Iterator object
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator();

	private:
		Location* location;

};

#endif
