#include <exception>
using namespace std;
#include<vectors>
#include "Ship.h"
#include "Vehicle.h"


	Ship::Ship(){ 
		numBattalionDestroys=2;
		numShipDestroys=1;
	}
	
	Ship::Ship(int bDamage,int sDamage){
		numBattalionDestroys=bDamage;
		numShipDestroys=sDamage; 
	}

	Ship::~Ship(){
		cout<<"Ship destroyed"<<endl; 
	}
	
	void Ship::attack(Country* enemy){
		if(enemy!-NULL){
				vector<Ship*> *ships=enemy->getMilitary()->getShips();
				vector<Ship*>::iterator *it;
				it=ships->begin();
				int i =0;
				while(i<numShipDestroys){
					*it->remove();
					it++;
				}
				vector<Battalion*> * fighters=enemy->getMilitary()->getBattalions();
				vector<Battalion*>::iterator *itr;
				i=0;
				while(i<numBattalionDestroys){
					*itr->remove();
					itr++;
				}

			}
	}
	
	void Ship::findEnemy(){

	}
	
	void Ship::destroyEnemy(Country* enemy){
		cout<<enemy-getName()<<" country has been defeated"<<endl;
		delete enemy;
	}
	
	void Ship::setNumBattalionDestroys(int bDamage){
		numBattalionDestroys=bDamage;
	}
	
	void Ship::setNumShipDestroys(int sDamage){
		numShipDestroys=sDamage;
	}
	
	int Ship::getBattalionDestroyed(){
		return numBattalionDestroys;
	}
	
	int Ship::getShipDestroyed(){
		return numShipDestroys;
	}