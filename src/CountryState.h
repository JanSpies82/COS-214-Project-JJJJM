
#ifndef __CountryState_h__
#define __CountryState_h__

// #include "Country.h"
#include <ctime>
class Country;

class CountryState
{
public:
  /**
    * @brief create new country state
    * 
    * @param country country to create state for
    */
  CountryState(Country* country);
  CountryState* clone();

private: 
  friend class Country;
  std::time_t timestamp;
  int numCitizens;
  double politicalStability;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
};

#endif
