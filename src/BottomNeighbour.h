#include <exception>
using namespace std;

#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class BottomNeighbour;

class BottomNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the bottomLocation object to the passed in _bottom parameter
		 * 
		 * @param _bottom : Location* - parameter to set the bottomLocation object to 
		 */
		void setBottom(Location* _bottom);

	private: 
		//StateType* addedState;
		Location* bottomLocation;
};

#endif
