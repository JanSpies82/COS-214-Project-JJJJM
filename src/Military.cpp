#include <vector>
#include <iostream>
using namespace std;

#include "Military.h"
#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"
#include "Country.h"
#include "VehicleFactory.h"
#include "Vehicle.h"


Military::Military(){
	 
	battalions =new vector<Battalion*>();
	ships=new vector<Ship*>();
	tanks=new vector<Tank*>();
	planes=new vector<Plane*>();
	vehicleFactories=new vector<VehicleFactory*>();
}

Military::Military(Military* copy){
	for (int i=0; i<copy->getBatallions()->size(); i++) 
        this->insertBatalions(copy->getBatallions()->at(i));
    for (int i=0; i<copy->getTanks()->size(); i++) 
        this->insertTanks(copy->getTanks()->at(i));
    for (int i=0; i<copy->getShips()->size(); i++) 
        this->insertShips(copy->getShips()->at(i));
    for (int i=0; i<copy->getPlanes()->size(); i++) 
        this->insertPlanes(copy->getPlanes()->at(i));
    this->numTroops=copy->getNumTroops();
}

Military::~Military(){
	
	clearShips();

	clearTanks();
	
	clearPlanes();
	
	clearBatalions();

	delete battalions;
	delete tanks;
	delete planes;
	delete vehicleFactories;
	
}

void Military::insertPlanes(Plane* plane){	
	if(plane!=NULL){
		this->planes->insert(this->planes->begin(),plane);
	}else{
		__throw_invalid_argument("NULL plane error");
	}
}	

void Military::insertBatalions(Battalion* batt){	
	if(batt!=NULL){
		this->battalions->insert(this->battalions->begin(),batt);
	}else{
		__throw_invalid_argument("NULL plane error");
	}
}
	
void Military::insertTanks(Tank* _tanks){
	if(_tanks!=NULL){
		this->tanks->insert(this->tanks->begin(),_tanks);
	}else{
		__throw_invalid_argument("NULL tank error");
	}
}	


void Military::insertShips(Ship* ship){
	if(ship!=NULL){
		this->ships->insert(this->ships->begin(),ship);
	}else{
		__throw_invalid_argument("NULL ship error");
	}
}



void Military:: addBattalions(){
	
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
	if(battalions->size()>0){
		battalions->at(0)->attack(enemy);
	}

	if(planes->size()>0){
		planes->at(0)->attack(enemy);
	}

	if(ships->size()>0){
		ships->at(0)->attack(enemy);
	}

	if(tanks->size()>0){
		ships->at(0)->attack(enemy);
	}
}

std::vector<Battalion*>* Military:: getBatallions(){
		if(battalions->size()>0)
			return battalions;
}

std::vector<Plane*>* Military:: getPlanes(){
		if(battalions->size()>0)
			return planes;
}

std::vector<Tank*>* Military:: getTanks(){
		if(battalions->size()>0)
			return tanks;
}

std::vector<Ship*>* Military:: getShips(){
		if(battalions->size()>0)
			return ships;
}

void Military::clearTanks()
{
    for (int i = 0; i < this->tanks->size(); i++)
        delete this->tanks->at(i);
}

void Military::clearShips()
{
	for (int i = 0; i < this->ships->size(); i++)
        delete this->ships->at(i);
}

void Military::clearPlanes()
{
    for (int i = 0; i < this->planes->size(); i++)
        delete this->planes->at(i);
}

void Military::clearBatalions()
{
    for (int i = 0; i < this->battalions->size(); i++)
        delete this->battalions->at(i);
}


Military* Military::getMilitary(){
	return this;
}

 void Military::setNumTroops(int t){
 	numTroops=t;
 }

 int Military::getNumTroops(){
 	return numTroops;
 }