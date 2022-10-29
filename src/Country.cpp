/// @author Jake Weatherhead

#include "Country.h"
#include "WarStage.h"
#include "Superpower.h"
#include "Military.h"
#include "CountryState.h"
#include "CountryMediator.h"
#include "Strategy.h"

///////////////////////////////////////////////////////////
// Country
///////////////////////////////////////////////////////////

Country::Country() 
{
}

///////////////////////////////////////////////////////////
// request
///////////////////////////////////////////////////////////

void Country::request()
{
	return;
}

///////////////////////////////////////////////////////////
// notify
///////////////////////////////////////////////////////////

void Country::notify()
{
	return;
}

///////////////////////////////////////////////////////////
// attach
///////////////////////////////////////////////////////////

void Country::attach()
{
	return;
}

///////////////////////////////////////////////////////////
// detach
///////////////////////////////////////////////////////////

void Country::detach()
{
	return;
}

///////////////////////////////////////////////////////////
// takeTurn
///////////////////////////////////////////////////////////

void Country::takeTurn()
{
	return;
}

///////////////////////////////////////////////////////////
// getState
///////////////////////////////////////////////////////////

CountryState* Country::getState()
{
  // generate current state
  // return current state
  return NULL;
}

///////////////////////////////////////////////////////////
// getNumCitizens
///////////////////////////////////////////////////////////

int Country::getNumCitizens()
{
  return numCitizens;
}

///////////////////////////////////////////////////////////
// setNumCitizens
///////////////////////////////////////////////////////////

void Country::setNumCitizens(int _numCitizens)
{
  numCitizens = _numCitizens;
}

///////////////////////////////////////////////////////////
// getMilitaryState
///////////////////////////////////////////////////////////

MilitaryState* Country::getMilitaryState()
{
  return militaryState;
}

///////////////////////////////////////////////////////////
// setMilitaryState
///////////////////////////////////////////////////////////

void Country::setMilitaryState(MilitaryState* _militaryState)
{
  militaryState = _militaryState;
}

///////////////////////////////////////////////////////////
// getMapState
///////////////////////////////////////////////////////////

MapState* Country::getMapState()
{
  return mapState;
}

///////////////////////////////////////////////////////////
// setMapState
///////////////////////////////////////////////////////////

void Country::setMapState(MapState* _mapState)
{
  mapState = _mapState;
}

///////////////////////////////////////////////////////////
// getCountryRating
///////////////////////////////////////////////////////////

double Country::getCountryRating(Country* enemy)
{
  std::vector<double> strengthScores;
  MilitaryState* thisMilitarystate = getMilitaryState();
  MilitaryState* enemyMilitaryState = enemy->getMilitaryState();

  return strengthRating;
}

///////////////////////////////////////////////////////////
// compareAspect(int, int)
///////////////////////////////////////////////////////////

double Country::compareAspect(int countryA, int countryB)
{

}

///////////////////////////////////////////////////////////
// compareAspect(double, double)
///////////////////////////////////////////////////////////

double Country::compareAspect(double countryA, double countryB)
{

}

double Country::getPoliticalStability()
{
  return politicalStability;
}

void Country::setPoliticalStability(double _politicalStability)
{
  if (_politicalStability < 0)
  {
    throw std::invalid_argument("_politicalStability must be greater than 0");
    return;
  }
  politicalStability = _politicalStability;
}

double Country::getDomesticMorale()
{
  return domesticMorale;
}

void Country::setDomesticMorale(double _domesticMorale)
{
  if (_domesticMorale < 0)
  {
    throw std::invalid_argument("_domesticMorale must be greater than 0");
    return;
  }
  domesticMorale = _domesticMorale;
}

double Country::getSelfReliance()
{
  return selfReliance;
}

void Country::setSelfReliance(double _selfReliance)
{
  if (_selfReliance < 0)
  {
    throw std::invalid_argument("_selfReliance must be greater than 0");
    return;
  }
  selfReliance = _selfReliance;
}

double Country::getBorderStrength() 
{
  return borderStrength;
}

void Country::setBorderStrength(double _borderStrength)
{
  if (_borderStrength < 0)
  {
    throw std::invalid_argument("_borderStrength must be greater than 0");
    return;
  }
  borderStrength = _borderStrength;
}

double Country::getCapitalSafety()
{
  return capitalSafety;
}

void Country::setCapitalSafety(double _capitalSafety)
{
  if (_capitalSafety < 0)
  {
    throw std::invalid_argument("_capitalSafety must be greater than 0");
    return;
  }
  capitalSafety = _capitalSafety;
}

double Country::getWarSentiment()
{
  return warSentiment;
}

void Country::setWarSentiment(double _warSentiment)
{
  if (_warSentiment < 0)
  {
    throw std::invalid_argument("_warSentiment must be greater than 0");
    return;
  }
  warSentiment = _warSentiment;
}

double Country::getTradeRouteSafety()
{
  return tradeRouteSafety;
}

void Country::setTradeRouteSafety(double _tradeRouteSafety)
{
  if (_tradeRouteSafety < 0)
  {
    throw std::invalid_argument("_tradeRouteSafety must be greater than 0");
    return;
  }
  tradeRouteSafety = _tradeRouteSafety;
}

MilitaryState* Country::getMilitaryState()
{
  return NULL;
}

MapState* Country::getMapState()
{
  return NULL;
}

CountryState* Country::getCountryState()
{
  return NULL;
}