#include <exception>
using namespace std;

#ifndef __OffensiveStrategy_h__
#define __OffensiveStrategy_h__

#include "Strategy.h"

// class Strategy;

class OffensiveStrategy;

//! OffensiveStrategy Class
/*!
 * This class determines the decisions that a country makes with the goal of being aggresive.
 */


class OffensiveStrategy: public Strategy
{

	public: void algorithm();
    /**
     * @brief Implements virtual algorithm function: Decides on countries next move with the goal of attacking the enemy
     */
};

#endif
