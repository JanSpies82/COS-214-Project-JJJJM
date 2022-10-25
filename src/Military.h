
#ifndef __Military_h__
#define __Military_h__

// #include "Battalion.h"
// #include "Plane.h"
// #include "Ship.h"
// #include "Tank.h"
#include <vector>

class VehicleFactory;
class Plane;
class Ship;
class Tank;
class Battalion;


class Military
{
	public:
		/**
		 **/
		Military();

		/**
		 **/
		~Military();

		/**
		 **/
		int getNumBattalions();

		/**
		 **/
		int getNumTanks();

		/**
		 **/
		int getNumPlanes();

		/**
		 **/
		int getNumShips();

		/**
		 **/
		int getNumVehicles();

		/**
		 **/
		void attack();//a bit tricky but sum the up the damage of the entire army well that might be an option
		
	private: 
		std::vector<Battalion*>* battalions;
		std::vector<Ship*>* ships;
		std::vector<Tank*>* tanks;
		//Country* countries;
		std::vector<Plane*>* planes;
		std::vector<VehicleFactory*>* vehicleFactories;
		// Battalion* battalions;
};

#endif
