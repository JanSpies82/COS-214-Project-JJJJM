#ifndef MO_STRATEGY
#define MO_STRATEGY

#include "Strategy.h"

class MiddleOffensiveStrategy : public Strategy
{
public:
    MiddleOffensiveStrategy();
    ~MiddleOffensiveStrategy();
    virtual void takeTurn(Country* countryB);
};

#endif