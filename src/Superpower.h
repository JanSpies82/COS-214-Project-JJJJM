///@author Janco Spies

#ifndef __Superpower_h__
#define __Superpower_h__

#include <string>
#include <vector>

class Country;
class SuperpowerState;

class Superpower
{
public:
  /**
   * @brief Construct a new Superpower object
   *
   * @param name : std::string - the name of the superpower
   */
  Superpower(std::string _name);

  /**
   * @brief Reconstruct a superpower object from a SuperpowerState
   * 
   * @param state : SuperpowerState* - the state to reconstruct from
   */
  Superpower(SuperpowerState *_state);

  /**
   * @brief Destroy the Superpower object and delete all of its countries
   *
   */
  ~Superpower();

  /**
   * @brief Get the name of the superpower
   *
   * @return std::string
   */
  std::string getName();

  /**
   * @brief Add a country to the superpower
   *
   * @param country : Country* - the country to add
   */
  void addCountry(Country *_country);

  /**
   * @brief Get the number of countries owned by the superpower
   *
   * @return int
   */
  int getCountryCount();

  /**
   * @brief Get the country at the specified index
   *
   * Exceptions : std::out_of_range if the index is out of range
   *
   * @param index : int - the index of the country to get
   * @return Country* - pointer to the country at the specified index
   */
  Country *getCountry(int _index);

  /**
   * @brief Remove the passed in country from the superpower
   *
   * Exceptions : std::out_of_range if the country is not owned by the superpower
   *
   * @param country : Country* - the country to remove
   */
  void removeCountry(Country *_country);

  /**
   * @brief Get the state of the superpower
   *
   * @return SuperpowerState* - pointer to the state of the superpower
   */
  SuperpowerState *getState();

  /**
   * @brief Prints a summary of the superpower and all its countries
   *
   */
  void printSummary();

private:
  std::vector<Country *> *countries;
  std::string name;
};

#endif
