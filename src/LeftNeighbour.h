#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include "Neighbour.h"

class LeftNeighbour: public Neighbour
{
	
	public:
		/**
		 * @brief The constructor for left neighbour.
		 * 
		 * @param _neighbour : Location* - Pointer to the left neighbour.
		 */
		LeftNeighbour(Location* _neighbour);

		/**
		 * @brief Returns left neighbour.
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Always returns true since LeftNeighbour will always have a left neighbour.
		 * 
		 * @return true 
		 */
		bool hasLeft();

};

#endif
