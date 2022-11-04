///@author Mekhail Muller

#include "MiddleStrategy.h"
#include "Country.h"
#include "CountryState.h"
#include "MilitaryState.h"

MiddleStrategy::MiddleStrategy() {}

MiddleStrategy::~MiddleStrategy() {}

void MiddleStrategy::defensiveMove(Country *countryA, Country *countryB)
{
  std::cout << "MiddleStrategy::defensiveMove selected" << std::endl;
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.8), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.8), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.8), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.8), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.8), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.6), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.6), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.6), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.6), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.6), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.6), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.6), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.6), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.6), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.6), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.8), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.8), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.8), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.8), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.8), false);
}

void MiddleStrategy::neutralMove(Country *countryA, Country *countryB)
{
  std::cout << "MiddleStrategy::neutralMove selected" << std::endl;
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.8), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.8), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.8), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.8), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.8), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.5), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.5), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.5), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.5), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.5), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.5), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.5), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.5), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.5), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.5), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.8), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.8), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.8), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.8), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.8), false);
}

void MiddleStrategy::offensiveMove(Country *countryA, Country *countryB)
{
  std::cout << "MiddleStrategy::neutralMove selected" << std::endl;
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.7), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.7), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.7), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.7), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.7), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.8), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.1), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.1), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.1), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.1), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.1), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.1), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.1), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.1), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.1), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.8), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.8), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.8), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.8), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.8), false);
}
