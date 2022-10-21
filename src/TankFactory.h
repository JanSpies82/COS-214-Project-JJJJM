#include <exception>
using namespace std;

#ifndef __TankFactory_h__
#define __TankFactory_h__

#include "VehicleFactory.h"

class TankFactory: public VehicleFactory
{

	public: 
		TankFactory();
		~TankFactory();
		Vehicle* manufactureVehicle();
};

#endif
