#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include "Neighbour.h"

class LeftNeighbour: public Neighbour
{
	public:
		/**
		 * @brief The constructor for left neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the left neighbour of a location 
		 */
		LeftNeighbour(Location* _neighbour);

		/**
		 * @brief Returns left neighbour if it has a left neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		bool hasLeft();
};

#endif
