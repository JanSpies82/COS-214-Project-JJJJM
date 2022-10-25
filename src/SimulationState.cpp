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
}

SimulationState::~SimulationState(){};

time_t SimulationState::getTimestamp()
{
    return this->timestamp;
}