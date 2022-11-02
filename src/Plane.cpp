// #include <exception>
// #include<iostream>
using namespace std;
// #include<vector>
// #include"Military.h"
// #include"Battalion.h"
#include "Plane.h"
// #include"Tank.h"
// #include "Vehicle.h"
// #include"Country.h"

Plane::Plane()
{

Plane::Plane(){
// 	numPlanesDestroys=2;
// 	numTankDestroys=1;
// 	numBattalionDestroys=4;
}

// Plane::Plane(int pDamage,int tDamage,int bDamage){
// 	numPlanesDestroys=pDamage;
// 	numTankDestroys=tDamage;
// 	numBattalionDestroys=bDamage;
// }

Plane::~Plane(){

}
void Plane::attack(Country* enemy){}
// 	if(enemy!=NULL){
// 		vector<Battalion*> *fighters1=enemy->getMilitary()->getBatallions();
// 		if(fighters1->size()>numBattalionDestroys){
// 			for (int i = 0; i < numBattalionDestroys; i++)
//         		delete fighters1->at(i);
// 		}else{
// 			enemy->getMilitary()->clearBatalions();
// 		}
			
// 		vector<Tank*> * fighters2=enemy->getMilitary()->getTanks();
// 		if(fighters2->size()>numTankDestroys){
// 			for (int i = 0; i < numTankDestroys; i++)
//         		delete fighters2->at(i);
// 		}else{
// 			enemy->getMilitary()->clearTanks();
// 		}
		
// 		vector<Plane*> * fighters3=enemy->getMilitary()->getPlanes();
// 		if(fighters3->size()>numPlanesDestroys){
// 			for (int i = 0; i < numPlanesDestroys; i++)
//         		delete fighters3->at(i);
// 		}else{
// 			enemy->getMilitary()->clearPlanes();
// 		}

// 	}
// }
// int Plane::getPlanesDestroyed(){
// 	return numPlanesDestroys;
// }
// int Plane::getBattalionDestroyed(){
// 	return numBattalionDestroys;
// }
// int Plane::getTankDestroyed(){
// 	return numTankDestroys;
// }
// void Plane::setNumPlanesDestroys(int pDamage){
// 	numPlanesDestroys=pDamage;
// }
// void Plane::setNumTankDetroys(int tDamage){
// 	numTankDestroys=tDamage;
// }
// void Plane::setNumBattalionDestroys(int bDamage){
// 	 numBattalionDestroys=bDamage;
// }
void Plane::destroyEnemy(Country * enemy){}
// 	cout<<enemy->getName()<<" country has been defeated"<<endl;
// 	delete enemy;
// }
void Plane::findEnemy(){

}
