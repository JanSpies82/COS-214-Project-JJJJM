///@author Julian Pienaar
#include <limits.h>
#include <iostream>
#include <stdexcept>
#include "../src/Map.h"
#include "gtest/gtest.h"
using namespace std;

namespace
{
    TEST(MapTest, DefaultConstructor)
    {
        Map *m = new Map();
        delete m;
    }

    TEST(MapTest, CopyConstructor)
    {
        Map *m = new Map();
        Map *t = new Map(m);
        EXPECT_EQ(m->getLocation(0, 0)->getColor(), t->getLocation(0, 0)->getColor());
        delete m;
        delete t;
    }

    TEST(MapTest, getLocationNeg)
    {
        Map *m = new Map();
        EXPECT_THROW(m->getLocation(-1, 0), out_of_range);
        EXPECT_THROW(m->getLocation(0, -1), out_of_range);
        EXPECT_THROW(m->getLocation(0, 27), out_of_range);
        EXPECT_THROW(m->getLocation(24, 0), out_of_range);
        delete m;
    }

    TEST(MapTest, getLocationPos)
    {
        Map *m = new Map();
        EXPECT_NO_THROW(m->getLocation(0, 0));
        EXPECT_NO_THROW(m->getLocation(23, 26));
        delete m;
    }

    TEST(MapTest, printMap)
    {
        Map *m = new Map();
        m->printMap();
        delete m;
    }
}