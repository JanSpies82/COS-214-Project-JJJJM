///@author Janco Spies

#include "StageContextState.h"
#include "WarStage.h"
using namespace std;

StageContextState::StageContextState(){
    simulationLength = 0;
    currentRound = 0;
    currentStage = NULL;
}

StageContextState::~StageContextState(){
    if (currentStage != NULL)
        delete currentStage;
}

void StageContextState::setSimulationLength(int _length){
    simulationLength = _length;
}

int StageContextState::getSimulationLength(){
    return simulationLength;
}

void StageContextState::setCurrentRound(int _round){
    currentRound = _round;
}

int StageContextState::getCurrentRound(){
    return currentRound;
}

void StageContextState::setCurrentStage(WarStage *_stage){
    currentStage = _stage;
}

WarStage* StageContextState::getCurrentStage(){
    return currentStage->clone();
}