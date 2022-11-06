/// @author Jake Weatherhead

#ifndef __Country_h__
#define __Country_h__

#include <vector>
#include <string>
#include <exception>
#include <cstdlib>

class WarStage;
class Superpower;
class Military;
class CountryState;
class Citizen;
class Strategy;
class Country;
class MapState;
class MilitaryState;
class Location;
class LocationObserver;
class Map;

class Country
{
public:
  /**
   * @brief destructor of Country objects
   */
  ~Country();

  /**
   * @brief parameterised constructor for Country objects
   * 
   * @param _name the name of this country
   */
  Country(std::string _name);

  /**
   * @brief default constructor for Country objects
   */
  Country();

  /**
   * @brief uses state information to implement this country's next turn
   *
   * @param countryB the country that is being attacked
   */
  void takeTurn(Country *countryB);

  /**
   * @brief country takes its turn using a country from its enemies list
   * 
   * @param _countryIsDead whether this country was defeated after this turn
   */
  Country* takeTurn(bool *_countryIsDead);

  /**
   * @brief sets this country's strategy based on the current war stage of the simulation
   */
  void setStrategy();

  /**
   * @brief getter for this country's CountryState object
   * 
   * @return a pointer to this country's CountryState object
   */
  CountryState *getState();

  /**
   * @brief getter for the name of this country
   * 
   * @return the name of this country
   */
  std::string getName();

  /**
   * @brief setter for the the name of this country
   * 
   * @param _name the name of this country
   */
  void setName(std::string _name);

  /**
   * @brief getter for this country's military
   *
   * @return this country's Military object
   */
  Military *getMilitary();

  /**
   * @brief generates a countries strengthRating based on various state comparisons with enemy
   *
   * @param countryB the country that this country is implementing a strategy against
   * @param strengthRatings the comparable strength ratings of this country and countryB
   *
   * @return the strength rating of this country
   */
  void getCountryRating(Country *countryB, double *strengthRatings);

  /**
   * @brief compares two state paramters and returns countryA's advantage
   *
   * @param countryA state parameter of countryA
   * @param countryB state parameter of countryB
   *
   * @return a comparable value of the advantage of countryA over countryB
   */
  double compareAspect(int countryA, int countryB);

  /**
   * @brief compares two state paramters and returns countryA's advantage
   *
   * @param countryA state parameter of countryA
   * @param countryB state parameter of countryB
   *
   * @return a comparable value of the advantage of countryA over countryB
   */
  double compareAspect(double countryA, double countryB);

  /**
   * @brief getter for numCitizens attribute
   *
   * @return current number of citizens of this country
   */
  int getNumCitizens();

  /**
   * @brief sets for the numCitizens attribute
   *
   * @param _numCitizens new value of numCitizens
   */
  void setNumCitizens(int _numCitizens);

  /**
   * @brief getter for this country's politicalStability attribute
   *
   * @return current politicalStability of this country
   */
  double getPoliticalStability();

  /**
   * @brief setter for this country's politicalStability attribute
   *
   * @param _politicalStability new value for this country's politicalStability attribute
   */
  void setPoliticalStability(double _politicalStability);

  /**
   * @brief getter for domesticMorale attribute
   *
   * @return current domesticMorale of this country
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
   * @return current self reliance of this country
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
   * @return current borderStrength of this country
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
   * @return current capitalSafety of this country
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
   * @return current warSentiment of this country
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
   * @return current tradeRouteSafety of this country
   */
  double getTradeRouteSafety();

  /**
   * @brief sets the value of class attribute tradeRouteSafety
   * 
   * @param _tradeRouteSafety new value of tradeRouteSafety
   */
  void setTradeRouteSafety(double _tradeRouteSafety);

  /**
   * @brief getter for this country's strategy object
   * 
   * @return this country's strategy object
   */
  CountryState *getCountryState();

  /**
   * @brief setter for this country's state
   * 
   * @param _countryState new countryState
   */
  void setCountryState(CountryState *_countryState);

  /**
   * @brief compares the various aspects of two countries' MilitaryState objects
   * 
   * @param a the country implementing a strategy against b
   * @param b the country being attacked by a
   * @param aspectScores vector of this country's scores across each MilitaryState attribute
   */
  void compareMilitary(Country *a, Country *b, std::vector<double> *aspectScores);

  /**
   * @brief compares the various aspects of two countries' CountryState objects
   * 
   * @param a the country implementing a strategy against b
   * @param b the country being attacked by a
   * @param aspectScores vector of this country's scores across each CountryState attribute
   */
  void compareDomestic(Country *a, Country *b, std::vector<double> *aspectScores);

  /**
   * @brief getter for this country's capital Location object
   * 
   * @return this country's capital Location object
   */
  Location *getCapital();

  /**
   * @brief setter for this country's capital
   * 
   * @param _capital new capital Location object
   */
  void setCapital(Location *_capital);

  /**
   * @brief getter for this country's locations
   * 
   * @return vector of this country's locations
   */
  std::vector<Location *> *getLocations();

  /**
   * @brief setter for this country's locations, performs a shallow copy of the passed in locations vector
   */
  void setLocations(std::vector<Location *> *_locations);

  /**
   * @brief setter for this country's color
   * 
   * @param _color : std::string - The color this country should be printed as on the map
   */
  void setColor(std::string _color);

  /**
   * @brief getter for this country's color
   * 
   * @return this country's color
   */
  std::string getColor();

  /**
   * @brief getter for this country's enemies
   * 
   * @return a pointer to the vector of this country's enemies
   */
  std::vector<Country *> *getEnemies();

  /**
   * @brief setter for this country's enemies
   * 
   * @param _enemies : std::vector<Country *> - The new vector of enemies for this country
   */
  void setEnemies(std::vector<Country *> *_enemies);

  /**
   * @brief getter for this country's MilitaryState object
   */
  MilitaryState *getMilitaryState();

  /**
   * @brief setter for this country's MilitaryState object
   */
  void setMilitaryState(MilitaryState *_militaryState);

  /**
   * @brief settervfor the country's CountryState object
   * 
   * @param _state : CountryState* - The new state object
   */
  void setState(CountryState *_state);

  /**
   * @brief print a summary of this country's state
   */
  void printSummary();

  /**
   * @brief subscribes an observer to changes in this country's locations
   * 
   * @param observer the observer to attach
   */
  void attachObserver(LocationObserver *_lObserver);

  /**
   * @brief detaches an observer of this country
   * 
   * @param _lObserver the observer to detach
   */
  void detachObserver(LocationObserver *_lObserver);

  /**
   * @brief resets this country's locations to a passed-in state
   * 
   * @param _map source of locations to reset to
   */
  void resetLocations(Map *_map);

  /**
   * @brief creates a clone of this country
   * 
   * @return a pointer to the newly cloned Country object
  */
  Country *clone();

  /**
   * @brief resets this country's enemies to a previous state
   * 
   * @param _enemies a vector of enemies to replace this country's current enemies
   */ 
  void resetEnemies(std::vector<Country *> *_enemies);

  /**
   * @brief removes an enemy from this country's enemies vector
   * 
   * @param _enemy enemy to be removed
   */
  void removeEnemy(Country *_enemy);

  /**
   * @brief sets the color of the colorOfDestroyedBy attribute
   * 
   * @param _newColorOfDestroyedBy color of the country that destroyed this country
   */
  void setColorOfDestroyedBy(std::string _newColorOfDestroyedBy);

  /**
   * @brief evaluates whether countryA was defeated by countryB
   * 
   * @param countryA the country that is checked to see if it was defeated
   * @param countryB the country that is checked to see if it defeated countryA
   * 
   * @return true if countryA was defeated by countryB, false otherwise
   */
  bool checkIsDead(Country* countryA, Country* countryB);

private:
  // bool checkIsDead();
  std::string colorOfDestroyedBy="\x1B[100m";
  Strategy *strategy;
  Military *military;
  CountryState *countryState;
  std::vector<LocationObserver *> *locationObservers;
};

#endif
