#include "MilitaryState.h"
#include "Military.h"
#include "Tank.h"
#include "Ship.h"
#include "Plane.h"
#include "Battalion.h"
#include"BattalionObserver.h"
#include<iostream>
MilitaryState::MilitaryState(){
    State=NULL;
}

MilitaryState::MilitaryState(Military * m){
	State=m;
    
}

MilitaryState::~MilitaryState(){
   
}
		
void MilitaryState::storeState(Military * m){
	State=m;
}

Military* MilitaryState:: getState(){
    if(State!=NULL)
        return State;
    else{
        __throw_invalid_argument("NULLPTR RECIEVED");
    }
}   

 void MilitaryState::setNumShips(int n){
 	if(n==0){
        this->State->clearShips();
    }
    else if(n==State->getNumShips()){

    }else if(n>State->getNumShips()){
        int sizeOfinput=n-State->getNumShips();
        for(int i =0;i<sizeOfinput;i++){
            this->State->insertShips(new Ship());
        }
    }else{

        int sizeOfRemove=State->getNumPlanes()-n;
        std::cout<<sizeOfRemove<<" needs to be delete\n";
        for(int i =0;i<sizeOfRemove;i++){
            delete this->State->getShips()->at(i);
        }
    }

    numShips=State->getNumShips();
 }
 
 void MilitaryState::setNumPlanes(int n){
 	if(n==0){
        State->clearPlanes();
    }
    else if(n==State->getNumPlanes()){

    }else if(n>State->getNumPlanes()){
        int sizeOfinput=n-State->getNumPlanes();
        for(int i =0;i<sizeOfinput;i++){
            State->insertPlanes(new Plane());
        }
    }else{
        int sizeOfRemove=State->getNumPlanes()-n;
        for(int i =0;i<sizeOfRemove;i++){
            delete this->State->getPlanes()->at(i);
        }
    }
    numPlanes=State->getNumPlanes();
  }  
 void MilitaryState::setNumTanks(int n){
 	if(n==0){
        this->State->clearTanks();
    }
    else if(n==State->getNumTanks()){

    }else if(n>State->getNumTanks()){
        int sizeOfinput=n-State->getNumTanks();
        for(int i =0;i<sizeOfinput;i++){
            State->insertTanks(new Tank());
        }
    }else{

        int sizeOfRemove=State->getNumTanks()-n;
        for(int i =0;i<sizeOfRemove;i++){
            delete this->State->getTanks()->at(i);
        }
    }
    
    numTanks=State->getNumTanks();
 }
 void MilitaryState::setNumTroops(int n){
 	State->setNumTroops(n);
    numTroops=State->getNumTroops();  
 }

 void MilitaryState::setNumBatalion(int n){
    if(n==0){
        State->clearBatalions();
    }
    else if(n==State->getNumBattalions()){

    }else if(n>State->getNumBattalions()){
        int sizeOfinput=n-State->getNumBattalions();
        for(int i =0;i<sizeOfinput;i++){
            State->insertBatalions(new Battalion());
        }
    }else{
        int sizeOfRemove=State->getNumBattalions()-n;
        for(int i =0;i<sizeOfRemove;i++){
            delete this->State->getBatallions()->at(i);
        }
    }

    numBattalions=State->getNumBattalions();
}
int MilitaryState::getNumBattalions(){

    numBattalions=State->getNumBattalions();
    return numBattalions;
}

int MilitaryState::getNumPlanes(){
    numPlanes=State->getNumPlanes();
    return numPlanes;
}

int MilitaryState::getNumShips(){
    numShips=State->getNumShips();
    return numShips;
}

int MilitaryState::getNumTanks(){
    numTanks=State->getNumTanks();
    return numTanks;
}

int MilitaryState::getNumTroops(){
    numTroops=State->getNumTroops();
    return numTroops; 
}

