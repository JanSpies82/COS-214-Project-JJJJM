#ifndef MIDDLE_STRATEGY_H
#define MIDDLE_STRATEGY_H

#include "Strategy.h"

class MiddleStrategy : public Strategy
{
public:
  MiddleStrategy();
  virtual ~MiddleStrategy();
  virtual void takeTurn(double* strengthRatings);
  void implementDefense(double* strengthRatings, Country* countryA, Country* countryB);
  void implementNeutral(double* strengthRatings, Country* countryA, Country* countryB);
  void implementOffense(double* strengthRatings, Country* countryA, Country* countryB);
};

#endif // MIDDLE_STRATEGY_H