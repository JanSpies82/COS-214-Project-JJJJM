#include <exception>
using namespace std;

#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class RightNeighbour;

class RightNeighbour: public Neighbour
{
	public:
		/**
		 * @brief Set the rightLocation object to the passed in _right parameter
		 * 
		 * @param _right : Location* - parameter to set the rightLocation object to 
		 */
		void setright(Location* _right);

	private: 
		//StateType* addedState;
		Location* rightLocation;
};

#endif
