#include <exception>
using namespace std;

#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class RightNeighbour;

class RightNeighbour: public Neighbour
{
	private: StateType* addedState;

	public: void operation();
};

#endif
