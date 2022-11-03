///@author Mekhail Muller

#include "Strategy.h"
#include "Country.h"

Strategy::Strategy(){}

void Strategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB)
{
  double cmp = strengthRatings[0] - strengthRatings[1];
  if (cmp < -0.5)
    defensiveMove(countryA, countryB);
  if (cmp < 0.5 && cmp > -0.5)
    neutralMove(countryA, countryB);
  if (cmp > 0.5)
    offensiveMove(countryA, countryB);
}

