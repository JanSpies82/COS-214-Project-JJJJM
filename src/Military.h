#include <vector>
using namespace std;

#ifndef __Military_h__
#define __Military_h__

#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
// #include "Country.h"
// #include "VehicleFactory.h"
// #include "Vehicle.h"

class Battalion;
class Plane;
class Ship;
class Country;
class VehicleFactory;
class Vehicle;
class Military;

class Military
{
	private: vector<Battalion> battalions;
	private: vector<Plane> planes;
	private: vector<Ship> ships;
	private: vector<Tank> tanks;
	public: Country* countrys;
	public: VehicleFactory* vehicleFactorys;
	public: Vehicle* vehicles;
	public: Battalion* battalions2;
};

#endif
