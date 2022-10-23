
#ifndef __CountryState_h__
#define __CountryState_h__

// #include "Country.h"

class Country;

class CountryState
{
public:
  CountryState(Country* c);
  virtual void simulationState();
  Country* request;

private: 
  std::time_t timestamp;
};

#endif
