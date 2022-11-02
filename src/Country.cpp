/// @author Jake Weatherhead

#include "Country.h"
#include "WarStage.h"
#include "Superpower.h"
#include "Military.h"
#include "MilitaryState.h"
#include "CountryState.h"
#include "CountryMediator.h"
#include "EarlyStrategy.h"
#include "MiddleStrategy.h"
#include "LateStrategy.h"
#include "Strategy.h"

#include <stdexcept>

///////////////////////////////////////////////////////////
// Country()
///////////////////////////////////////////////////////////

Country::Country()
{
}

///////////////////////////////////////////////////////////
// ~Country()
///////////////////////////////////////////////////////////

Country::~Country()
{
}

///////////////////////////////////////////////////////////
// Country(CountryState* cs, MilitaryState* ms)
///////////////////////////////////////////////////////////

Country::Country(std::string _name)
{
  name = _name;
}

///////////////////////////////////////////////////////////
// takeTurn()
///////////////////////////////////////////////////////////

void Country::takeTurn(Country *countryB)
{
  // setStrategy();
  // double strengthRatings[2];
  // getCountryRating(countryB, strengthRatings);
  // strategy->takeTurn(strengthRatings, this, countryB);
}

///////////////////////////////////////////////////////////
// setWarStage()
///////////////////////////////////////////////////////////

// void Country::setStrategy()
// {
//   delete strategy;
//   strategy = NULL;

//   if (getTurnCount() < 5)
//     strategy = new EarlyStrategy();
//   if (getTurnCount() < 15)
//     strategy = new MiddleStrategy();
//   if (getTurnCount() <= 20)
//     strategy = new LateStrategy();
// }

///////////////////////////////////////////////////////////
// getState()
///////////////////////////////////////////////////////////

CountryState *Country::getState()
{
  return countryState;
}

///////////////////////////////////////////////////////////
// getNumCitizens()
///////////////////////////////////////////////////////////

int Country::getNumCitizens()
{
  return numCitizens;
}

///////////////////////////////////////////////////////////
// setNumCitizens()
///////////////////////////////////////////////////////////

void Country::setNumCitizens(int _numCitizens)
{
  numCitizens = _numCitizens;
}

///////////////////////////////////////////////////////////
// getCountryRating()
///////////////////////////////////////////////////////////

void Country::getCountryRating(Country *b, double *strengthRatings)
{
  std::vector<double> strengthScoresA;
  std::vector<double> strengthScoresB;
  std::vector<double> aspectScores;

  compareMilitary(this, b, &aspectScores); // get CountryA's military strength scores
  for (double score : aspectScores)
    strengthScoresA.push_back(score);

  compareMilitary(b, this, &aspectScores); // get CountryB's military strength scores
  for (double score : aspectScores)
    strengthScoresB.push_back(score);

  compareDomestic(this, b, &aspectScores); // get CountryA's domestic strength scores
  for (double score : aspectScores)
    strengthScoresA.push_back(score);

  compareDomestic(b, this, &aspectScores); // get CountryB's domestic strength scores
  for (double score : aspectScores)
    strengthScoresB.push_back(score);

  double strengthA = 0.0;  
  for (double score : strengthScoresA)
    strengthA += score;
  strengthA /= strengthScoresA.size(); // CountryA's overall strength

  double strengthB = 0.0; 
  for (double score : strengthScoresB)
    strengthB += score;
  strengthB /= strengthScoresB.size(); // CountryB's overall strength

  strengthRatings[0] = strengthA;
  strengthRatings[1] = strengthB;
}

///////////////////////////////////////////////////////////
// compareMilitary()
///////////////////////////////////////////////////////////

void Country::compareMilitary(Country* a, Country* b, std::vector<double>* aspectScores)
{
  MilitaryState* mA = a->countryState->getMilitaryState();
  MilitaryState* mB = b->countryState->getMilitaryState();
  (*aspectScores).push_back(compareAspect(mA->getNumTroops(), mB->getNumTroops()));
  (*aspectScores).push_back(compareAspect(mA->getNumTanks(), mB->getNumTanks()));
  (*aspectScores).push_back(compareAspect(mA->getNumPlanes(), mB->getNumPlanes()));
  (*aspectScores).push_back(compareAspect(mA->getNumShips(), mB->getNumShips()));
}

///////////////////////////////////////////////////////////
// compareDomestic(Country)
///////////////////////////////////////////////////////////

void Country::compareDomestic(Country* a, Country* b, std::vector<double>* aspectScores)
{
  (*aspectScores).push_back(compareAspect(a->getPoliticalStability(), b->getPoliticalStability()));
  (*aspectScores).push_back(compareAspect(a->getDomesticMorale(), b->getDomesticMorale()));
  (*aspectScores).push_back(compareAspect(a->getBorderStrength(), b->getBorderStrength()));
  (*aspectScores).push_back(compareAspect(a->getCapitalSafety(), b->getCapitalSafety()));
  (*aspectScores).push_back(compareAspect(a->getWarSentiment(), b->getWarSentiment()));
  (*aspectScores).push_back(compareAspect(a->getTradeRouteSafety(), b->getTradeRouteSafety()));
}

///////////////////////////////////////////////////////////
// compareAspect(int, int)
///////////////////////////////////////////////////////////

double Country::compareAspect(int countryA, int countryB)
{
  return countryA / countryB;
}

///////////////////////////////////////////////////////////
// compareAspect(double, double)
///////////////////////////////////////////////////////////

double Country::compareAspect(double countryA, double countryB)
{
  return countryA / countryB;
}

///////////////////////////////////////////////////////////
// getPoliticalStability()
///////////////////////////////////////////////////////////

double Country::getPoliticalStability()
{
  return politicalStability;
}

///////////////////////////////////////////////////////////
// setPoliticalStability()
///////////////////////////////////////////////////////////

void Country::setPoliticalStability(double _politicalStability)
{
  if (_politicalStability < 0)
  {
    throw std::invalid_argument("_politicalStability must be greater than 0");
    return;
  }
  politicalStability = _politicalStability;
}

///////////////////////////////////////////////////////////
// getDomesticMorale()
///////////////////////////////////////////////////////////

double Country::getDomesticMorale()
{
  return domesticMorale;
}

///////////////////////////////////////////////////////////
// setDomesticMorale()
///////////////////////////////////////////////////////////

void Country::setDomesticMorale(double _domesticMorale)
{
  if (_domesticMorale < 0)
  {
    throw std::invalid_argument("_domesticMorale must be greater than 0");
    return;
  }
  domesticMorale = _domesticMorale;
}

///////////////////////////////////////////////////////////
// getSelfReliance()
///////////////////////////////////////////////////////////

double Country::getSelfReliance()
{
  return selfReliance;
}

///////////////////////////////////////////////////////////
// setSelfReliance()
///////////////////////////////////////////////////////////

void Country::setSelfReliance(double _selfReliance)
{
  if (_selfReliance < 0)
  {
    throw std::invalid_argument("_selfReliance must be greater than 0");
    return;
  }
  selfReliance = _selfReliance;
}

///////////////////////////////////////////////////////////
// getBorderStrength()
///////////////////////////////////////////////////////////

double Country::getBorderStrength()
{
  return borderStrength;
}

///////////////////////////////////////////////////////////
// setBorderStrength()
///////////////////////////////////////////////////////////

void Country::setBorderStrength(double _borderStrength)
{
  if (_borderStrength < 0)
  {
    throw std::invalid_argument("_borderStrength must be greater than 0");
    return;
  }
  borderStrength = _borderStrength;
}

///////////////////////////////////////////////////////////
// getCapitalSafety()
///////////////////////////////////////////////////////////

double Country::getCapitalSafety()
{
  return capitalSafety;
}

///////////////////////////////////////////////////////////
// setCapitalSafety()
///////////////////////////////////////////////////////////

void Country::setCapitalSafety(double _capitalSafety)
{
  if (_capitalSafety < 0)
  {
    throw std::invalid_argument("_capitalSafety must be greater than 0");
    return;
  }
  capitalSafety = _capitalSafety;
}

///////////////////////////////////////////////////////////
// getWarSentiment()
///////////////////////////////////////////////////////////

double Country::getWarSentiment()
{
  return warSentiment;
}

///////////////////////////////////////////////////////////
// setWarSentiment()
///////////////////////////////////////////////////////////

void Country::setWarSentiment(double _warSentiment)
{
  if (_warSentiment < 0)
  {
    throw std::invalid_argument("_warSentiment must be greater than 0");
    return;
  }
  warSentiment = _warSentiment;
}

///////////////////////////////////////////////////////////
// getTradeRouteSafety()
///////////////////////////////////////////////////////////

double Country::getTradeRouteSafety()
{
  return tradeRouteSafety;
}

///////////////////////////////////////////////////////////
// setTradeRouteSafety()
///////////////////////////////////////////////////////////

void Country::setTradeRouteSafety(double _tradeRouteSafety)
{
  if (_tradeRouteSafety < 0)
  {
    throw std::invalid_argument("_tradeRouteSafety must be greater than 0");
    return;
  }
  tradeRouteSafety = _tradeRouteSafety;
}

///////////////////////////////////////////////////////////
// getCountryState()
///////////////////////////////////////////////////////////

CountryState *Country::getCountryState()
{
  return countryState;
}

///////////////////////////////////////////////////////////
// setCountryState()
///////////////////////////////////////////////////////////

void Country::setCountryState(CountryState *_countryState)
{
  countryState = _countryState;
}

///////////////////////////////////////////////////////////
// getCountryName()
///////////////////////////////////////////////////////////

std::string Country::getName()
{
  return name;
};

///////////////////////////////////////////////////////////
// getMilitary()
///////////////////////////////////////////////////////////

Military *Country::getMilitary()
{
  return military;
}

///////////////////////////////////////////////////////////
// getCapital()
///////////////////////////////////////////////////////////

Location* Country::getCapital()
{
  return capital;
}

///////////////////////////////////////////////////////////
// setCapital(Location*)
///////////////////////////////////////////////////////////

void Country::setCapital(Location* _capital)
{
  capital = _capital;
}

///////////////////////////////////////////////////////////
// setLocations(std::vector<Location*>*)
///////////////////////////////////////////////////////////

void Country::setLocations(std::vector<Location*>* _locations)
{
  locations = _locations;
}