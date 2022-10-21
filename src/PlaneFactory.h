#include <exception>
using namespace std;

#ifndef __PlaneFactory_h__
#define __PlaneFactory_h__

#include "VehicleFactory.h"


class PlaneFactory: public VehicleFactory
{

	public: 
		PlaneFactory();
		~PlaneFactory();
		 Vehicle* manufactureVehicle();
};

#endif
