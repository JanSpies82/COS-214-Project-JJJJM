/// @author Jake Mahloko

#include "Ship.h"
#include "ShipFactory.h"
// #include "VehicleFactory.h"

using namespace std;

ShipFactory::ShipFactory(){}

ShipFactory::~ShipFactory(){}

// 		Vehicle* ShipFactory::manufactureVehicle(int damageBatallion,int damageToShip){
// 			return new Ship(damageBatallion,damageToShip);
// 		}

Vehicle *ShipFactory::manufactureVehicle()
{
	return new Ship();
}

ShipFactory *ShipFactory::clone()
{
	return new ShipFactory();
}
