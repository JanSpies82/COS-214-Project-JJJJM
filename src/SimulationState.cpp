#include <exception>
using namespace std;

#include "SimulationState.h"
#include "SimulationManager.h"
#include "MapState.h"
#include "CountryState.h"
#include "MilitaryState.h"

SimulationState::SimulationState(SimulationManager *_simulationManager)
{
    this->simulationManager = _simulationManager;
    this->timestamp = time(0);
    mapState = NULL;
    countryStates = new vector<CountryState *>();
    militaryStates = new vector<MilitaryState *>();
}

SimulationState::~SimulationState()
{
    if (mapState != NULL)
        delete mapState;

    for (int i = 0; i < countryStates->size(); i++)
        delete countryStates->at(i);
    delete countryStates;

    for (int i = 0; i < militaryStates->size(); i++)
        delete militaryStates->at(i);
    delete militaryStates;
};

void SimulationState::setMapState(MapState *_mapState)
{
    if (mapState != NULL)
        delete mapState;
    mapState = _mapState;
}

MapState *SimulationState::getMapState()
{
    if (mapState == NULL)
        __throw_out_of_range("SimulationState does not hold a MapState");
    return mapState;
}

void SimulationState::addCountryState(CountryState *_countryState)
{
    countryStates->push_back(_countryState);
}

CountryState *SimulationState::getCountryState(int index)
{
    if (index < 0 || index >= countryStates->size())
        __throw_out_of_range("CountryState index out of range");
    return countryStates->at(index);
}

void SimulationState::addMilitaryState(MilitaryState *_militaryState)
{
    militaryStates->push_back(_militaryState);
}

MilitaryState *SimulationState::getMilitaryState(int index)
{
    if (index < 0 || index >= militaryStates->size())
        __throw_out_of_range("MilitaryState index out of range");
    return militaryStates->at(index);
}

int SimulationState::getCountryStateCount()
{
    return countryStates->size();
}

int SimulationState::getMilitaryStateCount()
{
    return militaryStates->size();
}

time_t SimulationState::getTimestamp()
{
    return this->timestamp;
}