#include <limits.h>
#include <stdexcept>
#include "../src/SimulationState.h"
#include "../src/MapState.h"
#include "../src/CountryState.h"
#include "../src/MilitaryState.h"
#include "gtest/gtest.h"


// class IteratorTest : public testing::Test
// {
// public:
//     virtual void SetUp() override
//     {
//         map = new Map();
//         // country = new Country();
//         // military = new Military();
//         mapState = new MapState(map);
//     }
//     virtual void TearDown() override
//     {
//         delete map;
//         // delete country;
//         // delete military;
//     }

//     Map* map;
//     Country* country;
//     Military* military;
//     MapState* mapState;
//     CountryState* countryState;
//     MilitaryState* militaryState;
// };

namespace
{
    // class FakeMapState : public MapState
    // {
    // public:
    //     FakeMapState() : MapState(NULL) {}
    // };
    class FakeCountryState : public CountryState
    {
    public:
        FakeCountryState() : CountryState(NULL) {}
    };
    class FakeMilitaryState : public MilitaryState
    {
    public:
        FakeMilitaryState() : MilitaryState(NULL) {}
    };

    TEST(SimulationStateTest, Constructor)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        EXPECT_EQ(simulationState->getTimestamp(), time(0));
        EXPECT_EQ(simulationState->getCountryStateCount(), 0);
        EXPECT_EQ(simulationState->getCountryStateCount(), 0);
        delete simulationState;
    }

    TEST(SimulationStateTest, SetMapState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        Map* m1 = new Map();
        MapState *map1 = new MapState(m1);
        simulationState->setMapState(map1);
        EXPECT_EQ(simulationState->getMapState(), map1);
        Map *m2 = new Map();
        MapState *map2 = new MapState(m2);
        simulationState->setMapState(map2);
        EXPECT_EQ(simulationState->getMapState(), map2);
        delete simulationState;
        delete m1;
        delete m2;
    }

    TEST(SimulationStateTest, GetMapState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        EXPECT_THROW(simulationState->getMapState(), std::out_of_range);
        Map* m1 = new Map();
        MapState *map1 = new MapState(m1);
        simulationState->setMapState(map1);
        EXPECT_EQ(simulationState->getMapState(), map1);
        delete simulationState;
        delete m1;
    }

    TEST(SimulationStateTest, AddCountryState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        CountryState *countryState1 = new FakeCountryState();
        simulationState->addCountryState(countryState1);
        EXPECT_EQ(simulationState->getCountryStateCount(), 1);
        EXPECT_EQ(simulationState->getCountryState(0), countryState1);
        CountryState *countryState2 = new FakeCountryState();
        simulationState->addCountryState(countryState2);
        EXPECT_EQ(simulationState->getCountryStateCount(), 2);
        EXPECT_EQ(simulationState->getCountryState(0), countryState1);
        EXPECT_EQ(simulationState->getCountryState(1), countryState2);
        delete simulationState;
    }

    TEST(SimulationStateTest, GetCountryState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        EXPECT_THROW(simulationState->getCountryState(0), std::out_of_range);
        CountryState *countryState1 = new FakeCountryState();
        simulationState->addCountryState(countryState1);
        EXPECT_EQ(simulationState->getCountryState(0), countryState1);
        EXPECT_THROW(simulationState->getCountryState(1), std::out_of_range);
        CountryState *countryState2 = new FakeCountryState();
        simulationState->addCountryState(countryState2);
        EXPECT_EQ(simulationState->getCountryState(0), countryState1);
        EXPECT_EQ(simulationState->getCountryState(1), countryState2);
        EXPECT_THROW(simulationState->getCountryState(2), std::out_of_range);
        delete simulationState;
    }

    TEST(SimulationStateTest, AddMilitaryState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        MilitaryState *militaryState1 = new FakeMilitaryState();
        simulationState->addMilitaryState(militaryState1);
        EXPECT_EQ(simulationState->getMilitaryStateCount(), 1);
        EXPECT_EQ(simulationState->getMilitaryState(0), militaryState1);
        MilitaryState *militaryState2 = new FakeMilitaryState();
        simulationState->addMilitaryState(militaryState2);
        EXPECT_EQ(simulationState->getMilitaryStateCount(), 2);
        EXPECT_EQ(simulationState->getMilitaryState(0), militaryState1);
        EXPECT_EQ(simulationState->getMilitaryState(1), militaryState2);
        delete simulationState;
    }

    TEST(SimulationStateTest, GetMilitaryState)
    {
        SimulationState *simulationState = new SimulationState(NULL);
        EXPECT_THROW(simulationState->getMilitaryState(0), std::out_of_range);
        MilitaryState *militaryState1 = new FakeMilitaryState();
        simulationState->addMilitaryState(militaryState1);
        EXPECT_EQ(simulationState->getMilitaryState(0), militaryState1);
        EXPECT_THROW(simulationState->getMilitaryState(1), std::out_of_range);
        MilitaryState *militaryState2 = new FakeMilitaryState();
        simulationState->addMilitaryState(militaryState2);
        EXPECT_EQ(simulationState->getMilitaryState(0), militaryState1);
        EXPECT_EQ(simulationState->getMilitaryState(1), militaryState2);
        EXPECT_THROW(simulationState->getMilitaryState(2), std::out_of_range);
        delete simulationState;
    }
}