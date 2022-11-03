// #include <exception>
using namespace std;

#include "Tank.h"
#include "TankFactory.h"
// #include "VehicleFactory.h"

TankFactory::TankFactory()
{
}

TankFactory::~TankFactory()
{
}
// 		Vehicle* TankFactory::manufactureVehicle(int damageBatallion,int damageToTank){

// 			return new Tank(damageBatallion,damageToTank);
// 		}

Vehicle *TankFactory::manufactureVehicle()
{
	return new Tank();
}

TankFactory *TankFactory::clone()
{
	return new TankFactory();
}
