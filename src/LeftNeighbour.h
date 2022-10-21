#include <exception>
using namespace std;

#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class LeftNeighbour;

class LeftNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the leftLocation object to the passed in _left parameter
		 * 
		 * @param _left : Location* - parameter to set the leftLocation object to 
		 */
		void setleft(Location* _left);

	private: 
		//StateType* addedState;
		Location* leftLocation;
};

#endif
