#include <exception>
using namespace std;

#ifndef __Observer_h__
#define __Observer_h__

// #include "Location.h"

class Location;
class Observer;

class Observer
{
	public: Location* locations;

	public: virtual void update() = 0;
};

#endif
