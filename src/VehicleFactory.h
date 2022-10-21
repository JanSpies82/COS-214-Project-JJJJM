#include <exception>
using namespace std;

#ifndef __VehicleFactory_h__
#define __VehicleFactory_h__
#include"Vehicle.h"
 class VehicleFactory
{
	public:
		VehicleFactory();
		~VehicleFactory();
		virtual Vehicle* manufactureVehicle() = 0;

		
		
};

#endif
