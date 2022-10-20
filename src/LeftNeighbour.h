#include <exception>
using namespace std;

#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class LeftNeighbour;

class LeftNeighbour: public Neighbour
{
	private: StateType* addedState;

	public: void operation();
};

#endif
