#ifndef LD_STRATEGY
#define LD_STRATEGY

#include "Strategy.h"

class Country;

class LateDefensiveStrategy : public Strategy
{
public:
    LateDefensiveStrategy();
    ~LateDefensiveStrategy();
    virtual void takeTurn(Country* countryB);
};

#endif