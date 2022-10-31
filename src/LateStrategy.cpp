#include "LateStrategy.h"
#include "Country.h"

#include <iostream>

void LateStrategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB) 
{
  double powerBalance = strengthRatings[0] - strengthRatings[1];
  if (powerBalance < -0.5) 
    surrender(countryA, countryB);
  if (powerBalance < 0.5 && powerBalance > -0.5) 
    launchAttacks(countryA, countryB);
  if (powerBalance > 0.5) 
    occupyCapital(countryA, countryB);
}

void LateStrategy::surrender(Country* countryA, Country* countryB) 
{
  std::cout << "LateStrategy::surrender selected" << std::endl;

}

void LateStrategy::launchAttacks(Country* countryA, Country* countryB) 
{
  std::cout << "LateStrategy::launchAttack selected" << std::endl;


  double responseCountryB = (double)rand() / (double)RAND_MAX;
  if (responseCountryB >= 0.5) // countryB responds negatively
  {
    countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
    countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
    countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
    countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
    countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
    countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);
    // no effect to countryA's selfReliance
  }
}

void LateStrategy::occupyCapital(Country* countryA, Country* countryB) 
{
  std::cout << "LateStrategy::occupyCapital selected" << std::endl;

}