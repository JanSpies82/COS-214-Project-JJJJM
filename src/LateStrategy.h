#ifndef LATE_STRATEGY_H
#define LATE_STRATEGY_H

#include "Strategy.h"

class LateStrategy : public Strategy
{
public:
    LateStrategy();
    virtual ~LateStrategy();
    virtual void takeTurn(double* strengthRatings);
};

#endif // LATE_STRATEGY_H