#include "MiddleStrategy.h"
#include "Country.h"

#include <iostream>

void MiddleStrategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB) 
{
  double powerBalance = strengthRatings[0] - strengthRatings[1];
  if (powerBalance < -0.5) 
    defendBorders(countryA, countryB);
  if (powerBalance < 0.5 && powerBalance > -0.5) 
    airstrikeCapital(countryA, countryB);
  if (powerBalance > 0.5) 
    launchInvasion(countryA, countryB);
}

void MiddleStrategy::defendBorders(Country* countryA, Country* countryB) 
{
  std::cout << "MiddleStrategy::defendBorders selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // CountryA successfully defended its border/s
  {
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
    return;
  }
  // CountryB attacked CountryA's border/s and won
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

void MiddleStrategy::airstrikeCapital(Country* countryA, Country* countryB) 
{
  std::cout << "MiddleStrategy::airstrikeCaptial selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.5
  // CountryB chance of success : 0.5
  if (randomOutcome <= 0.5) // CountryA successfully attacked CountryB's capital
  {
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
    return;
  }
  // CountryB stopped the neutralised countryA's airforce
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);
}

void MiddleStrategy::launchInvasion(Country* countryA, Country* countryB) 
{
  std::cout << "MiddleStrategy::launchInvasion selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.7
  // CountryB chance of success : 0.3
  if (randomOutcome <= 0.7) // CountryA successfully invaded CountryB
  {
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
    return;
  }
  // CountryB successfully defended its territory
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
