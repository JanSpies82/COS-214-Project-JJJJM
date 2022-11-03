#include "CountryState.h"
#include "MilitaryState.h"
#include "Location.h"
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
  selfReliance = 0;
  militaryState = new MilitaryState();
  locations = NULL;
  enemies = NULL;
  capital = NULL;
  color = "";
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
  selfReliance = country->getSelfReliance();
  militaryState = new MilitaryState();
  capital = NULL;
  capital = country->getCapital();
  locations = NULL;
  locations = country->getLocations();
  enemies = NULL;
  enemies = country->getEnemies();
  color = country->getColor();
}

CountryState::CountryState(const CountryState& cs)
{
  name = cs.name;
  numCitizens = cs.numCitizens;
  domesticMorale = cs.domesticMorale;
  selfReliance = cs.selfReliance;
  borderStrength = cs.borderStrength;
  capitalSafety = cs.capitalSafety;
  warSentiment = cs.warSentiment;
  tradeRouteSafety = cs.tradeRouteSafety;
  politicalStability = cs.politicalStability;
  militaryState = cs.militaryState->clone();
  capital = NULL;
  capital = cs.capital;
  color = cs.color;
  enemies = NULL;
  enemies = cs.enemies;
  locations = NULL;
  locations = cs.locations;
}

CountryState::~CountryState()
{
  if (capital != NULL)
    delete capital;

  if (enemies != NULL)
  {
    enemies->resize(0);
    delete enemies;
  }

  if (locations != NULL)
  {
    locations->resize(0);
    delete locations;
  }

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
