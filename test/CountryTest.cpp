#include <limits.h>
#include <stdexcept>
#include "../src/Country.h"
#include "gtest/gtest.h"

namespace {

  TEST(CountryTest, Constructor)
  {
    Country* testCountry = new Country();
    EXPECT_EQ(testCountry->getTurnCount(), 1);
  }
}