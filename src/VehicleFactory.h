#include <exception>
using namespace std;

#ifndef __VehicleFactory_h__
#define __VehicleFactory_h__

// #include "Military.h"

class Military;
class VehicleFactory;

__abstract class VehicleFactory
{
	private: Vehicle* vehicle;
	public: Military* militarys;

	protected: virtual Vehicle* factoryMethod() = 0;

	public: void anOperation();
};

#endif
