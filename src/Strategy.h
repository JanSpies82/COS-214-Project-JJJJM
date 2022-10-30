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
     * @brief virtual function representing the implementation of a strategy.
     * 
     * @param countryB the country being attacked by calling country
     */
    virtual void takeTurn(Country* countryB) = 0;
};

#endif
