#include <exception>
using namespace std;

#ifndef __Territory_h__
#define __Territory_h__

// #include "LocationIterator.h"
#include "Location.h"

class LocationIterator;
// class Location;
class Territory;

class Territory: public Location
{
	public:
		LocationIterator* locationIterators;
		
		/**
		 * @brief Create a Iterator object and store it in locationIterators
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();
};

#endif
