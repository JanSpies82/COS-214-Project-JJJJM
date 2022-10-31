#ifndef MIDDLE_STRATEGY_H
#define MIDDLE_STRATEGY_H

#include "Strategy.h"

class MiddleStrategy : public Strategy
{
public:
  MiddleStrategy();
  virtual ~MiddleStrategy();
  virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);
  void defendBorders(Country* countryA, Country* countryB);
  void airstrikeCapital(Country* countryA, Country* countryB);
  void launchInvasion(Country* countryA, Country* countryB);
};

#endif // MIDDLE_STRATEGY_H