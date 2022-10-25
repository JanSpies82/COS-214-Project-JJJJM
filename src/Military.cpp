#include <vector>
using namespace std;

#include "Military.h"
#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
#include "Country.h"
#include "VehicleFactory.h"
#include "Vehicle.h"

<<<<<<< HEAD

Military::Military(){

}

Military::~Military(){

}

void Military:: addBattalions(Citizen *_citizen){
	battalions->insert(new Battalion());
	delete _citizen;
}

int Military::getNumBattalions(){
	return battalions->size();
}

int Military::getNumTanks(){
	return tanks->size();
}

int Military::getNumPlanes(){
	return planes->size();
}

int Military::getNumShips(){
	return ships->size();
}

int Military::getNumVehicles(){
	return getNumShips()+getNumPlanes()+getNumTanks();
}

void Military::attack(Country* enemy){

}
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
