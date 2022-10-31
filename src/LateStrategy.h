#ifndef LATE_STRATEGY_H
#define LATE_STRATEGY_H

#include "Strategy.h"

class LateStrategy : public Strategy
{
public:
    LateStrategy();
    virtual ~LateStrategy();
    virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);
    void surrender(Country* countryA, Country* countryB);
    void launchAttacks(Country* countryA, Country* countryB);
    void occupyCapital(Country* countryA, Country* countryB);
};

#endif // LATE_STRATEGY_H