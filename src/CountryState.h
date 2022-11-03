
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
    * @brief create new country state
    * 
    * @param country country to create state for
    */
  CountryState();
  CountryState(Country* country);
  CountryState(const CountryState& cs);
  ~CountryState();
  CountryState* clone();
  MilitaryState* getMilitaryState();
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
