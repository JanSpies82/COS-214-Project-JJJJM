#include "CountryState.h"
#include "Country.h"
#include "SimulationState.h"

CountryState::CountryState(Country* _request){
  request = _request;
  timestamp = std::time(0);
}

void CountryState::simulationState() {
	return;
}

