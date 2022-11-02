#include <exception>

#include "StageContext.h"
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

StageContext* StageContext::onlyInstance = 0;
WarStage* StageContext::currentStage = 0;

StageContext* StageContext::clone(){
    StageContext* clone = new StageContext();
    clone->simulationLength = simulationLength;
    clone->currentRound = currentRound;
    clone->currentStage = currentStage;
    clone->onlyInstance = clone;
    return clone;
}

int StageContext::getCurrentRound(){
	return currentRound;
}

StageContext* StageContext::getInstance() {
	if(onlyInstance == 0){
		onlyInstance = new StageContext();
	}
	return onlyInstance;
}

int StageContext::getWarStage(){
    return currentStage->getWarStage();
}

void StageContext::incrementRound(){
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

void StageContext::setSimulationLength(int length){
	simulationLength = length;
}

StageContext::StageContext(){
	simulationLength = 0;
	currentRound = 0;
    currentStage = new EarlyStage();
}

StageContext::~StageContext(){
    delete currentStage;
    delete onlyInstance;
}





