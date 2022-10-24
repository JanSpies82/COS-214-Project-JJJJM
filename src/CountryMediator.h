#ifndef __CountryMediator_h__
#define __CountryMediator_h__

// #include "Country.h"

class Country;
class CountryMediator;

class CountryMediator
{
public: 
  Country* countries;

  /**
    * @brief for all countries, notify them of the new state
    * 
    * @param country origin country of updated state
    */
  void notify(Country* country);
};

#endif
