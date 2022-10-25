#include <limits.h>
#include <stdexcept>
#include "../src/Memento.h"
#include "../src/SimulationState.h"
#include "gtest/gtest.h"

namespace
{
    TEST(MementoTest, Constructor)
    {
        Memento *memento = new Memento();
        try
        {
            memento->getState();
            FAIL() << "Expected std::out_of_range";
        }
        catch (std::out_of_range const &err)
        {
            EXPECT_EQ(err.what(), std::string("Memento does not hold a SimulationState"));
        }
        catch (...)
        {
            FAIL() << "Expected std::out_of_range";
        }
        delete memento;
    }

    TEST(MementoTest, Destructor)
    {
        Memento *memento = new Memento();
        delete memento;
    }

    TEST(MementoTest, GetStateNotSet)
    {
        Memento *memento = new Memento();
        try
        {
            memento->getState();
            FAIL() << "Expected std::out_of_range";
        }
        catch (std::out_of_range const &err)
        {
            EXPECT_EQ(err.what(), std::string("Memento does not hold a SimulationState"));
        }
        catch (...)
        {
            FAIL() << "Expected std::out_of_range";
        }
        delete memento;
    }

    TEST(MementoTest, GetStateSet)
    {
        Memento *memento = new Memento();
        SimulationState *simulationState = new SimulationState(NULL);
        memento->setState(simulationState);
        EXPECT_EQ(memento->getState(), simulationState);
        delete memento;
    }

}