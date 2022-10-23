#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"

class Country;
class Strategy;

//! Strategy Class
/*!
 * This class determines the decisions that a country makes.
 */

__abstract class Strategy
{
    public: Strategy(Country*);
    /**
     * @brief Constructor: initialises Country variable
     */

	public: Country* countrys; /*!< Holds country in which the strategy belongs to */

	public: virtual void algorithm() = 0;
    /**
     * @brief virtual function: Decides on countries next move
     */
};

#endif
