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
class MapState;

class Country
{
public: 
  /**
   * @brief  Default constructor
   */
  Country();

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

  /**
    * @brief generates a countries strength rating based on various state information
    * @return the strength rating of this country
    */
  double getCountryRating();

  /**
    * @brief generates a vector of military coefficients reflecting military strength
    * @return a vector of int coefficients
    */
  std::vector<int> getMilitaryCoefficients();

  /**
    * @brief generates a vector of map coefficients reflecting the strength
    * of this country's position on the map
    * @return a vector of int coefficients
    */
  std::vector<int> getMapCoefficients();

  /**
    * @brief generates a vector of domestic coefficients reflecting the internal strength
    * of this country
    * @return a vector of int coefficients
    */
  std::vector<int> getDomesticCoefficients();

  /**
    * @brief getter for numCitizens attribute
    * @return returns current number of citizens of this country
    */
  int getNumCitizens();

  /**
   * @brief sets the value of class attribute numCitizens
   * @param int new value of numCitizens
   */
  void setNumCitizens(int _numCitizens);

  /**
    * @brief getter for politicalStability attribute
    * @return returns current political stability of this country
    */
  double getPoliticalStability();

  /**
   * @brief sets the value of class attribute politicalStability
   * @param double new value of politicalStability
   */
  void setPoliticalStability(double _politicalStability);

  /**
    * @brief getter for domesticMorale attribute
    * @return returns current domestic morale of this country
    */
  double getDomesticMorale();

  /**
   * @brief sets the value of class attribute domesticMorale
   * @param double new value of domesticMorale
   */
  void setDomesticMorale(double _domesticMorale);

  /**
    * @brief getter for selfReliance attribute
    * @return returns current self reliance of this country
    */
  double getSelfReliance();

  /**
   * @brief sets the value of class attribute selfReliance
   * @param double new value of selfReliance
   */
  void setSelfReliance(double _selfReliance);

  /**
    * @brief getter for borderStrength attribute
    * @return returns current border strength of this country
    */
  double getBorderStrength();

  /**
   * @brief sets the value of class attribute borderStrength
   * @param double new value of borderStrength
   */
  void setBorderStrength(double _borderStrength);

  /**
    * @brief getter for capitalSafety attribute, which is how safe the capital is from enemies
    * @return returns current capital safety of this country
    */
  double getCapitalSafety();

  /**
   * @brief sets the value of class attribute capitalSafety
   * @param double new value of capitalSafety
   */
  void setCapitalSafety(double _capitalSafety);

  /**
    * @brief getter for warSentiment attribute
    * @return returns current war sentiment of this country
    */
  double getWarSentiment();

  /**
   * @brief sets the value of class attribute warSentiment
   * @param double new value of warSentiment
   */
  void setWarSentiment(double _warSentiment);

  /**
    * @brief getter for tradeRouteSafety attribute
    * @return returns current trade route safety of this country
    */
  double getTradeRouteSafety();

  /**
   * @brief sets the value of class attribute tradeRouteSafety
   * @param double new value of tradeRouteSafety
   */
  void setTradeRouteSafety(double _tradeRouteSafety);
  

private:
  int numCitizens;
  MapState* mapState;
  Military* military;
  WarStage* warStage;
  Strategy* strategy;
  CountryState* state;
  Superpower* superpower;
  CountryMediator* mediator;
  double politicalStability;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
  std::vector<double> mapWeights;
  std::vector<double> militaryWeights;
  std::vector<double> domesticWeights;
};

#endif
