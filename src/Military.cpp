#include <vector>
using namespace std;

#include "Military.h"
#include "Battalion.h"
#include "Plane.h"
#include "Ship.h"
#include "Country.h"
#include "VehicleFactory.h"
#include "Vehicle.h"


Military::Military(){
	shipDamage=2;
	tankDamage=3;
	planeDamage=1;
	battalionDamage=5;
	 
	battalions =new <Battalion*>();
	ships=new <Ship*>;
	tanks=new <Tank*>();
	planes=new <Plane*>();
	vehicleFactories=new <VehicleFactory*>();
}

Military::Military(int pDamage,int sDamage,int tDamage,int bDamage){
	shipDamage=sDamage;
	tankDamage=tDamage;
	planeDamage=pDamage;
	battalionDamage=bDamage;

	battalions =new <Battalion*>();
	ships=new <Ship*>;
	tanks=new <Tank*>();
	planes=new <Plane*>();
	vehicleFactories=new <VehicleFactory*>();
}

Military::~Military(){
	//delete each element
	clearShips();
	clearTanks();
	clearPlanes();
	clearBatalions();

	
	//delete the vectors
	delete battalions;
	delete tanks;
	delete planes;
	delete vehicleFactories;
}

void Military::insertPlanes(Plane* plane){	
	if(plane!=NULL){
		planes->insert(plane);
	}else{
		cout<<"NULL plane error"<<endl;
	}
}	

void Military::insertPlanes(vector<Plane*> _plane){
	for (int i = 0; i < this->_plane->size(); i++)
		this->planes->insert(this->planes->begin(), _plane_>at(i));
}	

void Military::insertTanks(Tank* _tanks){
	if(_tanks!=NULL){
		tanks->insert(_tanks);
	}else{
		cout<<"NULL tank error"<<endl;
	}
}	

void Military::insertTanks(vector<Tank*> _tanks){
	for (int i = 0; i < this->_tanks->size(); i++)
		this->tanks->insert(this->tanks->begin(), _tanks);
}	

void Military::insertShips(Ship* ship){
	if(ship!=NULL){
		ships->insert(ship);
	}else{
		cout<<"NULL ship error"<<endl;
	}
}

void Military::insertShips(vector<Ship*> _ships){
	for (int i = 0; i < this->_ships->size(); i++)
		this->ships->insert(this->ships->begin(), _ships);	
}	

void Military:: addBattalions(){
	battalions->insert(new Battalion());
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

Battalion* Military:: getBatallions(){
		if(battalions->size()>0)
			return battalions;
}

Plane* Military:: getPlanes(){
		if(battalions->size()>0)
			return planes;
}

Tank* Military:: getTanks(){
		if(battalions->size()>0)
			return tanks;
}

Ship* Military:: getShips(){
		if(battalions->size()>0)
			return ships;
}

void Military::clearTanks()
{
    for (int i = 0; i < this->tanks->size(); i++)
        delete this->tanks>at(i);
    
    this->tanks->clear();
}

void Military::clearShips()
{
    for (int i = 0; i < this->ships->size(); i++)
        delete this->ships->at(i);
    
    this->ships->clear();
}

void Military::clearPlanes()
{
    for (int i = 0; i < this->planes->size(); i++)
        delete this->planes->at(i);
    
    this->planes->clear();
}

void Military::clearBatalions()
{
    for (int i = 0; i < this->batalions->size(); i++)
        delete this->batalions->at(i);
    
    this->batalions->clear();
}

