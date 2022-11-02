#include "CountryState.h"
#include "MilitaryState.h"
#include "Country.h"

CountryState::CountryState()
{
  numCitizens = 0;
  politicalStability = 0;
  domesticMorale = 0;
  borderStrength = 0;
  capitalSafety = 0;
  warSentiment = 0;
  tradeRouteSafety = 0;
  militaryState = new MilitaryState();
}

CountryState::CountryState(Country* country)
{
  numCitizens = country->getNumCitizens();
  politicalStability = country->getPoliticalStability();
  domesticMorale = country->getDomesticMorale();
  borderStrength = country->getBorderStrength();
  capitalSafety = country->getCapitalSafety();
  warSentiment = country->getWarSentiment();
  tradeRouteSafety = country->getTradeRouteSafety();

  militaryState = new MilitaryState();
}

CountryState::CountryState(const CountryState& cs)
{
  numCitizens = cs.numCitizens;
  politicalStability = cs.politicalStability;
  domesticMorale = cs.domesticMorale;
  borderStrength = cs.borderStrength;
  capitalSafety = cs.capitalSafety;
  warSentiment = cs.warSentiment;
  tradeRouteSafety = cs.tradeRouteSafety;
  militaryState = cs.militaryState->clone();
}

CountryState::~CountryState()
{
  delete militaryState;
}

CountryState* CountryState::clone()
{
  return new CountryState(*this);
}

MilitaryState* CountryState::getMilitaryState()
{
  return militaryState;
}
