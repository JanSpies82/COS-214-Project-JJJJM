#include <exception>
using namespace std;

#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include "Neighbour.h"

// class Neighbour;
class TopNeighbour;

class TopNeighbour: public Neighbour
{
	private: StateType* addedState;

	public: void operation();
};

#endif
