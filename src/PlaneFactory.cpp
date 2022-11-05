/// @author Jake Mahloko

#include "PlaneFactory.h"
#include "Plane.h"

using namespace std;

PlaneFactory::PlaneFactory(){}

PlaneFactory::~PlaneFactory(){}

Vehicle *PlaneFactory::manufactureVehicle()
{
	return new Plane();
}

PlaneFactory *PlaneFactory::clone()
{
	return new PlaneFactory();
}