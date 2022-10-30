#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include "Neighbour.h"

class BottomNeighbour: public Neighbour
{
	public:
	
		/**
		 * @brief The constructor for bottom neighbour.
		 * 
		 * @param _neighbour : Location* - Pointer to the bottom neighbour. 
		 */
		BottomNeighbour(Location* _neighbour);

		/**
		 * @brief Returns bottom neighbour.
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

		/**
		 * @brief Always returns true since BottomNeighbour will always have a bottom neighbour.
		 * 
		 * @return true 
		 */
		bool hasBottom();
};

#endif
