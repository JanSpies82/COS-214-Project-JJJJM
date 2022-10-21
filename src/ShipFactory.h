#include <exception>
using namespace std;

#ifndef __ShipFactory_h__
#define __ShipFactory_h__

#include "VehicleFactory.h"



class ShipFactory: public VehicleFactory
{

	public: 
		ShipFactory();
		~ShipFactory();
		 Vehicle* manufactureVehicle();
};

#endif
