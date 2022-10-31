#include <exception>
using namespace std;
#include<vector>
#include "Plane.h"
#include "Vehicle.h"


Plane::Plane(){
	numPlanesDestroys=2;
	numTankDetroys=1;
	numBattalionDestroys=4;
}

Plane::Plane(int pDamage,int tDamage,int bDamage){
	numPlanesDestroys=pDamage;
	numTankDetroys=tDamage;
	numBattalionDestroys=bDamage;
}

Plane::~Plane(){

}
void Plane::attack(Country* enemy){
	if(enemy!-NULL){
				vector<Battalion*> *fighters=enemy->getMilitary()->getBattalions();
				vector<Battalion*>::iterator *it;
				if(fighters->size>0){
					it=fighters->begin();
					int i =0;
					while(i<numBattalionDestroys){
					*it->remove();
					it++;
					}

					vector<Tank*> * fighters=enemy->getMilitary()->getTanks();
					vector<Tank*>::iterator *itr;
					i=0;
					while(i<numTankDestroys){
						*itr->remove();
						itr++;
					}

					vector<Plane*> * fighters=enemy->getMilitary()->getPlanes();
					vector<PLane*>::iterator *itr1;
					i=0;
					while(i<numPlanesDestroys){
						*itr1->remove();
						itr1++;
					}

				}
				


			}
}
int Plane::getPlanesDestroyed(){
	returm numPlanesDestroys;
}
int Plane::getBattalionDestroyed(){
	return numBattalionDestroys;
}
int Plane::getTankDestroyed(){
	return numTankDestroys;
}
void Plane::setNumPlanesDestroys(int pDamage){
	setNumPlanesDestroys=pDamage;
}
void Plane::setNumTankDetroys(int tDamage){
	numTankDetroys=tank;
}
void Plane::setNumBattalionDestroys(int bDamage){
	battalionDamage=bDamage;
}
void destroyEnemy(Country * enemy){
	cout<<enemy-getName()<<" country has been defeated"<<endl;
	delete enemy;
}
void findEnemy(){

}