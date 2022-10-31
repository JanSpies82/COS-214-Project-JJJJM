#ifndef LATE_STRATEGY_H
#define LATE_STRATEGY_H

#include "Strategy.h"

class LateStrategy : public Strategy
{
public:
    LateStrategy();
    virtual ~LateStrategy();
    virtual void takeTurn(double* strengthRatings);
    void implementDefense(double* strengthRatings, Country* countryA, Country* countryB);
    void implementNeutral(double* strengthRatings, Country* countryA, Country* countryB);
    void implementOffense(double* strengthRatings, Country* countryA, Country* countryB);
};

#endif // LATE_STRATEGY_H