/// @author Jake Mahloko

#include "Ship.h"
#include "ShipFactory.h"

using namespace std;

ShipFactory::ShipFactory(){}

ShipFactory::~ShipFactory(){}

Vehicle *ShipFactory::manufactureVehicle()
{
	return new Ship();
}

ShipFactory *ShipFactory::clone()
{
	return new ShipFactory();
}
