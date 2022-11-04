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

namespace
{
  TEST(CountryTest, Constructor)
  {
    Country *testCountry = new Country("testCountry");
    delete testCountry;
  }

  TEST(CountryTest, GettersAndSetters)
  {
    Country *countryA = new Country("countryA");
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
    Country *countryA = new Country("countryA");
    countryA->setBorderStrength(0.9);
    countryA->setNumCitizens(1000);
    countryA->setPoliticalStability(0.9);
    countryA->setSelfReliance(0.9);
    countryA->setCapitalSafety(0.9);
    Country *countryB = new Country("countryB");
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
    std::vector<Country *> *countries = new std::vector<Country *>();
    countries->push_back(new Country("A"));
    countries->push_back(new Country("B"));
    for (int i = 0; i < countries->size(); i++)
      delete countries->at(i);
    delete countries;
  }

  TEST(CountryTest, CountryStateAddressConstructor)
  {
    Country *countryA = new Country("countryA");
    countryA->setColor("Red");
    Country *countryB = new Country("countryB");
    CountryState *c = countryA->getCountryState();
    countryB->setCountryState(new CountryState(*c));
    EXPECT_EQ(countryB->getColor(), "Red");
    delete countryA;
    delete countryB;
  }

  TEST(CountryTest, setLocations)
  {
    std::vector<Location *> *locs = new std::vector<Location *>();
    for (int i = 0; i < 100; i++)
      locs->push_back(new Territory(0, 0));
    Country *a = new Country("a");
    a->setLocations(locs);
    for (int i = 0; i < locs->size(); i++)
      delete locs->at(i);
    delete a;    
  }

  // Test whether the parameterised takeTurn() method
  // properly executes a strategy. Note: currently only tests
  // if strengthRatings are correctly generated. 
  TEST(CountryTest, parameterisedTakeTurn)
  {
    // Set countryA countryState
    Country *countryA = new Country("countryA");
    countryA->setBorderStrength(0.9);
    countryA->setNumCitizens(1000);
    countryA->setCapitalSafety(0.9);
    countryA->setDomesticMorale(0.9);
    countryA->setTradeRouteSafety(0.9);
    countryA->setSelfReliance(0.9);
    countryA->setPoliticalStability(0.9);

    // Set countryB countryState
    Country *countryB = new Country("CountryB");
    countryB->setBorderStrength(0.3);
    countryB->setNumCitizens(100);
    countryB->setCapitalSafety(0.3);
    countryB->setDomesticMorale(0.3);
    countryB->setTradeRouteSafety(0.3);
    countryB->setSelfReliance(0.3);
    countryB->setPoliticalStability(0.3);

    // Create countryA militaryState
    MilitaryState *mA = new MilitaryState();

    std::vector<Ship *> *shipsA = new std::vector<Ship *>();
    for (int i = 0; i < 100; i++)
      shipsA->push_back(new Ship());
    mA->setShips(shipsA);

    std::vector<Tank *> *tanksA = new std::vector<Tank *>();
    for (int i = 0; i < 100; i++)
      tanksA->push_back(new Tank());
    mA->setTanks(tanksA);

    std::vector<Plane *> *planesA = new std::vector<Plane *>();
    for (int i = 0; i < 100; i++)
      planesA->push_back(new Plane());
    mA->setPlanes(planesA);

    // Create countryB militaryState
    MilitaryState *mB = new MilitaryState();

    std::vector<Ship *> *shipsB = new std::vector<Ship *>();
    for (int i = 0; i < 10; i++)
      shipsB->push_back(new Ship());
    mB->setShips(shipsB);

    std::vector<Tank *> *tanksB = new std::vector<Tank *>();
    for (int i = 0; i < 10; i++)
      tanksB->push_back(new Tank());
    mB->setTanks(tanksB);

    std::vector<Plane *> *planesB = new std::vector<Plane *>();
    for (int i = 0; i < 10; i++)
      planesB->push_back(new Plane());
    mB->setPlanes(planesB);

    countryA->setMilitaryState(mA);
    countryB->setMilitaryState(mB);
    countryA->takeTurn(countryB);

    delete countryA;
    delete countryB;
  }

  // Test whether the takeTurn() method that takes no parameters
  // properly executes a strategy. Note: currently only tests
  // if strengthRatings are correctly generated. 
  TEST(CountryTest, randomEnemyTakeTurn)
  {
    // Create 5 enemies for countryX
    std::string names[5] = {"A", "B", "C", "D", "E"};
    std::vector<Country *> *enemies = new std::vector<Country *>();
    std::vector<MilitaryState *> *ms = new std::vector<MilitaryState *>();
    std::vector<std::vector<Ship*>*>* shipVectors = new std::vector<std::vector<Ship*>*>();
    std::vector<std::vector<Tank*>*>* tankVectors = new std::vector<std::vector<Tank*>*>();
    std::vector<std::vector<Plane*>*>* planeVectors = new std::vector<std::vector<Plane*>*>();
    for (int i = 0; i < 5; i++)
    {
      enemies->push_back(new Country(names[i]));
      enemies->at(i)->setBorderStrength((double)rand() / (double)RAND_MAX);
      enemies->at(i)->setNumCitizens((double)rand() / (double)RAND_MAX * 1000);
      enemies->at(i)->setCapitalSafety((double)rand() / (double)RAND_MAX);
      enemies->at(i)->setDomesticMorale((double)rand() / (double)RAND_MAX);
      enemies->at(i)->setTradeRouteSafety((double)rand() / (double)RAND_MAX);
      enemies->at(i)->setSelfReliance((double)rand() / (double)RAND_MAX);
      enemies->at(i)->setPoliticalStability((double)rand() / (double)RAND_MAX);

      ms->push_back(new MilitaryState());

      int size[5] = {20, 40, 60, 80, 100};
      
      shipVectors->push_back(new std::vector<Ship *>());
      for (int j = 0; j < size[i]; j++)
        shipVectors->at(i)->push_back(new Ship());
      ms->at(i)->setShips(shipVectors->at(i));
      
      tankVectors->push_back(new std::vector<Tank *>());
      for (int j = 0; j < size[i]; j++)
        tankVectors->at(i)->push_back(new Tank());
      ms->at(i)->setTanks(tankVectors->at(i));
      
      planeVectors->push_back(new std::vector<Plane *>());
      for (int j = 0; j < size[i]; j++)
        planeVectors->at(i)->push_back(new Plane());
      ms->at(i)->setPlanes(planeVectors->at(i));
      
      enemies->at(i)->setMilitaryState(ms->at(i));
      
    }

    // Set up countryX
    Country *countryX = new Country("X");
    countryX->setBorderStrength(0.9);
    countryX->setNumCitizens(100000);
    countryX->setCapitalSafety(0.9);
    countryX->setDomesticMorale(0.9);
    countryX->setTradeRouteSafety(0.9);
    countryX->setSelfReliance(0.9);
    countryX->setPoliticalStability(0.9);

    countryX->setEnemies(enemies);

    MilitaryState *mA = new MilitaryState();

    std::vector<Ship *> *shipsA = new std::vector<Ship *>();
    for (int i = 0; i < 100; i++)
      shipsA->push_back(new Ship());
    mA->setShips(shipsA);

    std::vector<Tank *> *tanksA = new std::vector<Tank *>();
    for (int i = 0; i < 100; i++)
      tanksA->push_back(new Tank());
    mA->setTanks(tanksA);

    std::vector<Plane *> *planesA = new std::vector<Plane *>();
    for (int i = 0; i < 100; i++)
      planesA->push_back(new Plane());
    mA->setPlanes(planesA);

    countryX->setMilitaryState(mA);
    countryX->takeTurn();
    delete countryX;
    delete enemies;
    delete ms;
    delete shipVectors;
    delete planeVectors;
    delete tankVectors;
  }
}