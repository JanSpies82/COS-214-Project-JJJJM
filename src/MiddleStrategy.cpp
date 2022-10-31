#include "MiddleStrategy.h"
#include "Country.h"

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
  // countryB is unaffected by a negotitation with a weaker country

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
  // else no change to countryA's stats
}

void MiddleStrategy::airstrikeCapital(Country* countryA, Country* countryB) 
{

}

void MiddleStrategy::launchInvasion(Country* countryA, Country* countryB) 
{

}
