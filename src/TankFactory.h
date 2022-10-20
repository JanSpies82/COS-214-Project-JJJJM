#include <exception>
using namespace std;

#ifndef __TankFactory_h__
#define __TankFactory_h__

#include "VehicleFactory.h"

// class VehicleFactory;
class TankFactory;

class TankFactory: public VehicleFactory
{

	public: Vehicle* factoryMethod();
};

#endif
