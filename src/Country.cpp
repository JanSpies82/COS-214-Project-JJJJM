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
#include "Location.h"

#include <stdexcept>

///////////////////////////////////////////////////////////
// Country()
///////////////////////////////////////////////////////////

// Country::Country()
// {
// }

///////////////////////////////////////////////////////////
// ~Country()
///////////////////////////////////////////////////////////

Country::~Country()
{
  if (countryState->locations != NULL)
    delete countryState->locations;
  if (countryState != NULL)
    delete countryState;
}

///////////////////////////////////////////////////////////
// Country(CountryState* cs, MilitaryState* ms)
///////////////////////////////////////////////////////////

Country::Country(std::string _name)
{
  countryState = new CountryState();
  countryState->name = _name;
  // countryState = NULL;  // @janco what did you have in mind when setting this to NULL? Setting it from outside?
  countryState->locations = NULL;
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
  if (countryState != NULL)
    delete countryState;
  countryState = new CountryState(this);
  return countryState;
}

///////////////////////////////////////////////////////////
// getNumCitizens()
///////////////////////////////////////////////////////////

int Country::getNumCitizens()
{
  return countryState->numCitizens;
}

///////////////////////////////////////////////////////////
// setNumCitizens()
///////////////////////////////////////////////////////////

void Country::setNumCitizens(int _numCitizens)
{
  countryState->numCitizens = _numCitizens;
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

void Country::compareMilitary(Country *a, Country *b, std::vector<double> *aspectScores)
{
  MilitaryState *mA = a->countryState->militaryState;
  MilitaryState *mB = b->countryState->militaryState;
  (*aspectScores).push_back(compareAspect(mA->getNumTroops(), mB->getNumTroops()));
  (*aspectScores).push_back(compareAspect(mA->getNumTanks(), mB->getNumTanks()));
  (*aspectScores).push_back(compareAspect(mA->getNumPlanes(), mB->getNumPlanes()));
  (*aspectScores).push_back(compareAspect(mA->getNumShips(), mB->getNumShips()));
}

///////////////////////////////////////////////////////////
// compareDomestic(Country)
///////////////////////////////////////////////////////////

void Country::compareDomestic(Country *a, Country *b, std::vector<double> *aspectScores)
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
  return countryState->politicalStability;
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
  countryState->politicalStability = _politicalStability;
}

///////////////////////////////////////////////////////////
// getDomesticMorale()
///////////////////////////////////////////////////////////

double Country::getDomesticMorale()
{
  return countryState->domesticMorale;
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
  countryState->domesticMorale = _domesticMorale;
}

///////////////////////////////////////////////////////////
// getSelfReliance()
///////////////////////////////////////////////////////////

double Country::getSelfReliance()
{
  return countryState->selfReliance;
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
  countryState->selfReliance = _selfReliance;
}

///////////////////////////////////////////////////////////
// getBorderStrength()
///////////////////////////////////////////////////////////

double Country::getBorderStrength()
{
  return countryState->borderStrength;
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
  countryState->borderStrength = _borderStrength;
}

///////////////////////////////////////////////////////////
// getCapitalSafety()
///////////////////////////////////////////////////////////

double Country::getCapitalSafety()
{
  return countryState->capitalSafety;
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
  countryState->capitalSafety = _capitalSafety;
}

///////////////////////////////////////////////////////////
// getWarSentiment()
///////////////////////////////////////////////////////////

double Country::getWarSentiment()
{
  return countryState->warSentiment;
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
  countryState->warSentiment = _warSentiment;
}

///////////////////////////////////////////////////////////
// getTradeRouteSafety()
///////////////////////////////////////////////////////////

double Country::getTradeRouteSafety()
{
  return countryState->tradeRouteSafety;
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
  countryState->tradeRouteSafety = _tradeRouteSafety;
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
// getName()
///////////////////////////////////////////////////////////

std::string Country::getName()
{
  return countryState->name;
}

///////////////////////////////////////////////////////////
// setName()
///////////////////////////////////////////////////////////

void Country::setName(std::string _name)
{
  countryState->name = _name;
}

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

Location *Country::getCapital()
{
  return countryState->capital;
}

///////////////////////////////////////////////////////////
// setCapital(Location*)
///////////////////////////////////////////////////////////

void Country::setCapital(Location *_capital)
{
  countryState->capital = _capital;
}

///////////////////////////////////////////////////////////
// setLocations(std::vector<Location*>*)
///////////////////////////////////////////////////////////

void Country::setLocations(std::vector<Location *> *_locations)
{
  countryState->locations = _locations;
  for (int i = 0; i < countryState->locations->size(); i++)
    if (!countryState->locations->at(i)->getIsCapital())
      countryState->locations->at(i)->setColor(countryState->color);//Set location to be the same color as country
    else
      countryState->locations->at(i)->setColor("\x1B[40m"); // Set capital color to black
}

///////////////////////////////////////////////////////////
// setColor(std::string _color)
///////////////////////////////////////////////////////////

void Country::setColor(std::string _color)
{
  countryState->color = _color;
}

///////////////////////////////////////////////////////////
// getColor()
///////////////////////////////////////////////////////////

std::string Country::getColor()
{
  return countryState->color;
}

///////////////////////////////////////////////////////////
// getMediator()
///////////////////////////////////////////////////////////

CountryMediator* Country::getMediator()
{
  return mediator;
}

///////////////////////////////////////////////////////////
// setMediator()
///////////////////////////////////////////////////////////

void Country::setMediator(CountryMediator* _mediator)
{
  if (mediator != NULL)
    delete mediator;
  mediator = _mediator;
}