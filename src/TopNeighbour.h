#include <exception>
using namespace std;

#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class Location;
class TopNeighbour;


class TopNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the topLocation object to the passed in _top parameter
		 * 
		 * @param _top : Location* - parameter to set the topLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

	private: 
		//StateType* addedState;
		Location* topLocation;
};

#endif
