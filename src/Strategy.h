#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"

class Country;
class Strategy;

//! Strategy Class
/*!
 * This class determines which strategy to choose for a country.
 */

__abstract class Strategy
{
    public: Strategy(Country* country);
    /**
     * @brief Constructor: initialises Country variable
     *
     * @param country :Country* - The country that is to be linked to this strategy
     */

	public: Country* countrys; /*!< Holds country in which the strategy belongs to */

	public: virtual void algorithm() = 0;
    /**
     * @brief virtual function: Compares strength score to other countries and changes the strategy within a country accordingly
     */
};

#endif
