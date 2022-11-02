#include <exception>
#include<iostream>
#include<vector>
#include "Ship.h"
#include "Battalion.h"
#include "Vehicle.h"
#include "Military.h"
#include"Country.h"
using namespace std;

	Ship::Ship(){ 
		numBattalionDestroys=2;
		numShipDestroys=1;
	}
	
	Ship::Ship(int bDamage,int sDamage){
		numBattalionDestroys=bDamage;
		numShipDestroys=sDamage; 
	}

	Ship::~Ship(){
		
	}
	
	void Ship::attack(Country* enemy){
		if(enemy!=NULL){
				vector<Ship*> *fighters1=enemy->getMilitary()->getShips();
				if(fighters1->size()>numShipDestroys){
				for (int i = 0; i < numShipDestroys; i++)
        			delete fighters1->at(i);
				}else{
					enemy->getMilitary()->clearBattalions();
				}
				vector<Battalion*> *fighters2=enemy->getMilitary()->getBattalions();
				if(fighters2->size()>numBattalionDestroys){
					for (int i = 0; i < numBattalionDestroys; i++)
        				delete fighters2->at(i);
				}else{
					enemy->getMilitary()->clearBattalions();
				}

			}
	}
	
	void Ship::findEnemy(){

	}
	
	void Ship::destroyEnemy(Country* enemy){
		cout<<enemy->getName()<<" country has been defeated"<<endl;
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