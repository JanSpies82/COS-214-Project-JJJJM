#include <limits.h>
#include <stdexcept>
#include "../src/Country.h"
#include "gtest/gtest.h"

namespace {
  TEST(CountryTest, Constructor)
  {
    Country* testCountry = new Country();
    delete testCountry;
  }

  TEST(CountryTest, ImplementStrategy)
  {
    Country* countryA = new Country();
    Country* countryB = new Country();



    delete countryB;
    delete countryA;
  }
}