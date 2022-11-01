#include <exception>
using namespace std;

#include "PlaneFactory.h"
#include "VehicleFactory.h"
#include"Plane.h"

PlaneFactory::PlaneFactory(){

}
PlaneFactory::~PlaneFactory(){

}

Vehicle* PlaneFactory::manufactureVehicle(int planeDamage,int damageToTank,int damageToBatallion){
	return new Plane(planeDamage,damageToTank,damageToBatallion);
}

Vehicle* PlaneFactory::manufactureVehicle(){
	return new Plane();
}
		