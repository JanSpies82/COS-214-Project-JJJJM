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

SimulationState::~SimulationState(){
    if (mapState != NULL)
        delete mapState;
        
    for (int i = 0; i < countryStates->size(); i++)
        delete countryStates->at(i);
    delete countryStates;

    for (int i = 0; i < militaryStates->size(); i++)
        delete militaryStates->at(i);
    delete militaryStates;
};

time_t SimulationState::getTimestamp()
{
    return this->timestamp;
}