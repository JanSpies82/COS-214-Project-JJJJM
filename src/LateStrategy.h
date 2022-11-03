///@author Mekhail Muller

#ifndef LATE_STRATEGY_H
#define LATE_STRATEGY_H

#include "Strategy.h"

class LateStrategy : public Strategy
{
public:
    LateStrategy();

    /**
      * @brief destructor
      */
    ~LateStrategy();

protected:
    /**
      * @brief virtual function representing the implementation of a turn 
      * when Country A is weaker than Country B
      * 
      * @param countryA the country that is making the move (calling country)
      * @param countryB the country being attacked by calling country
      */
    void defensiveMove(Country* countryA, Country* countryB);

    /**
      * @brief virtual function representing the implementation of a turn 
      * when Country A and Country B are similar in strength
      * 
      * @param countryA the country that is making the move (calling country)
      * @param countryB the country being attacked by calling country
      */
    void neutralMove(Country* countryA, Country* countryB);

    /**
      * @brief virtual function representing the implementation of a turn 
      * when Country A is stronger than Country B
      * 
      * @param countryA the country that is making the move (calling country)
      * @param countryB the country being attacked by calling country
      */
    void offensiveMove(Country* countryA, Country* countryB);
};

#endif // LATE_STRATEGY_H