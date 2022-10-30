#ifndef LO_STRATEGY
#define LO_STRATEGY

#include "Strategy.h"

class Country;

class LateOffensiveStrategy : public Strategy
{
public:
    LateOffensiveStrategy();
    ~LateOffensiveStrategy();
    void takeTurn(Country* countryB);
};

#endif