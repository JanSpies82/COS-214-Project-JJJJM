#include <exception>
using namespace std;
#include<vector>
#include "Tank.h"
#include "Vehicle.h"

		Tank::Tank(){
			numBattalionDestroys=5;
			numTankDestroys=2;
		}
		
		Tank::Tank(int damageToBatallion,int damageToTanks){
			numBattalionDestroys=damageToBatallion;
			numTankDetroys=damageToTanks;
		}

		Tank::~Tank(){
			cout<<"Tank destroyed"<<endl;
		}
		
		void Tank::attack(Country* enemy){
			if(enemy!-NULL){
				vector<Tank*> *tanks=enemy->getMilitary()->getTanks();
				vector<Tank*>::iterator *it;
				it=tanks->begin();
				int i =0;
				while(i<numTankDestroys){
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
		
		void Tank::findEnemy(){

		}
		
		void Tank::destroyEnemy(Country* enemy){
			cout<<enemy-getName()<<" country has been defeated"<<endl;
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