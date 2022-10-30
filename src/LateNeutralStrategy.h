#ifndef LN_STRATEGY
#define LN_STRATEGY

#include "Strategy.h"

class Country;

class LateNeutralStrategy : public Strategy
{
public:
    LateNeutralStrategy();
    ~LateNeutralStrategy();
    virtual void takeTurn(Country* countryB);
};

#endif