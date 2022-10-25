
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

private: 
  std::time_t timestamp;
};

#endif
