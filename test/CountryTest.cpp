#include <limits.h>
#include <stdexcept>
#include <vector>
#include "../src/Country.h"
#include "../src/Location.h"
#include "../src/Territory.h"
#include "../src/CountryState.h"
#include "../src/MilitaryState.h"
#include "gtest/gtest.h"

namespace {
  TEST(CountryTest, Constructor)
  {
    Country* testCountry = new Country("testCountry");
    delete testCountry;
  }

  TEST(CountryTest, GettersAndSetters)
  {
    Country* countryA = new Country("countryA");
    countryA->setBorderStrength(0.9);
    countryA->setNumCitizens(1000);
    countryA->setPoliticalStability(0.9);
    countryA->setSelfReliance(0.9);
    countryA->setCapitalSafety(0.9);
    EXPECT_EQ(countryA->getName(), "countryA");
    EXPECT_EQ(countryA->getBorderStrength(), 0.9);
    EXPECT_EQ(countryA->getNumCitizens(), 1000);
    EXPECT_EQ(countryA->getPoliticalStability(), 0.9);
    EXPECT_EQ(countryA->getSelfReliance(), 0.9);
    EXPECT_EQ(countryA->getCapitalSafety(), 0.9);
    delete countryA;
  }

  TEST(CountryTest, GetAndSetCountryState)
  {
    Country* countryA = new Country("countryA");
    countryA->setBorderStrength(0.9);
    countryA->setNumCitizens(1000);
    countryA->setPoliticalStability(0.9);
    countryA->setSelfReliance(0.9);
    countryA->setCapitalSafety(0.9);
    Country* countryB = new Country("countryB");
    countryB->setCountryState(new CountryState(countryA));
    EXPECT_EQ(countryB->getBorderStrength(), 0.9);
    EXPECT_EQ(countryB->getNumCitizens(), 1000);
    EXPECT_EQ(countryB->getPoliticalStability(), 0.9);
    EXPECT_EQ(countryB->getSelfReliance(), 0.9);
    EXPECT_EQ(countryB->getCapitalSafety(), 0.9);
    delete countryA;
    delete countryB;
  }

  // Proof of vector deallocation method being memory efficient
  TEST(CountryTest, VectorDeallocation)
  {
    std::vector<Country*>* countries = new std::vector<Country*>();
    countries->push_back(new Country("A"));
    countries->push_back(new Country("B"));
    for (int i = 0; i < countries->size(); i++)
      delete countries->at(i);
    delete countries;
  }  

  TEST(CountryTest, CountryStateAddressConstructor)
  {
    Country* countryA = new Country("countryA");
    countryA->setColor("Red");
    Country* countryB = new Country("countryB");
    CountryState* c = countryA->getCountryState();
    countryB->setCountryState(new CountryState(*c));
    EXPECT_EQ(countryB->getColor(), "Red"); 
    delete countryA;
    delete countryB;
  }

  TEST(CountryTest, setLocations)
  {
    std::vector<Location*>* locs = new std::vector<Location*>();
    for (int i = 0; i < 100; i++)
      locs->push_back(new Territory(0,0));
    Country* a = new Country("a");
    a->setLocations(locs);
    delete a;
  }
}