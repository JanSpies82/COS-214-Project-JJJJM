#include "CountryState.h"
#include "Country.h"

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

CountryState::CountryState(const CountryState& cs)
{
  timestamp = cs.timestamp;
  numCitizens = cs.numCitizens;
  politicalStability = cs.politicalStability;
  domesticMorale = cs.domesticMorale;
  borderStrength = cs.borderStrength;
  capitalSafety = cs.capitalSafety;
  warSentiment = cs.warSentiment;
  tradeRouteSafety = cs.tradeRouteSafety;
}

CountryState* CountryState::clone()
{
  return new CountryState(*this);
}
