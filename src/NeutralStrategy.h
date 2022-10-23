#include <exception>
using namespace std;

#ifndef __NeutralStrategy_h__
#define __NeutralStrategy_h__

#include "Strategy.h"

// class Strategy;
class NeutralStrategy;
//! NuetralStrategy Class
/*!
 * This class determines the decisions that a country makes with the goal of not participating in war
 */

class NeutralStrategy: public Strategy
{

	public: void algorithm();
    /**
     * @brief Implementes virtual algorithm: Decides on countries next move with the goal of neither being offensive/defensive, but instead not participate in war
     */
};

#endif
