#include <limits.h>
#include <stdexcept>
#include "../src/Map.h"
#include "gtest/gtest.h"

namespace {
TEST(MapTest, Constructor){
    Map* m=new Map();
    delete m;
}
    
}