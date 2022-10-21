#include <exception>
using namespace std;

#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class TopNeighbour;

class TopNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the topLocation object to the passed in _top parameter
		 * 
		 * @param _top : Location* - parameter to set the topLocation object to 
		 */
		void settop(Location* _top);

	private: 
		//StateType* addedState;
		Location* topLocation;
};

#endif
