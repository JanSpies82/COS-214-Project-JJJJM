#include <exception>
using namespace std;

#ifndef __Country_h__
#define __Country_h__

#include "WarStage.h"
// #include "Superpower.h"
// #include "Military.h"
// #include "CountryState.h"
// #include "Citizen.h"
// #include "CountryMediator.h"
// #include "Strategy.h"

class WarStage;
class Superpower;
class Military;
class CountryState;
class Citizen;
class CountryMediator;
class Strategy;
class Country;

class Country
{
public: 
  void request();
  void notify();
  void attach();
  void detach();
  void algorithm();
  Superpower* superpowers;
  WarStage* warStages;
  Military* militaries;
  CountryState* req;
  Citizen* citizens;
  CountryMediator* countryMediators;
  Strategy* strategies;

private:
  WarStage* warStage;
  Strategy* strategy;
  CountryMediator* mediator;
};

#endif
