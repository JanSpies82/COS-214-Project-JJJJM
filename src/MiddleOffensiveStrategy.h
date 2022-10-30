#ifndef MO_STRATEGY
#define MO_STRATEGY

#include "Strategy.h"

class MiddleOffensiveStrategy : public Strategy
{
public:
    MiddleOffensiveStrategy();
    ~MiddleOffensiveStrategy();
    void takeTurn(Country* countryB);
};

#endif