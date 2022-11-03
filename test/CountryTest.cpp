#include <limits.h>
#include <stdexcept>
#include <vector>
#include "../src/Country.h"
#include "../src/Ship.h"
#include "../src/Plane.h"
#include "../src/Tank.h"
#include "../src/Vehicle.h"
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
    a = NULL;
  }

  TEST(CountryTest, identifyStrategy)
  {
    // Set countryA countryState
    Country* countryA = new Country("countryA");
    countryA->setBorderStrength(0.9);
    countryA->setNumCitizens(1000);
    countryA->setCapitalSafety(0.9);
    countryA->setDomesticMorale(0.9);
    countryA->setTradeRouteSafety(0.9);
    countryA->setSelfReliance(0.9);
    countryA->setPoliticalStability(0.9);

    // Set countryB countryState
    Country* countryB = new Country("CountryB");
    countryB->setBorderStrength(0.3);
    countryB->setNumCitizens(100);
    countryB->setCapitalSafety(0.3);
    countryB->setDomesticMorale(0.3);
    countryB->setTradeRouteSafety(0.3);
    countryB->setSelfReliance(0.3);
    countryB->setPoliticalStability(0.3);

    // Create countryA militaryState
    MilitaryState* mA = new MilitaryState();

    std::vector<Ship*>* shipsA = new std::vector<Ship*>();
    for (int i = 0; i < 100; i++)
      shipsA->push_back(new Ship());
    mA->setShips(shipsA);
    
    std::vector<Tank*>* tanksA = new std::vector<Tank*>();
    for (int i = 0; i < 100; i++)
      tanksA->push_back(new Tank());
    mA->setTanks(tanksA);

    std::vector<Plane*>* planesA = new std::vector<Plane*>();
    for (int i = 0; i < 100; i++)
      planesA->push_back(new Plane());
    mA->setPlanes(planesA);

    // Create countryB militaryState
    MilitaryState* mB = new MilitaryState();

    std::vector<Ship*>* shipsB = new std::vector<Ship*>();
    for (int i = 0; i < 10; i++)
      shipsB->push_back(new Ship());
    mB->setShips(shipsB);
    
    std::vector<Tank*>* tanksB = new std::vector<Tank*>();
    for (int i = 0; i < 10; i++)
      tanksB->push_back(new Tank());
    mB->setTanks(tanksB);

    std::vector<Plane*>* planesB = new std::vector<Plane*>();
    for (int i = 0; i < 10; i++)
      planesB->push_back(new Plane());
    mB->setPlanes(planesB);

    countryA->setMilitaryState(mA);
    countryB->setMilitaryState(mB);
    countryA->takeTurn(countryB);

    delete countryA;
    delete countryB;
  }
}