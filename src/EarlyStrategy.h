#ifndef EARLY_STRATEGY_H
#define EARLY_STRATEGY_H

#include "Strategy.h"

class EarlyStrategy : public Strategy
{
public:
  EarlyStrategy();
  virtual ~EarlyStrategy();
  virtual void takeTurn(double strengthA, double strengthB);
};

#endif // EARLY_STRATEGY_H