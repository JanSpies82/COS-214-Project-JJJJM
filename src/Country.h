#ifndef __Country_h__
#define __Country_h__

#include <vector>
#include <exception>

class WarStage;
class Superpower;
class Military;
class CountryState;
class Citizen;
class CountryMediator;
class Strategy;
class Country;
class MapState;
class MilitaryState;

class Country
{
public: 
  /**
   * @brief default constructor
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
  void takeTurn();

  /**
    * @brief return up-to-date state information
    */
  CountryState* getState();

  /**
    * @brief generates a countries strength rating based on various state comparisons with enemy
    * @return the strength rating of this country
    */
  double getCountryRating(Country* enemy);

  /**
    * @brief compares two state paramters and returns countryA's advantage
    * @param countryA the country to return the advantage of
    * @param countryB the enemy country to compare to
    * @return a comparable value of the advantage of countryA
    */
  double compareAspect(int countryA, int countryB);

  /**
    * @brief compares two state paramters and returns countryA's advantage
    * @param countryA the country to return the advantage of
    * @param countryB the enemy country to compare to
    * @return a comparable value of the advantage of countryA
    */
  double compareAspect(double countryA, double countryB);

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

  /**
   * @brief getter for this country's military state
   * @return returns this country's militaryState object
  */
  MilitaryState* getMilitaryState();

  /**
   * @brief setter for this country's military state
   * @param MilitaryState* new military state
  */
  void setMilitaryState(MilitaryState* _militaryState);

  /**
   * @brief getter for this country's map state
   * @return returns this country's mapState object
  */
  MapState* getMapState();

  /**
   * @brief setter for this country's map state
   * @param MapState* new map state
  */

  void setMapState(MapState* _mapState);

  /**
   * @brief getter for this country's strategy
   * @return returns this country's strategy object
  */
  CountryState* getCountryState();
  
private:
  int numCitizens;
  MapState* mapState;
  Military* military;
  WarStage* warStage;
  Strategy* strategy;
  CountryState* state;
  MilitaryState* militaryState;
  Superpower* superpower;
  CountryMediator* mediator;
  double politicalStability;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
  std::vector<Country*>* enemies;
  std::vector<double> mapWeights;
  std::vector<double> militaryWeights;
  std::vector<double> domesticWeights;
};

#endif
