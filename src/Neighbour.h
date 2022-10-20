#include <exception>
using namespace std;

#ifndef __Neighbour_h__
#define __Neighbour_h__

#include "Location.h"

// class Location;
class Neighbour;

class Neighbour: public Location
{
	private: Location* location;
	public: Location* locations;

	public: void operation();

	public: virtual Iterator* createIterator();
};

#endif
