#include <exception>
using namespace std;

#ifndef __LocationIterator_h__
#define __LocationIterator_h__

// #include "Territory.h"
// #include "Location.h"
#include "Iterator.h"

class Territory;
class Location;
// class Iterator;
class LocationIterator;

class LocationIterator: public Iterator
{
	public: Territory* territorys;
	public: Location* locations;

	public: void first();

	public: void next();

	public: void isDone();

	public: void currentItem();

	public: virtual void current();
};

#endif
