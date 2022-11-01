#include <exception>
#include<iostream>
#include "Military.h"
#include "Battalion.h"
#include<vector>
#include "Tank.h"
#include "Vehicle.h"
#include "Country.h"
using namespace std;

Tank::Tank(){
	numBattalionDestroys=5;
	numTankDestroys=2;
}
		
Tank::Tank(int damageToBatallion,int damageToTanks){
	numBattalionDestroys=damageToBatallion;
	numTankDestroys=damageToTanks;
}
Tank::~Tank(){
	
}
		
void Tank::attack(Country* enemy){
	if(enemy!=NULL){
		vector<Battalion*> *fighters1=enemy->getMilitary()->getBatallions();
		if(fighters1->size()>numBattalionDestroys){
			for (int i = 0; i < numBattalionDestroys; i++)
    	   		delete fighters1->at(i);
		}else{
			enemy->getMilitary()->clearBatalions();
		}
			
		vector<Tank*> * fighters2=enemy->getMilitary()->getTanks();
		if(fighters2->size()>numTankDestroys){
			for (int i = 0; i < numTankDestroys; i++)
    	   		delete fighters2->at(i);
		}else{
			enemy->getMilitary()->clearTanks();
		}

	}
}
		
void Tank::findEnemy(){
}
		
void Tank::destroyEnemy(Country* enemy){
	cout<<enemy->getName()<<" country has been defeated"<<endl;
	delete enemy;
}
		
void Tank::setNumBattalionDestroys(int batt){
	numBattalionDestroys=batt;
}
void Tank::setNumTankDetroys(int tanks){
	numTankDestroys=tanks;
}
		
int Tank::getBattalionDestroyed(){
	return numBattalionDestroys;
}
		
int Tank::getTankDestroyed(){
	return numTankDestroys;
}