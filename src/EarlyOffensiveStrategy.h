#ifndef EO_STRATEGY
#define EO_STRATEGY

#include "Strategy.h"

class Country;

class EarlyOffensiveStrategy : public Strategy
{
public:
    EarlyOffensiveStrategy();
    ~EarlyOffensiveStrategy();
    void takeTurn(Country* countryB);
};


#endif