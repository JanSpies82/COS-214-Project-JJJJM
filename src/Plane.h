#include <exception>
using namespace std;

#ifndef __Plane_h__
#define __Plane_h__

#include "Vehicle.h"

// class Vehicle;
class Plane;

class Plane: public Vehicle
{

	public: void findEnemy();

	public: void destroyEnemy();
};

#endif
