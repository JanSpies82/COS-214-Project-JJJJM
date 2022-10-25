#include <exception>

#ifndef __Country_h__
#define __Country_h__

#include "WarStage.h"
// #include "Superpower.h"
// #include "Military.h"
// #include "CountryState.h"
// #include "Citizen.h"
// #include "CountryMediator.h"
// #include "Strategy.h"

#include <vector>

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
  /**
    * @brief takes next action in simulation based on current state
    */
  void request();

  /**
    * @brief notify each observer of the new current state
    */
  void notify();

  /**
    * @brief add new observer to vector of observers
    */
  void attach();
  
  /**
    * @brief remove observer from vector of observers
    */
  void detach();

  /**
    * @brief uses state information to implement next action
    */
  void algorithm();

  /**
    * @brief return up-to-date state information
    */
  CountryState* getState();

private:
  std::vector<Superpower*>* superpowers;
  std::vector<WarStage*>* warStages;
  std::vector<Military*>* militaries;
  CountryState* state;
  std::vector<Citizen*>* citizens;
  std::vector<CountryMediator*>* countryMediators;  
  WarStage* warStage;
  Strategy* strategy;
  CountryMediator* mediator;
};

#endif
