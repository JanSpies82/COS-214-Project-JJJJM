#ifndef EO_STRATEGY
#define EO_STRATEGY

#include "Strategy.h"

class Country;

class EarlyOffensiveStrategy : public Strategy
{
public:
    EarlyOffensiveStrategy();
    ~EarlyOffensiveStrategy();
    virtual void takeTurn(Country* countryB);
};


#endif