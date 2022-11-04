/// @author Jake Weatherhead

#include "CountryState.h"
#include "MilitaryState.h"
#include "Location.h"
#include "Country.h"
#include <vector>
using namespace std;

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

CountryState::CountryState(Country *country)
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

CountryState::CountryState(const CountryState &cs)
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
  if (cs.enemies != NULL)
  {
    vector<Country *> *newEnemies = new vector<Country *>();
    for (int i = 0; i < cs.enemies->size(); i++)
    {
      newEnemies->push_back(cs.enemies->at(i));
    }
    enemies = newEnemies;
  }
  locations = NULL;
  if (cs.locations != NULL)
  {
    vector<Location *> *newLocations = new vector<Location *>();
    for (int i = 0; i < cs.locations->size(); i++)
    {
      newLocations->push_back(cs.locations->at(i));
    }
    locations = newLocations;
  }
}
CountryState::~CountryState()
{
  // if (capital != NULL)
  //   delete capital;

  if (enemies != NULL)
  {
    // for (int i = 0; i < enemies->size(); i++)
    //   delete enemies->at(i);
    delete enemies;
  }

  if (locations != NULL)
  {
    // for (int i = 0; i < locations->size(); i++)
    //   delete locations->at(i);
    delete locations;
  }

  delete militaryState;
}

CountryState *CountryState::clone()
{
  return new CountryState(*this);
}

MilitaryState *CountryState::getMilitaryState()
{
  return militaryState;
}

void CountryState::setMilitaryState(MilitaryState *_militaryState)
{
  if (militaryState != NULL)
    delete militaryState;
  militaryState = _militaryState;
}
