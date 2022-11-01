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
WarStage* WarStage::onlyInstance = 0;

WarStage* WarStage::getInstance() {
	if(onlyInstance == 0){
		onlyInstance = new WarStage();
	}
	return onlyInstance;
}

WarStage::WarStage(){
	simulationLength = 0;
	warStage = "";
	currentRound = 0;
}

void WarStage::setSimulationLength(int length){
	simulationLength = length;
}

int WarStage::getCurrentRound(){
	return currentRound;
}

string WarStage::getWarStage(){
	int earlyStageEnds = simulationLength * 0.3;
	int middleStageEnds = simulationLength * 0.8;

	if(currentRound < earlyStageEnds)
		return "earlystage";
	else if(currentRound < middleStageEnds)
		return "middlestage";
	else
		return "endstage";
}

void WarStage::incrementRound(){
	currentRound++;
}