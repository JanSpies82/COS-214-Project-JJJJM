
#include "EarlyStrategy.h"
#include <iostream>

EarlyStrategy::EarlyStrategy() 
{

}

EarlyStrategy::~EarlyStrategy() 
{

}

void EarlyStrategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB) 
{
  double powerBalance = strengthRatings[0] - strengthRatings[1];
  if (powerBalance < -0.5) 
    negotiate(countryA, countryB);
  if (powerBalance < 0.5 && powerBalance > -0.5) 
    taxImports(countryA, countryB);
  if (powerBalance > 0.5) 
    banImports(countryA, countryB);
}

void EarlyStrategy::negotiate(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::negotiate selected" << std::endl;

}

void EarlyStrategy::taxImports(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::taxImports selected" << std::endl;

}

void EarlyStrategy::banImports(Country* countryA, Country* countryB) 
{
  std::cout << "EarlyStrategy::banImports selected" << std::endl;
}