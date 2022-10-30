#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include "Neighbour.h"

class RightNeighbour: public Neighbour
{
	public:
	
		/**
		 * @brief The constructor for right neighbour.
		 * 
		 * @param _neighbour : Location* - Pointer to the right neighbour.
		 */
		RightNeighbour(Location* _neighbour);

		 /**
		 * @brief Returns right neighbour.
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief Always returns true since RightNeighbour will always have a right neighbour.
		 * 
		 * @return true 
		 */
		bool hasRight();
};

#endif
