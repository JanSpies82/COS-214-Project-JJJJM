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
	currentRound = 0;
}

EarlyStage::EarlyStage(int round){
	currentRound = round;
}

WarStage* EarlyStage::clone(){
	WarStage* clone = new EarlyStage(currentRound);
	return clone;
}

int EarlyStage::getWarStage(){
	return 0;
}

WarStage* EarlyStage::changeStage(){
	return MiddleStage::getInstance(currentRound);
}