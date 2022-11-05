///@author Mekhail Muller

#include "LateStrategy.h"
#include "Country.h"
#include "CountryState.h"
#include "MilitaryState.h"
#include <iostream>

const std::string RESET = "\x1B[0m";
const std::string BOLDRED = "\x1B[1;31m";
const std::string BOLDGREEN = "\x1B[1;32m";

LateStrategy::LateStrategy() {}

LateStrategy::~LateStrategy() {}

void LateStrategy::defensiveMove(Country *countryA, Country *countryB)
{
  // countryA surrenders and loses war
  std::cout << "(LateStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << BOLDRED << " surrendered " << RESET << " to "
            << countryB->getColor() << countryB->getName() << RESET << "\n";

  countryA->setPoliticalStability(0);
  countryA->setDomesticMorale(0);
  countryA->setBorderStrength(0);
  countryA->setCapitalSafety(0);
  countryA->setWarSentiment(0);
  countryA->setTradeRouteSafety(0);

  // Set all countryA, militaryState attributes to zero
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  mA->updateNumBattalions(mA->getNumBattalions(), false);
  mA->updateNumPlanes(mA->getNumPlanes(), false);
  mA->updateNumShips(mA->getNumShips(), false);
  mA->updateNumTanks(mA->getNumTanks(), false);
  mA->updateNumTroops(mA->getNumTroops(), false);
}

void LateStrategy::neutralMove(Country *countryA, Country *countryB)
{
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA wins turn
  {
    // Update CountryA's CountryState
    std::cout << "(LateStrategy) " << countryA->getColor()
              << countryA->getName() << RESET << BOLDGREEN << " won"
              << RESET << " neutralMove against "
              << countryB->getColor() << countryB->getName()
              << RESET << "\n";

    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.6);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.6);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.65);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.65);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.65);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.65);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.2), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.2), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.2), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.2), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.2), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.15);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.15);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.15);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.15);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.15);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.15);

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
  std::cout << "(LateStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << BOLDRED << " lost"
            << RESET << " neutralMove against "
            << countryB->getColor() << countryB->getName()
            << RESET << "\n";

  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.1);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.1);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.15);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.15);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.15);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.15);

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
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.2), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.2), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.2), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.2), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.2), false);
}

void LateStrategy::offensiveMove(Country *countryA, Country *countryB)
{
  std::cout << "LateStrategy::occupyCapital selected" << std::endl;
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins turn
  {
    // Update CountryA's CountryState
    std::cout << "(LateStrategy) " << countryA->getColor()
              << countryA->getName() << RESET << BOLDGREEN << " won"
              << RESET << " offensiveMove against "
              << countryB->getColor() << countryB->getName()
              << RESET << "\n";

    countryB->setPoliticalStability(0);
    countryB->setDomesticMorale(0);
    countryB->setBorderStrength(0);
    countryB->setCapitalSafety(0);
    countryB->setWarSentiment(0);
    countryB->setTradeRouteSafety(0);

    // Set all countryB, militaryState attributes to zero
    mB->updateNumBattalions(mB->getNumBattalions(), false);
    mB->updateNumPlanes(mB->getNumPlanes(), false);
    mB->updateNumShips(mB->getNumShips(), false);
    mB->updateNumTanks(mB->getNumTanks(), false);
    mB->updateNumTroops(mB->getNumTroops(), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  std::cout << "(LateStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << BOLDRED << " lost"
            << RESET << " offensiveMove against "
            << countryB->getColor() << countryB->getName()
            << RESET << "\n";

  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.4);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.4);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.4);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.4);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.4);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.4);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(mA->getNumBattalions(), false);
  mA->updateNumPlanes(mA->getNumPlanes(), false);
  mA->updateNumShips(mA->getNumShips(), false);
  mA->updateNumTanks(mA->getNumTanks(), false);
  mA->updateNumTroops(mA->getNumTroops(), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 1.01);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 1.01);
  countryB->setBorderStrength(countryB->getBorderStrength() * 1.01);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 1.01);
  countryB->setWarSentiment(countryB->getWarSentiment() * 1.01);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 1.01);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.6), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.6), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.6), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.6), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.6), false);
}