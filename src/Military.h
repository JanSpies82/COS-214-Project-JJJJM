#include <vector>
using namespace std;

#ifndef __Military_h__
#define __Military_h__

#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"



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
		vector<Battalion> battalions;
		vector<Ship> ships;
		vector<Tank> tanks;
		//Country* countries;
		vector<Plane> planes;
		VehicleFactory* vehicleFactoress;
		Battalion* battalions;
};

#endif
