#include <exception>
using namespace std;

#ifndef __Location_h__
#define __Location_h__

#include "Map.h"
#include "LocationIterator.h"
#include "Observer.h"
#include "Neighbour.h"

class Map;
class LocationIterator;
class Observer;
// class Neighbour;
class Location;

class Location
{
	public: 
		Map* maps;
		LocationIterator* locationIterators;
		Observer* observers;
		Neighbour* neighbours;
		int xCoordinate, yCoordinate;


		/**
		 * @brief Abstract function which specifies that all inheriting classes should have a createIterator() function.
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator() = 0;
	
	protected:
		const int RIGHT=0,LEFT=1,UP=2,DOWN=3;
};

#endif
