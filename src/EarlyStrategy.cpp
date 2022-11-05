///@author Mekhail Muller

#include "EarlyStrategy.h"
#include "CountryState.h"
#include "MilitaryState.h"
#include "Country.h"

EarlyStrategy::EarlyStrategy(){}

EarlyStrategy::~EarlyStrategy(){}

void EarlyStrategy::defensiveMove(Country* countryA, Country* countryB) 
{
  srand((unsigned) time(NULL));  // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.99);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.99);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.99);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.99);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.99);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.99); 

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.95);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.95);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.95);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.95);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.95);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.95);

    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.95);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.95);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.99);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.99);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.99);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.99);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.99);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.99);

}

void EarlyStrategy::neutralMove(Country* countryA, Country* countryB) 
{
  srand((unsigned) time(NULL));  // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.99);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.99);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.99);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.99);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.99);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.99); 

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.95);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.95);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.95);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.95);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.95);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.95);

    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.95);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.95);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.99);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.99);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.99);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.99);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.99);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.99);

}

void EarlyStrategy::offensiveMove(Country* countryA, Country* countryB) 
{
  srand((unsigned) time(NULL));  // seed rand
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.99);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.99);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.99);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.99);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.99);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.99); 

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.95);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.95);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.95);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.95);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.95);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.95);

    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.95);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.95);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.99);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.99);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.99);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.99);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.99);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.99);

}