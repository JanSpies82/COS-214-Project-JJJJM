#include <exception>

#include "Stage.h"
#include "WarStage.h"
#include "EarlyStage.h"
#include "MiddleStage.h"
#include "LateStage.h"

// void WarStage::handle() {
// 	throw "Not yet implemented";
// }

// void WarStage::handle() {
// 	throw "Not yet implemented";
// }

Stage* Stage::onlyInstance = 0;
WarStage* Stage::currentStage = 0;

WarStage* Stage::getInstance() {
	if(onlyInstance == 0){
		onlyInstance = new Stage();
	}
	if(currentStage == 0){
		currentStage = new EarlyStage();
	}
	return currentStage;
}

Stage::Stage(){
	simulationLength = 0;
	currentRound = 0;
}

void Stage::setSimulationLength(int length){
	simulationLength = length;
}

int Stage::getCurrentRound(){
	return currentRound;
}

void Stage::incrementRound(){
	int earlyStage = simulationLength * 0.3;
	int midStage = simulationLength * 0.9;
	currentRound++;

	if(currentRound == earlyStage){
		WarStage* current = currentStage;
		currentStage = new MiddleStage();
		delete current;
	}
	else if(currentRound == midStage){
		WarStage* current = currentStage;
		currentStage = new LateStage();
		delete current;
	}
	
}