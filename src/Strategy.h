#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"

class Country;

//! Strategy Class
/*!
 * This class determines the decisions that a country makes.
 */

class Strategy
{
    /**
     * @brief Constructor: initialises Country variable
     */
public:
    Strategy(Country *);

    /**
     * @brief virtual function: Decides on countries next move
     */
    virtual void algorithm() = 0;

protected:
    // TODO what is the purpose of this? The country can pass itself in as a parameter in algorithm() and does not need to be stored?
    Country *country; /*!< Holds country in which the strategy belongs to */
};

#endif
