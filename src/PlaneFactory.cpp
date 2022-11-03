/// @author Jake Mahloko

#include "PlaneFactory.h"
// #include "VehicleFactory.h"
#include "Plane.h"

using namespace std;

PlaneFactory::PlaneFactory(){}

PlaneFactory::~PlaneFactory(){}

// Vehicle* PlaneFactory::manufactureVehicle(int planeDamage,int damageToTank,int damageToBatallion){
// 	return new Plane(planeDamage,damageToTank,damageToBatallion);
// }

Vehicle *PlaneFactory::manufactureVehicle()
{
	return new Plane();
}

PlaneFactory *PlaneFactory::clone()
{
	return new PlaneFactory();
}