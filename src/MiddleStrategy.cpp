///@author Mekhail Muller

#include "MiddleStrategy.h"
#include "Country.h"
#include "CountryState.h"
#include "MilitaryState.h"

const std::string RESET = "\x1B[0m";

MiddleStrategy::MiddleStrategy() {}

MiddleStrategy::~MiddleStrategy() {}

void MiddleStrategy::defensiveMove(Country *countryA, Country *countryB)
{
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // CountryA wins turn
  {
    std::cout << "(MiddleStrategy) " << countryA->getColor()
              << countryA->getName() << RESET << " implemented defensiveMove against "
              << countryB->getColor() << countryB->getName() << RESET << " and won\n";

    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.99);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.99);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.99);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.99);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.99);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.99);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.01), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.01), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.01), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.01), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.01), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.75);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.75);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.75);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.75);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.75);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.75);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.2), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.2), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.2), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.2), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.2), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  std::cout << "(MiddleStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << " implemented defensiveMove against "
            << countryB->getColor() << countryB->getName() << RESET << " and lost\n";

  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.75);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.75);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.75);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.75);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.75);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.75);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.2), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.2), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.2), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.2), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.2), false);

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

void MiddleStrategy::neutralMove(Country *countryA, Country *countryB)
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
    std::cout << "(MiddleStrategy) " << countryA->getColor()
              << countryA->getName() << RESET << " implemented neutralMove against "
              << countryB->getColor() << countryB->getName() << RESET << " and won\n";

    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.01), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.01), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.01), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.01), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.01), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.75);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.75);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.75);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.75);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.75);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.75);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.02), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.02), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.02), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.02), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.02), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  std::cout << "(MiddleStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << " implemented neutralMove against "
            << countryB->getColor() << countryB->getName() << RESET << " and lost\n";

  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.8);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.8);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.8);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.8);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.8);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.8);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.08), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.08), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.08), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.08), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.08), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.95);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.95);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.95);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.95);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.95);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.95);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.01), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.01), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.01), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.01), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.01), false);
}

void MiddleStrategy::offensiveMove(Country *countryA, Country *countryB)
{
  MilitaryState *mA = countryA->getCountryState()->getMilitaryState();
  MilitaryState *mB = countryB->getCountryState()->getMilitaryState();
  srand((unsigned)time(NULL)); // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins turn
  {
    // Update CountryA's CountryState
    std::cout << "(MiddleStrategy) " << countryA->getColor()
              << countryA->getName() << RESET << " implemented offensiveMove against "
              << countryB->getColor() << countryB->getName() << RESET << " and won\n";

    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

    // Update CountryA's MilitaryState
    mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.07), false);
    mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.07), false);
    mA->updateNumShips(floor(mA->getNumShips() * 0.07), false);
    mA->updateNumTanks(floor(mA->getNumTanks() * 0.07), false);
    mA->updateNumTroops(floor(mA->getNumTroops() * 0.07), false);

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.75);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.75);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.75);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.75);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.75);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.75);

    // Update CountryB's MilitaryState
    mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.12), false);
    mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.12), false);
    mB->updateNumShips(floor(mB->getNumShips() * 0.12), false);
    mB->updateNumTanks(floor(mB->getNumTanks() * 0.12), false);
    mB->updateNumTroops(floor(mB->getNumTroops() * 0.12), false);
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  std::cout << "(MiddleStrategy) " << countryA->getColor()
            << countryA->getName() << RESET << " implemented offensiveMove against "
            << countryB->getColor() << countryB->getName() << RESET << " and lost\n";
            
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.75);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.75);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.75);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.75);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.75);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.75);

  // Update CountryA's MilitaryState
  mA->updateNumBattalions(floor(mA->getNumBattalions() * 0.1), false);
  mA->updateNumPlanes(floor(mA->getNumPlanes() * 0.1), false);
  mA->updateNumShips(floor(mA->getNumShips() * 0.1), false);
  mA->updateNumTanks(floor(mA->getNumTanks() * 0.1), false);
  mA->updateNumTroops(floor(mA->getNumTroops() * 0.1), false);

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.9);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.9);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.9);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.9);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.9);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.9);

  // Update CountryB's MilitaryState
  mB->updateNumBattalions(floor(mB->getNumBattalions() * 0.02), false);
  mB->updateNumPlanes(floor(mB->getNumPlanes() * 0.02), false);
  mB->updateNumShips(floor(mB->getNumShips() * 0.02), false);
  mB->updateNumTanks(floor(mB->getNumTanks() * 0.02), false);
  mB->updateNumTroops(floor(mB->getNumTroops() * 0.02), false);
}
