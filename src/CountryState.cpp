#include "CountryState.h"
#include "Country.h"
#include "SimulationState.h"

CountryState::CountryState(Country* country){
  timestamp = std::time(0);
}

void CountryState::simulationState() {
	return;
}

