#include <exception>
using namespace std;

#ifndef __Neighbour_h__
#define __Neighbour_h__

#include "Location.h"

// class Location;
class Neighbour;

class Neighbour: public Location
{
	public:
		Location* locations;

		void operation();

		virtual Iterator* createIterator();

	private:
		Location* location;
		
};

#endif
