#include <exception>
using namespace std;
#include"Ship.h"
#include "ShipFactory.h"
#include "VehicleFactory.h"

		ShipFactory::ShipFactory(){

		}

		ShipFactory::~ShipFactory(){

		}

		Vehicle* ShipFactory::manufactureVehicle(int damageBattalion,int damageToShip){
			return new Ship(damageBattalion,damageToShip);
		}

		Vehicle* ShipFactory::manufactureVehicle(){
			return new Ship();
		}

