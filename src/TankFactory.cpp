#include <exception>
using namespace std;

#include"Tank.h"
#include "TankFactory.h"
#include "VehicleFactory.h"

		TankFactory::TankFactory(){
			
		}
		
		TankFactory::~TankFactory(){

		}
		Vehicle* TankFactory::manufactureVehicle(int damageBattalion,int damageToTank){
			
			return new Tank(damageBattalion,damageToTank);
		}

		Vehicle* TankFactory::manufactureVehicle(){
			return new Tank();
		}

