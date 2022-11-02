#include "CountryState.h"
#include "MilitaryState.h"
#include "Country.h"

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
