#ifndef MN_STRATEGY
#define MN_STRATEGY

#include "Strategy.h"

class Country;

class MiddleNeutralStrategy : public Strategy
{

public:
    MiddleNeutralStrategy();
    ~MiddleNeutralStrategy();
    void takeTurn(Country* countryB);
};

#endif