#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include "Neighbour.h"

class RightNeighbour: public Neighbour
{
	public:
		/**
		 * @brief The constructor for right neighbour
		 * 
		 * @param _neighbour : Location* - Adds this location as the right neighbour of a location
		 */
		RightNeighbour(Location* _neighbour);

		 /**
		 * @brief Calls the getRight function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		bool hasRight();
};

#endif
