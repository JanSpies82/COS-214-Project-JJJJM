#include <limits.h>
#include <stdexcept>
#include "../src/MilitaryState.h"
#include "../src/Tank.h"
#include "../src/Ship.h"
#include "../src/Plane.h"
#include "../src/Battalion.h"
#include "gtest/gtest.h"

namespace
{
    TEST(MilitaryStateTest, Constructor)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        EXPECT_EQ(testMilitaryState->getNumShips(), 0);
        EXPECT_EQ(testMilitaryState->getNumPlanes(), 0);
        EXPECT_EQ(testMilitaryState->getNumTanks(), 0);
        EXPECT_EQ(testMilitaryState->getNumBattalions(), 0);
        EXPECT_EQ(testMilitaryState->getNumTroops(), 0);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumTroopsPos)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumTroops(1000, true);
        EXPECT_EQ(testMilitaryState->getNumTroops(), 1000);
        testMilitaryState->updateNumTroops(500, false);
        EXPECT_EQ(testMilitaryState->getNumTroops(), 500);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumTroopsNeg)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumTroops(1000, true);
        EXPECT_EQ(testMilitaryState->getNumTroops(), 1000);
        EXPECT_THROW(testMilitaryState->updateNumTroops(1500, false), std::runtime_error);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumTanksPos)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumTanks(10, true);
        EXPECT_EQ(testMilitaryState->getNumTanks(), 10);
        testMilitaryState->updateNumTanks(5, false);
        EXPECT_EQ(testMilitaryState->getNumTanks(), 5);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumTanksNeg)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumTanks(10, true);
        EXPECT_EQ(testMilitaryState->getNumTanks(), 10);
        EXPECT_THROW(testMilitaryState->updateNumTanks(15, false), std::runtime_error);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, setTanks)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        std::vector<Tank *> *testTanks = new std::vector<Tank *>();
        for (int i = 0; i < 10; i++)
            testTanks->push_back(new Tank());
        testMilitaryState->setTanks(testTanks);
        EXPECT_EQ(testMilitaryState->getNumTanks(), 10);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumBattalionsPos)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumBattalions(10, true);
        EXPECT_EQ(testMilitaryState->getNumBattalions(), 10);
        testMilitaryState->updateNumBattalions(5, false);
        EXPECT_EQ(testMilitaryState->getNumBattalions(), 5);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumBattalionsNeg)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumBattalions(10, true);
        EXPECT_EQ(testMilitaryState->getNumBattalions(), 10);
        EXPECT_THROW(testMilitaryState->updateNumBattalions(15, false), std::runtime_error);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, setBattalions)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        std::vector<Battalion *> *testBattalions = new std::vector<Battalion *>();
        for (int i = 0; i < 10; i++)
            testBattalions->push_back(new Battalion());
        testMilitaryState->setBattalions(testBattalions);
        EXPECT_EQ(testMilitaryState->getNumBattalions(), 10);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumShipsPos)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumShips(10, true);
        EXPECT_EQ(testMilitaryState->getNumShips(), 10);
        testMilitaryState->updateNumShips(5, false);
        EXPECT_EQ(testMilitaryState->getNumShips(), 5);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumShipsNeg)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumShips(10, true);
        EXPECT_EQ(testMilitaryState->getNumShips(), 10);
        EXPECT_THROW(testMilitaryState->updateNumShips(15, false), std::runtime_error);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, setShips)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        std::vector<Ship *> *testShips = new std::vector<Ship *>();
        for (int i = 0; i < 10; i++)
            testShips->push_back(new Ship());
        testMilitaryState->setShips(testShips);
        EXPECT_EQ(testMilitaryState->getNumShips(), 10);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumPlanesPos)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumPlanes(10, true);
        EXPECT_EQ(testMilitaryState->getNumPlanes(), 10);
        testMilitaryState->updateNumPlanes(5, false);
        EXPECT_EQ(testMilitaryState->getNumPlanes(), 5);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, updateNumPlanesNeg)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        testMilitaryState->updateNumPlanes(10, true);
        EXPECT_EQ(testMilitaryState->getNumPlanes(), 10);
        EXPECT_THROW(testMilitaryState->updateNumPlanes(15, false), std::runtime_error);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, setPlanes)
    {
        MilitaryState *testMilitaryState = new MilitaryState();
        std::vector<Plane *> *testPlanes = new std::vector<Plane *>();
        for (int i = 0; i < 10; i++)
            testPlanes->push_back(new Plane());
        testMilitaryState->setPlanes(testPlanes);
        EXPECT_EQ(testMilitaryState->getNumPlanes(), 10);
        delete testMilitaryState;
    }

    TEST(MilitaryStateTest, cloneTest){
        MilitaryState *testMilitaryState1 = new MilitaryState();
        testMilitaryState1->updateNumTroops(1000, true);
        testMilitaryState1->updateNumTanks(10, true);
        testMilitaryState1->updateNumBattalions(10, true);
        testMilitaryState1->updateNumShips(10, true);
        testMilitaryState1->updateNumPlanes(10, true);
        MilitaryState *testMilitaryState2 = testMilitaryState1->clone();
        EXPECT_EQ(testMilitaryState1->getNumTroops(), testMilitaryState2->getNumTroops());
        EXPECT_EQ(testMilitaryState1->getNumTanks(), testMilitaryState2->getNumTanks());
        EXPECT_EQ(testMilitaryState1->getNumBattalions(), testMilitaryState2->getNumBattalions());
        EXPECT_EQ(testMilitaryState1->getNumShips(), testMilitaryState2->getNumShips());
        EXPECT_EQ(testMilitaryState1->getNumPlanes(), testMilitaryState2->getNumPlanes());
        EXPECT_NE(testMilitaryState1, testMilitaryState2);
        delete testMilitaryState1;
        delete testMilitaryState2;
    }
}