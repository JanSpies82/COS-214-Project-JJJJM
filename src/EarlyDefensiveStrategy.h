#ifndef ED_STRATEGY
#define ED_STRATEGY

#include "Strategy.h"

class Country;

class EarlyDefensiveStrategy : public Strategy
{
public:
    EarlyDefensiveStrategy();
    ~EarlyDefensiveStrategy();
    virtual void takeTurn(Country* countryB);
};

#endif