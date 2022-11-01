
#include "EarlyStrategy.h"
#include "Country.h"
#include <iostream>

EarlyStrategy::EarlyStrategy() 
{

}

EarlyStrategy::~EarlyStrategy() 
{
  
}

void EarlyStrategy::defensiveMove(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::negotiate selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // CountryA wins
  {
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.9);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.9);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.9);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.9);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.9);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.9);
    return;
  }
  // CountryB wins
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);
}

void EarlyStrategy::neutralMove(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::taxImports selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA wins
  {
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.9);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.9);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.9);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.9);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.9);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.9);
    return;
  }
  // CountryB wins
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);

  countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.65);
  countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.65);
  countryB->setBorderStrength(countryB->getBorderStrength() * 0.65);
  countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.65);
  countryB->setWarSentiment(countryB->getWarSentiment() * 0.65);
  countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.65);
}

void EarlyStrategy::offensiveMove(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::banImports selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA wins
  {
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95); 

    countryB->setPoliticalStability(countryB->getPoliticalStability() * 0.9);
    countryB->setDomesticMorale(countryB->getDomesticMorale() * 0.9);
    countryB->setBorderStrength(countryB->getBorderStrength() * 0.9);
    countryB->setCapitalSafety(countryB->getCapitalSafety() * 0.9);
    countryB->setWarSentiment(countryB->getWarSentiment() * 0.9);
    countryB->setTradeRouteSafety(countryB->getTradeRouteSafety() * 0.9);
    return;
  }
  // CountryB wins
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);
}