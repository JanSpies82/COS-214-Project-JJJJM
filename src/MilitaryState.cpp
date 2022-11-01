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

 void MilitaryState::setNumShips(int n){
 	numShips=n;
 }
 
 void MilitaryState::setNumPlanes(int n){
 	numPlanes=n;
  }  
 void MilitaryState::setNumTanks(int n){
 	numTanks=n;
    
 }
 void MilitaryState::setNumTroops(int n){
 	numTroops=n;  
 }

 void MilitaryState::setNumBatalion(int b){
    numBattalions=b;
 }
 
int MilitaryState::getNumBattalions(){
    return numBatalions;
}

