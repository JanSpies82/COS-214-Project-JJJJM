#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include "Neighbour.h"

class TopNeighbour: public Neighbour
{
	public:
	
		/**
		 * @brief The constructor for top neighbour.
		 * 
		 * @param _neighbour : Location* - Pointer to top neighbour.
		 */
		TopNeighbour(Location* _neighbour);

		/**
		 * @brief Returns top neighbour.
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Always returns true since TopNeighbour will always have a top neighbour.
		 * 
		 * @return true 
		 */
		bool hasTop();
};

#endif
