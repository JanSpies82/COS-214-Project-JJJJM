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


int Stage::getCurrentRound(){
	return currentRound;
}

Stage* Stage::getInstance() {
	if(onlyInstance == 0){
		onlyInstance = new Stage();
	}
	return onlyInstance;
}

int Stage::getWarStage(){
    return currentStage->getWarStage();
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

void Stage::setSimulationLength(int length){
	simulationLength = length;
}

Stage::Stage(){
	simulationLength = 0;
	currentRound = 0;
    currentStage = new EarlyStage();
}

Stage::~Stage(){
    delete currentStage;
    delete onlyInstance;
}





