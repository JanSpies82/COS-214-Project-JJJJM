#include "LateStrategy.h"
#include "Country.h"

#include <iostream>

void LateStrategy::defensiveMove(Country* countryA, Country* countryB) 
{
  // countryA surrenders and loses war
  countryA->setPoliticalStability(0);
  countryA->setDomesticMorale(0);
  countryA->setBorderStrength(0);
  countryA->setCapitalSafety(0);
  countryA->setWarSentiment(0);
  countryA->setTradeRouteSafety(0); 

  // Update CountryA's MilitaryState
  
}

void LateStrategy::neutralMove(Country* countryA, Country* countryB) 
{
  std::cout << "LateStrategy::launchAttacks selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.6);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.6);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.65);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.65);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.65);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.65); 

    // Update CountryA's MilitaryState

    // Update CountryB's CountryState
    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.15);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.15);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.15);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.15);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.15);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.15);

    // Update CountryB's MilitaryState
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.1);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.1);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.15);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.15);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.15);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.15);

  // Update CountryA's MilitaryState

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);

  // Update CountryB's MilitaryState
}

void LateStrategy::offensiveMove(Country* countryA, Country* countryB) 
{
  std::cout << "LateStrategy::occupyCapital selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins turn
  {
    // Update CountryA's CountryState
    countryB->setPoliticalStability(0);
    countryB->setDomesticMorale(0);
    countryB->setBorderStrength(0);
    countryB->setCapitalSafety(0);
    countryB->setWarSentiment(0);
    countryB->setTradeRouteSafety(0);

    // Update CountryA's MilitaryState
    return;
  }
  // CountryB wins turn
  // Update CountryA's CountryState
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.4);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.4);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.4);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.4);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.4);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.4);

  // Update CountryA's MilitaryState

  // Update CountryB's CountryState
  countryB->setPoliticalStability(countryB->getPoliticalStability() * 1.01);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 1.01);
  countryB->setBorderStrength(countryB->getBorderStrength() * 1.01);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 1.01);
  countryB->setWarSentiment(countryB->getWarSentiment() * 1.01);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 1.01);

  // Update CountryB's MilitaryState

}