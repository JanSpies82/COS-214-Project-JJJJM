#ifndef MD_STRATEGY
#define MD_STRATEGY

#include "Strategy.h"

class Country;

class MiddleDefensiveStrategy : public Strategy
{
public:
    MiddleDefensiveStrategy();
    ~MiddleDefensiveStrategy();
    void takeTurn(Country* countryB);
};

#endif