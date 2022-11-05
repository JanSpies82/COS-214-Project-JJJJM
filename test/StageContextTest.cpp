///@author Mekhail Muller
#include <limits.h>
#include <stdexcept>
#include "../src/StageContext.h"
#include "../src/StageContextState.h"
#include "../src/MiddleStage.h"
#include "gtest/gtest.h"

namespace
{
    TEST(StageContextTest, getInstance)
    {
        StageContext *stageContext1 = StageContext::getInstance();
        StageContext *stageContext2 = StageContext::getInstance();
        EXPECT_EQ(stageContext1, stageContext2);
        delete stageContext1;
    }

    TEST(StageContextTest, getState)
    {
        StageContextState *state = StageContext::getInstance()->getState();
        EXPECT_EQ(state->getSimulationLength(), 0);
        EXPECT_EQ(state->getCurrentRound(), 0);
        delete StageContext::getInstance();
        delete state;
    }

    TEST(StageContextTest, setState)
    {
        StageContextState *state = new StageContextState();
        state->setSimulationLength(10);
        state->setCurrentRound(5);
        state->setCurrentStage(new MiddleStage());

        StageContext::getInstance()->setState(state);
        EXPECT_EQ(StageContext::getInstance()->getCurrentRound(), 5);
        EXPECT_EQ(StageContext::getInstance()->getSimulationLength(), 10);
        delete StageContext::getInstance();
        delete state;
    }

    TEST(StageContextTest, incrementRound)
    {
        StageContext::getInstance()->setSimulationLength(10);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getCurrentRound(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getCurrentRound(), 2);
        delete StageContext::getInstance();
    }

    TEST(StageContextTest, switchStage)
    {
        StageContext::getInstance()->setSimulationLength(10);
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 0);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 0);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 0);

        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);
        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 1);

        StageContext::getInstance()->incrementRound();
        EXPECT_EQ(StageContext::getInstance()->getWarStage(), 2);
        delete StageContext::getInstance();
    }
}