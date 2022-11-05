///@author Mekhail Muller

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"
#include <exception>

class Country;

/*!
 * This class determines which strategy to choose for a country.
 */

class Strategy
{
public:
  /**
   * @brief Constructor: initialises Country variable
   *
   */
  Strategy(); //Let strategy be reusable by not holding a country object

  /**
   * @brief virtual function representing the implementation of a strategy.
   * 
   * @param strengthRatings double array holding the strength values of the 2 countries
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  virtual void takeTurn(double* strengthRatings, Country* countryA, Country* countryB);

protected:
  /**
   * @brief virtual function representing the implementation of a turn when Country A is stronger than Country B
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  virtual void offensiveMove(Country* countryA, Country* countryB) = 0;

  /**
   * @brief virtual function representing the implementation of a turn when Country A has equal strength with Country B
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  virtual void neutralMove(Country* countryA, Country* countryB) = 0;

  /**
   * @brief virtual function representing the implementation of a turn when Country A is weaker than Country B
   * 
   * @param countryA the country that is making the move (calling country)
   * @param countryB the country being attacked by calling country
   */
  virtual void defensiveMove(Country* countryA, Country* countryB) = 0;



};

#endif
