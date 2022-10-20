#include <exception>
using namespace std;

#ifndef __ShipFactory_h__
#define __ShipFactory_h__

#include "VehicleFactory.h"

// class VehicleFactory;
class ShipFactory;

class ShipFactory: public VehicleFactory
{

	public: Vehicle* factoryMethod();
};

#endif
