#include <exception>
using namespace std;

#ifndef __Location_h__
#define __Location_h__

// #include "Map.h"
// #include "LocationIterator.h"
// #include "Observer.h"
// #include "Neighbour.h"

class Map;
class LocationIterator;
class Observer;
// class Neighbour;
class Location;

__abstract class Location
{
	public: Map* maps;
	public: LocationIterator* locationIterators;
	public: Observer* observers;
	public: Neighbour* neighbours;

	public: virtual Iterator* createIterator() = 0;
};

#endif
