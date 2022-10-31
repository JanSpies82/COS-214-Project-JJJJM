#ifndef EARLY_STRATEGY_H
#define EARLY_STRATEGY_H

#include "Strategy.h"

class EarlyStrategy : public Strategy
{
public:
  EarlyStrategy();
  virtual ~EarlyStrategy();
  virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);
  void implementDefense(double* strengthRatings, Country* countryA, Country* countryB);
  void implementNeutral(double* strengthRatings, Country* countryA, Country* countryB);
  void implementOffense(double* strengthRatings, Country* countryA, Country* countryB);

};

#endif // EARLY_STRATEGY_H