///@author Mekhail Muller

#include "StageContext.h"
#include "WarStage.h"
#include "EarlyStage.h"
#include "MiddleStage.h"
#include "LateStage.h"
#include "StageContextState.h"
#include <cmath>

StageContext *StageContext::onlyInstance = NULL;

StageContext::StageContext()
{
	simulationLength = 0;
	currentRound = 0;
	currentStage = new EarlyStage();
}

int StageContext::getCurrentRound()
{
	return currentRound;
}

StageContext *StageContext::getInstance()
{
	if (onlyInstance == NULL)
	{
		onlyInstance = new StageContext();
	}
	return onlyInstance;
}

int StageContext::getWarStage()
{
	return currentStage->getWarStage();
}

void StageContext::incrementRound()
{
	int earlyStage = floor(simulationLength * 0.3);
	int midStage = floor(simulationLength * 0.9);
	currentRound++;

	if (currentRound == earlyStage)
	{
		WarStage *current = currentStage;
		currentStage = new MiddleStage();
		delete current;
	}
	else if (currentRound == midStage)
	{
		WarStage *current = currentStage;
		currentStage = new LateStage();
		delete current;
	}
}

void StageContext::setSimulationLength(int _length)
{
	simulationLength = _length;
}


StageContext::~StageContext()
{
    delete currentStage;
	onlyInstance = NULL;
}

int StageContext::getSimulationLength()
{
	return simulationLength;
}

void StageContext::setCurrentRound(int _round)
{
	currentRound = _round;
}

void StageContext::setCurrentStage(WarStage *_stage)
{
	currentStage = _stage;
}

StageContextState* StageContext::getState()
{
    StageContextState* state = new StageContextState();
    state->setSimulationLength(simulationLength);
	state->setCurrentRound(currentRound);
	state->setCurrentStage(currentStage->clone());
	return state;
}

void StageContext::setState(StageContextState *_state)
{
	simulationLength = _state->getSimulationLength();
	currentRound = _state->getCurrentRound();
	delete currentStage;
	currentStage = _state->getCurrentStage();
}

void StageContext::moveToStage(int _stage)
{
	WarStage *current = currentStage;
	if (_stage == 0)
		currentStage = new EarlyStage();
	else if (_stage == 1)
		currentStage = new MiddleStage();
	else if (_stage == 2)
		currentStage = new LateStage();
	if (current != currentStage)
		delete current;
}
