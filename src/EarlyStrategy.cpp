
#include "EarlyStrategy.h"
#include "Country.h"
#include <iostream>

EarlyStrategy::EarlyStrategy() 
{

}

EarlyStrategy::~EarlyStrategy() 
{
  
}

// void EarlyStrategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB) 
// {
//   double powerBalance = strengthRatings[0] - strengthRatings[1];
//   if (powerBalance < -0.5) 
//     negotiate(countryA, countryB);
//   if (powerBalance < 0.5 && powerBalance > -0.5) 
//     taxImports(countryA, countryB);
//   if (powerBalance > 0.5) 
//     banImports(countryA, countryB);
// }

void EarlyStrategy::defensiveMove(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::negotiate selected" << std::endl;
  double randomOutcome = (double)rand() / (double)RAND_MAX;
  // CountryA chance of success : 0.3
  // CountryB chance of success : 0.7
  if (randomOutcome <= 0.3) // the negotiation has succeeded in easing tension
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
  // CountryB feels antagonised by CountryA, reacts with aggression
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
  if (randomOutcome <= 0.5) // CountryB learns its lesson, the measure was a success
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
  // CountryB feels a line has been crossed, reacts with aggression
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
  if (randomOutcome <= 0.7) // CountryB learns its lesson, the measure was a success
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
  // CountryB feels a line has been crossed, reacts with aggression
  countryA->setPoliticalStability(countryA->getPoliticalStability() * 0.9);
  countryA->setDomesticMorale(countryA->getDomesticMorale() * 0.9);
  countryA->setBorderStrength(countryA->getBorderStrength() * 0.95);
  countryA->setCapitalSafety(countryA->getCapitalSafety() * 0.95);
  countryA->setWarSentiment(countryA->getWarSentiment() * 0.95);
  countryA->setTradeRouteSafety(countryA->getTradeRouteSafety() * 0.95);
}