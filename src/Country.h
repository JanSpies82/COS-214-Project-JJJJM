#include <exception>

#ifndef __Country_h__
#define __Country_h__

#include "WarStage.h"
// #include "Superpower.h"
// #include "Military.h"
// #include "CountryState.h"
// #include "Citizen.h"
// #include "CountryMediator.h"
// #include "Strategy.h"

#include <vector>

class WarStage;
class Superpower;
class Military;
class CountryState;
class Citizen;
class CountryMediator;
class Strategy;
class Country;
class MapState;

class Country
{
public: 
  /**
   * @brief  Default constructor
   */
  Country();
  /**
    * @brief takes next action in simulation based on current state
    */
  void request();

  /**
    * @brief notify each observer of the new current state
    */
  void notify();

  /**
    * @brief add new observer to vector of observers
    */
  void attach();
  
  /**
    * @brief remove observer from vector of observers
    */
  void detach();

  /**
    * @brief uses state information to implement next action
    */
  void algorithm();

  /**
    * @brief return up-to-date state information
    */
  CountryState* getState();

  /**
    * @brief generates a countries strength rating based on various state information
    * @return the strength rating of this country
    */
  double getCountryRating();

  /**
    * @brief generates a vector of military coefficients reflecting military strength
    * @return a vector of int coefficients
    */
  std::vector<int> getMilitaryCoefficients()
  {

  };

  /**
    * @brief generates a vector of map coefficients reflecting the strength
    * of this country's position on the map
    * @return a vector of int coefficients
    */
  std::vector<int> getMapCoefficients()
  {

  };

  /**
    * @brief generates a vector of domestic coefficients reflecting the internal strength
    * of this country
    * @return a vector of int coefficients
    */
  std::vector<int> getDomesticCoefficients()
  {

  };

  /**
    * @brief getter for numCitizens attribute
    * @return returns current number of citizens of this country
    */
  int getNumCitizens()
  {
    return numCitizens;
  };

  /**
   * @brief sets the value of class attribute numCitizens
   * @param int new value of numCitizens
   */
  void setNumCitizens(int _numCitizens)
  {
    if (_numCitizens < 0)
    {
      throw std::invalid_argument("_numCitizens must be greater than 0");
      return;
    }
    numCitizens = _numCitizens;
  };
  

private:
  int numCitizens;
  MapState* mapState;
  Military* military;
  WarStage* warStage;
  Strategy* strategy;
  CountryState* state;
  Superpower* superpower;
  CountryMediator* mediator;
  std::vector<double> mapWeights;
  std::vector<double> militaryWeights;
  std::vector<double> domesticWeights;
};

#endif
