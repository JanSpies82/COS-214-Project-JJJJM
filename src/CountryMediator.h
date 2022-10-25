#ifndef __CountryMediator_h__
#define __CountryMediator_h__

class Country;

class CountryMediator
{
public: 
  std::vector<Country*>* countries;

  /**
    * @brief for all countries, notify them of the new state
    * 
    * @param country origin country of updated state
    */
  void notify(Country* country);
};

#endif
