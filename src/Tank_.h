#include <exception>
using namespace std;

#ifndef __Tank__h__
#define __Tank__h__

#include "Vehicle.h"

// class Vehicle;
class Tank_;

class Tank_: public Vehicle
{

	public: void findEnemy();

	public: void destroyEnemy();
};

#endif
