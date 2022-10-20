#include <exception>
using namespace std;

#ifndef __PlaneFactory_h__
#define __PlaneFactory_h__

#include "VehicleFactory.h"

// class VehicleFactory;
class PlaneFactory;

class PlaneFactory: public VehicleFactory
{

	protected: virtual Vehicle* factoryMethod();
};

#endif
