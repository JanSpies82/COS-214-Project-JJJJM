/// @author Janco Spies

#include <exception>
using namespace std;

#include "SimulationState.h"
#include "MapState.h"
#include "StageContextState.h"
#include "SuperpowerState.h"

SimulationState::SimulationState()
{
    this->timestamp = time(0);
    mapState = NULL;
    stageContextState = NULL;
    superpowerStates = new vector<SuperpowerState *>();
}

SimulationState::~SimulationState()
{
    if (mapState != NULL)
        delete mapState;
    
    if (stageContextState != NULL)
        delete stageContextState;

    for (int i = 0; i < superpowerStates->size(); i++)
        delete superpowerStates->at(i);
    delete superpowerStates;
};

void SimulationState::setMapState(MapState *_mapState)
{
    if (mapState != NULL)
        delete mapState;
    mapState = _mapState;
}

void SimulationState::setStageContextState(StageContextState *_stageContextState)
{
    if (stageContextState != NULL)
        delete stageContextState;
    stageContextState = _stageContextState;
}


StageContextState* SimulationState::getStageContextState()
{
    if (stageContextState == NULL)
        __throw_out_of_range("SimulationState does not hold a StageContextState");
    return stageContextState;
}

MapState *SimulationState::getMapState()
{
    if (mapState == NULL)
        __throw_out_of_range("SimulationState does not hold a MapState");
    return mapState;
}

void SimulationState::addSuperpowerState(SuperpowerState *_superpowerState)
{
    superpowerStates->push_back(_superpowerState);
}

SuperpowerState *SimulationState::getSuperpowerState(int _index)
{
    if (_index < 0 || _index >= superpowerStates->size())
        __throw_out_of_range("Index out of range");
    return superpowerStates->at(_index);
}

int SimulationState::getSuperpowerStateCount()
{
    return superpowerStates->size();
}

time_t SimulationState::getTimestamp()
{
    return this->timestamp;
}