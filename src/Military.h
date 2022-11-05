/// @author Jake Mahloko

#ifndef __Military_h__
#define __Military_h__

#include <vector>

class Country;

class Military
{
public:
  /**
   * @brief Construct a new Military object
   *
   */
  Military();

  /**
   * @brief Construct a new Military object
   *
   */
  Military(Military * _military);

  /**
   * @brief Destroy the Military object
   *
   */
  ~Military();

  /**
   * @brief
   *
   */
  void attack(Country * _country);
};

#endif
