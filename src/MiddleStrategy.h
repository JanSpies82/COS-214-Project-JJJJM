#ifndef MIDDLE_STRATEGY_H
#define MIDDLE_STRATEGY_H

#include "Strategy.h"

class MiddleStrategy : public Strategy
{
public:
    MiddleStrategy();
    virtual ~MiddleStrategy();
    virtual void takeTurn(double* strengthRatings);
};

#endif // MIDDLE_STRATEGY_H