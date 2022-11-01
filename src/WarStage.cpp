#include <exception>

#include "WarStage.h"
#include "Country.h"

// void WarStage::handle() {
// 	throw "Not yet implemented";
// }

#include <exception>

#include "WarStage.h"
#include "Country.h"

// void WarStage::handle() {
// 	throw "Not yet implemented";
// }

// WarStage* WarStage::getInstance() {
// 	if(onlyInstance == 0){
// 		onlyInstance = new WarStage();
// 	}
// 	return onlyInstance;
// }

WarStage::WarStage(){
	simulationLength = 0;
	currentRound = 0;
}

void WarStage::setSimulationLength(int length){
	simulationLength = length;
}

int WarStage::getCurrentRound(){
	return currentRound;
}



void WarStage::incrementRound(){
	currentRound++;
}