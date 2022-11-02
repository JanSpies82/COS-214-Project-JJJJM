#ifndef __Country_h__
#define __Country_h__

#include <vector>
#include <string>
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
class Location;

class Country
{
public: 
  /**
   * @brief default constructor
   */
  Country();

  /**
   * @brief destructor
  */
  ~Country();

  /**
   * @brief parameterised constructor
  */
  Country(std::string _name);

  /**
    * @brief uses state information to implement next action
    * 
    * @param countryB the country that is being attacked
    */
  void takeTurn(Country* countryB);

  /**
   * @brief sets the country's strategy
   * 
   * @todo implement
  */
  void setStrategy();

  /**
    * @brief return up-to-date state information
    * 
    * @todo review for deletion
    */
  CountryState* getState();

  /**
   * @brief returns the country's name
  */
  std::string getName();

  /**
   * @brief getter for this country's military
   * 
   * @return this country's military object
  */
  Military* getMilitary();

  /**
    * @brief generates a countries strength rating based on various state comparisons with enemy
    * 
    * @param countryB the country that this country is implementing a strategy against
    * 
    * @return the strength rating of this country
    */
  void getCountryRating(Country* countryB, double* strengthRatings);

  /**
    * @brief compares two state paramters and returns countryA's advantage
    * 
    * @param countryA state parameter of countryA
    * 
    * @param countryB state parameter of countryB
    * 
    * @return a comparable value of the advantage of countryA
    */
  double compareAspect(int countryA, int countryB);

  /**
    * @brief compares two state paramters and returns countryA's advantage
    * 
    * @param countryA state parameter of countryA
    * 
    * @param countryB state parameter of countryB
    * 
    * @return a comparable value of the advantage of countryA
    */
  double compareAspect(double countryA, double countryB);

  /**
    * @brief getter for numCitizens attribute
    * 
    * @return returns current number of citizens of this country
    */
  int getNumCitizens();

  /**
   * @brief sets the value of class attribute numCitizens
   * 
   * @param _numCitizens new value of numCitizens
   */
  void setNumCitizens(int _numCitizens);

  /**
    * @brief getter for politicalStability attribute
    * 
    * @return returns current political stability of this country
    */
  double getPoliticalStability();

  /**
   * @brief sets the value of class attribute politicalStability
   * 
   * @param _politicalStability new value of politicalStability
   */
  void setPoliticalStability(double _politicalStability);

  /**
    * @brief getter for domesticMorale attribute
    * 
    * @return returns current domestic morale of this country
    */
  double getDomesticMorale();

  /**
   * @brief sets the value of class attribute domesticMorale
   * 
   * @param _domesticMorale new value of domesticMorale
   */
  void setDomesticMorale(double _domesticMorale);

  /**
    * @brief getter for selfReliance attribute
    * 
    * @return returns current self reliance of this country
    */
  double getSelfReliance();

  /**
   * @brief sets the value of class attribute selfReliance
   * 
   * @param _selfReliance new value of selfReliance
   */
  void setSelfReliance(double _selfReliance);

  /**
    * @brief getter for borderStrength attribute
    * 
    * @return returns current border strength of this country
    */
  double getBorderStrength();

  /**
   * @brief sets the value of class attribute borderStrength
   * 
   * @param _borderStrength new value of borderStrength
   */
  void setBorderStrength(double _borderStrength);

  /**
    * @brief getter for capitalSafety attribute, which is how safe the capital is from enemies
    * 
    * @return returns current capital safety of this country
    */
  double getCapitalSafety();

  /**
   * @brief sets the value of class attribute capitalSafety
   * 
   * @param _capitalSafety new value of capitalSafety
   */
  void setCapitalSafety(double _capitalSafety);

  /**
    * @brief getter for warSentiment attribute
    * 
    * @return returns current war sentiment of this country
    */
  double getWarSentiment();

  /**
   * @brief sets the value of class attribute warSentiment
   * 
   * @param _warSentiment new value of warSentiment
   */
  void setWarSentiment(double _warSentiment);

  /**
    * @brief getter for tradeRouteSafety attribute
    * 
    * @return returns current trade route safety of this country
    */
  double getTradeRouteSafety();

  /**
   * @brief sets the value of class attribute tradeRouteSafety
   * 
   * @param _tradeRouteSafety new value of tradeRouteSafety
   */
  void setTradeRouteSafety(double _tradeRouteSafety);

  /**
   * @brief getter for this country's strategy
   * 
   * @return returns this country's strategy object
  */
  CountryState* getCountryState();

  /**
   * @brief setter for this country's state
   * 
   * @param _countryState new country state
  */
  void setCountryState(CountryState* _countryState);

  /**
   * @brief compares the various aspects of two countries' militaries
   * 
   * @param a the country implementing a strategy against b
   * 
   * @param b the country being attacked by a
   * 
   * @param aspectScores pointer to an array that holds this countries scores across each state aspect
  */
  void compareMilitary(Country* a, Country* b, std::vector<double>* aspectScores);

  /**
   * @brief compares the various aspects of two countries' internal states
   * 
   * @param a the country implementing a strategy against b
   * 
   * @param b the country being attacked by a
   * 
   * @param aspectScores pointer to an array that holds this countries scores across each state aspect
  */
  void compareDomestic(Country* a, Country* b, std::vector<double>* aspectScores);

  /**
   * @brief getter for this country's capital
   * 
   * @return returns this country's capital location object
  */
  Location* getCapital();

  /**
   * @brief setter for this country's capital
   * 
   * @param _capital new capital location object
  */
  void setCapital(Location* _capital);

  /**
   * @brief getter for this country's locations
  */
  std::vector<Location*>* getLocations();

  /**
   * @brief setter for this country's locations, performs a shallow copy of the passed in locations vector
  */
  void setLocations(std::vector<Location*>* _locations);

/**
 * @brief setter for this country's color 
 * 
 * @param _color : std::string - The color this country should be printed as on the map
 */
  void setColor(std::string _color);

  /**
   * @brief getter for this country's color
   * 
   * @return returns this country's color
  */
  std::string getColor();
  
private:
  int numCitizens;
  std::string name;
  Location* capital;
  Strategy* strategy;
  Military* military;
  double politicalStability;
  double domesticMorale;
  double selfReliance;
  double borderStrength;
  double capitalSafety;
  double warSentiment;
  double tradeRouteSafety;
  CountryMediator* mediator;
  CountryState* countryState;
  std::vector<Country*>* enemies;
  std::vector<Location*>* locations;
  std::string color;
};

#endif
