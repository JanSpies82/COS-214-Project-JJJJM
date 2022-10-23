#include <exception>
using namespace std;

#ifndef __DefensiveStrategy_h__
#define __DefensiveStrategy_h__

#include "Strategy.h"

// class Strategy;
class DefensiveStrategy;

//! DefensiveStrategy Class
/*!
 * This class determines the decisions that a country makes with the goal of defending the country
 */

class DefensiveStrategy: public Strategy
{

	public: void algorithm();
    /**
     * @brief Implements abstract function: Decides on countries next move with the goal of defending the country and its military
     */
};

#endif
