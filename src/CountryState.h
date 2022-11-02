
#ifndef __CountryState_h__
#define __CountryState_h__

// #include "Country.h"
#include <ctime>
class Country;

class MilitaryState;

class CountryState
{
public:
  /**
    * @brief create new country state
    * 
    * @param country country to create state for
    */
  CountryState(Country* country);
  CountryState(const CountryState& cs);
  ~CountryState();
  CountryState* clone();
  MilitaryState* getMilitaryState();

private: 
  friend class Country;
  int numCitizens;
  std::string name;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
  double politicalStability;
  MilitaryState* militaryState;
  std::vector<Country*>* enemies;
};

#endif
