#include <exception>
using namespace std;

#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class Location;
class LeftNeighbour;

class LeftNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the leftLocation object to the passed in _left parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the leftLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

	private: 
		//StateType* addedState;
		Location* leftLocation;
};

#endif
