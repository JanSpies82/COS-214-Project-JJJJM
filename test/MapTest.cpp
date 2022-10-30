#include <limits.h>
#include <iostream>
#include <stdexcept>
#include "../src/Map.h"
#include "gtest/gtest.h"
using namespace std;

namespace {
TEST(MapTest, Constructor){
    Map* m=new Map();
    Map* t=new Map(m);
    Map* k=new Map(t);

    m->printMap();

    EXPECT_ANY_THROW(k->getLocation(24,0));
    EXPECT_ANY_THROW(k->getLocation(-1,0));
    EXPECT_ANY_THROW(k->getLocation(0,27));
    EXPECT_ANY_THROW(k->getLocation(0,-1));

    EXPECT_NO_THROW(k->getLocation(0,0));
    EXPECT_NO_THROW(k->getLocation(23,26));

    delete m;
    delete t;
    delete k;
}
    
}