#include "MilitaryState.h"
#include "Military.h"

MilitaryState::MilitaryState(Military * m){
	State=m;
}

MilitaryState::~MilitaryState(){

}
		
void MilitaryState::storeState(Military * m){
	State=m;
}

Military* MilitaryState:: getState(){
    return State;
}

 int MilitaryState::getNumShips(){
 	m->getNumShips();
 }
 int MilitaryState::getNumPlanes(){
 	m->getNumPlanes();
 }
 int MilitaryState::getNumTanks(){
 	m->getNumTanks();
 }
 int MilitaryState::getNumTroops(){
 	m->getNumBattalions();
 }


