#include <exception>
using namespace std;

#include "EarlyStage.h"
#include "WarStage.h"

WarStage* EarlyStage::onlyInstance = 0;

WarStage* EarlyStage::getInstance() {
	if(onlyInstance == 0){
		onlyInstance = new EarlyStage();
	}
	return onlyInstance;
}

WarStage* EarlyStage::getInstance(int length) {
	if(onlyInstance == 0){
		onlyInstance = new EarlyStage(length);
	}
	return onlyInstance;
}

EarlyStage::EarlyStage(){
	simulationLength = 0;
	currentRound = 0;
}

EarlyStage::EarlyStage(int length){
	simulationLength = length;
	currentRound = 0;
}

WarStage* EarlyStage::clone(){

}

int EarlyStage::getWarStage(){
	
}

void EarlyStage::changeStage(){

}