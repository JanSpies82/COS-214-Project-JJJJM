#include <exception>
using namespace std;

#ifndef __Ship_h__
#define __Ship_h__

#include "Vehicle.h"

// class Vehicle;
class Ship;

class Ship: public Vehicle
{

	public: void findEnemy();

	public: void destroyEnemy();
};

#endif
