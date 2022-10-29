#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include "Neighbour.h"

class BottomNeighbour: public Neighbour
{
	public:
		/**
		 * @brief The constructor for bottom neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the bottom neighbour of a location 
		 */
		BottomNeighbour(Location* _neighbour);

		/**
		 * @brief Returns bottom neighbour if it has a bottom neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

		bool hasBottom();
};

#endif
