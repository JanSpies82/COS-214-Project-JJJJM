/// @author Jake Mahloko

#include "Military.h"
#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"
#include "Country.h"
#include "VehicleFactory.h"
#include "Vehicle.h"
#include <vector>
#include <iostream>

using namespace std;


Military::Military(){}

Military::Military(Military* copy){}

Military::~Military(){}

void attack(Country* country){}

//  void Military::setNumTroops(int t){
//  	numTroops=t;
//  }

//  int Military::getNumTroops(){
//  	return numTroops;
//  }