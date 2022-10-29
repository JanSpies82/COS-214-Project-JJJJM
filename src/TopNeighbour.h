#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include "Neighbour.h"

class TopNeighbour: public Neighbour
{
	public:
		/**
		 * @brief The constructor for top neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the top neighbour of a location 
		 */
		TopNeighbour(Location* _neighbour);

		/**
		 * @brief Returns top neighbour if it has a top neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		bool hasTop();
};

#endif
