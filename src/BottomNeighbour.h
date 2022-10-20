#include <exception>
using namespace std;

#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class BottomNeighbour;

class BottomNeighbour: public Neighbour
{
	private: StateType* addedState;

	public: void operation();
};

#endif
