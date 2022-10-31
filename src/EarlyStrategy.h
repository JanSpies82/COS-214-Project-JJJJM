#ifndef EARLY_STRATEGY_H
#define EARLY_STRATEGY_H

#include "Strategy.h"

class EarlyStrategy : public Strategy
{
public:
  EarlyStrategy();
  virtual ~EarlyStrategy();
  virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);
  void negotiate(Country* countryA, Country* countryB);
  void taxImports(Country* countryA, Country* countryB);
  void banImports(Country* countryA, Country* countryB);

};

#endif // EARLY_STRATEGY_H