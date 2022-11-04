/// @author Jake Weatherhead

#ifndef __CountryState_h__
#define __CountryState_h__

// #include "Country.h"
#include <ctime>
#include <string>
#include <vector>

class Country;
class Location;
class MilitaryState;

class CountryState
{
public:
  /**
  * @brief Create new country state
  * 
  * @param country country to create state for
  */
  CountryState();

  /**
   * @brief Construct a new Country State object
   * 
   * @param country 
   */
  CountryState(Country* country);

  /**
   * @brief Construct a new Country State object
   * 
   * @param cs 
   */
  CountryState(const CountryState& cs);

  /**
   * @brief Destroy the Country State object
   * 
   */
  ~CountryState();

  /**
   * @brief Create a clone of the held country state and return it
   * 
   * @return CountryState* 
   */
  CountryState* clone();

  /**
   * @brief Get the Military State object
   * 
   * @return MilitaryState* 
   */
  MilitaryState* getMilitaryState();

  /**
   * @brief Set the Military State object
   * 
   * @param _militaryState 
   */
  void setMilitaryState(MilitaryState* _militaryState);

private: 
  friend class Country;
  std::string name;
  int numCitizens;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
  double politicalStability;
  MilitaryState* militaryState;
  Location* capital;
  std::string color;
  std::vector<Country*>* enemies;
  std::vector<Location*>* locations;
};

#endif
