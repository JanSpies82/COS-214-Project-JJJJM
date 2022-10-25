#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"

class Country;

//! Strategy Class
/*!
 * This class determines which strategy to choose for a country.
 */

class Strategy
{
    public:
    /**
     * @brief Constructor: initialises Country variable
     *
     * @param country :Country* - The country that is to be linked to this strategy
     */

    Strategy(Country *);

    /**
     * @brief virtual function: Compares strength score to other countries and changes the strategy within a country accordingly
     *
     * @param _country:Country* Country that must be compared to everyone else
     */
    virtual void algorithm(Country * _country) = 0;
};

#endif
