///@author Julian Pienaar
#include <limits.h>
#include <stdexcept>
#include "../src/MapState.h"
#include "gtest/gtest.h"

namespace {
    TEST(MapStateTest, TestMapState){
        Map* m=new Map();
        MapState* ms=new MapState(m);
        Map* mc=ms->clone();
        delete mc;
        delete ms;
        delete m;
    }
    
}