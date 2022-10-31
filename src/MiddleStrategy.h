#ifndef MIDDLE_STRATEGY_H
#define MIDDLE_STRATEGY_H

#include "Strategy.h"

class MiddleStrategy : public Strategy
{
public:
  /**
   * @brief Constructor
   */
  MiddleStrategy();

  /**
   * @brief destructor
   */
  ~MiddleStrategy();

  /**
   * @brief a decision function that determines the exact strategy to be used
   */
  virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);

  /**
   * @brief virtual function representing the implementation of a turn 
   * when Country A is weaker than Country B
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  void defendBorders(Country* countryA, Country* countryB);

  /**
   * @brief virtual function representing the implementation of a turn 
   * when Country A and Country B are similar in strength
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  void airstrikeCapital(Country* countryA, Country* countryB);

  /**
   * @brief virtual function representing the implementation of a turn 
   * when Country A is stronger than Country B
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  void launchInvasion(Country* countryA, Country* countryB);
};

#endif // MIDDLE_STRATEGY_H