///@author Janco Spies
#include <limits.h>
#include <stdexcept>
#include "../src/SimulationState.h"
#include "../src/MapState.h"
#include "../src/Map.h"
#include "../src/Superpower.h"
#include "../src/SuperpowerState.h"
#include "../src/StageContext.h"
#include "../src/StageContextState.h"
#include "gtest/gtest.h"

namespace {
    TEST(SimulationStateTest, Constructor) {
        SimulationState* simulationState = new SimulationState();
        EXPECT_EQ(simulationState->getSuperpowerStateCount(), 0);
        delete simulationState;
    }

    TEST(SimulationStateTest, getMapStatePos){
        SimulationState* simulationState = new SimulationState();
        Map* m = new Map();
        MapState* mapState1 = new MapState(m);
        simulationState->setMapState(mapState1);
        EXPECT_EQ(simulationState->getMapState(), mapState1);
        MapState* mapState2 = new MapState(m);
        simulationState->setMapState(mapState2);
        EXPECT_EQ(simulationState->getMapState(), mapState2);
        delete simulationState;
        delete m;
    }

    TEST(SimulationStateTest, getMapStateNeg){
        SimulationState* simulationState = new SimulationState();
        EXPECT_THROW(simulationState->getMapState(), std::out_of_range);
        delete simulationState;
    }

    TEST(SimulationStateTest, getStageContextStatePos){
        SimulationState* simulationState = new SimulationState();
        StageContextState *stageContextState1 = StageContext::getInstance()->getState();
        simulationState->setStageContextState(stageContextState1);
        EXPECT_EQ(simulationState->getStageContextState(), stageContextState1);
        StageContextState* stageContextState2 = StageContext::getInstance()->getState();
        simulationState->setStageContextState(stageContextState2);
        EXPECT_EQ(simulationState->getStageContextState(), stageContextState2);
        delete simulationState;
        delete StageContext::getInstance();
    }

    TEST(SimulationStateTest, getStageContextStateNeg){
        SimulationState* simulationState = new SimulationState();
        EXPECT_THROW(simulationState->getStageContextState(), std::out_of_range);
        delete simulationState;
    }

    TEST(SimulationStateTest, getSuperpowerStateCount){
        SimulationState* simulationState = new SimulationState();
        EXPECT_EQ(simulationState->getSuperpowerStateCount(), 0);
        simulationState->addSuperpowerState(new SuperpowerState(""));
        EXPECT_EQ(simulationState->getSuperpowerStateCount(), 1);
        simulationState->addSuperpowerState(new SuperpowerState(""));
        EXPECT_EQ(simulationState->getSuperpowerStateCount(), 2);
        delete simulationState;
    }

    TEST(SimulationStateTest, getSuperpowerStatePos){
        SimulationState* simulationState = new SimulationState();
        SuperpowerState* superpowerState1 = new SuperpowerState("");
        simulationState->addSuperpowerState(superpowerState1);
        EXPECT_EQ(simulationState->getSuperpowerState(0), superpowerState1);
        SuperpowerState* superpowerState2 = new SuperpowerState("");
        simulationState->addSuperpowerState(superpowerState2);
        EXPECT_EQ(simulationState->getSuperpowerState(1), superpowerState2);
        delete simulationState;
    }

    TEST(SimulationStateTest, getSuperpowerStateNeg){
        SimulationState* simulationState = new SimulationState();
        EXPECT_THROW(simulationState->getSuperpowerState(0), std::out_of_range);
        simulationState->addSuperpowerState(new SuperpowerState(""));
        EXPECT_THROW(simulationState->getSuperpowerState(1), std::out_of_range);
        EXPECT_THROW(simulationState->getSuperpowerState(-1), std::out_of_range);
        delete simulationState;
    }
}