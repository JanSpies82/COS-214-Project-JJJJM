#include <exception>
using namespace std;

#include "PlaneFactory.h"
#include "VehicleFactory.h"
#include"Plane.h"

PlaneFactory::PlaneFactory(){

}
PlaneFactory::~PlaneFactory(){

}

Vehicle* PlaneFactory::manufactureVehicle(int planeDamage,int damageToTank,int damageToBattalion){
	return new Plane(planeDamage,damageToTank,damageToBattalion);
}

Vehicle* PlaneFactory::manufactureVehicle(){
	return new Plane();
}
		