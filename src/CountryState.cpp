#include "CountryState.h"
#include "Country.h"
#include "SimulationState.h"

CountryState::CountryState(Country* country){
  timestamp = std::time(0);
  numCitizens = country->getNumCitizens();
  politicalStability = country->getPoliticalStability();
  domesticMorale = country->getDomesticMorale();
  borderStrength = country->getBorderStrength();
  capitalSafety = country->getCapitalSafety();
  warSentiment = country->getWarSentiment();
  tradeRouteSafety = country->getTradeRouteSafety();
}

