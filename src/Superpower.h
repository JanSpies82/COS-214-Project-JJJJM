
#ifndef __Superpower_h__
#define __Superpower_h__

#include <string>
#include <vector>

class Country;

class Superpower
{
public:
  /**
   * @brief Construct a new Superpower object
   *
   * @param name : std::string - the name of the superpower
   * @param color : std::string - the color code of the superpower
   */
  Superpower(std::string name, std::string color);

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
   * @brief Get the color code of the superpower
   *
   * @return std::string
   */
  std::string getColor();

  /**
   * @brief Add a country to the superpower
   *
   * @param country : Country* - the country to add
   */
  void addCountry(Country *country);

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
  Country *getCountry(int index);

  /**
   * @brief Remove the passed in country from the superpower
   *
   * Exceptions : std::out_of_range if the country is not owned by the superpower
   * 
   * @param country : Country* - the country to remove
   */
  void removeCountry(Country *country);

private:
  std::vector<Country *> *countries;
};

#endif
