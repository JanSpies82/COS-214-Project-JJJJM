
#ifndef __Citizen_h__
#define __Citizen_h__

#include <vector>
// #include "Country.h"

class Country;
class Citizen;

class Citizen
{
public:
  std::vector<Country*>* countries;
};

#endif