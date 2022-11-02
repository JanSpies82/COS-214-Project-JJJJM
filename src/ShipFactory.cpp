// #include <exception>
using namespace std;
#include"Ship.h"
#include "ShipFactory.h"
// #include "VehicleFactory.h"

		ShipFactory::ShipFactory(){

		}

		ShipFactory::~ShipFactory(){

		}

// 		Vehicle* ShipFactory::manufactureVehicle(int damageBatallion,int damageToShip){
// 			return new Ship(damageBatallion,damageToShip);
// 		}

		Vehicle* ShipFactory::manufactureVehicle(){
			return new Ship();
		}

