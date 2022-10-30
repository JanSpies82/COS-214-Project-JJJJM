#include <limits.h>
#include <iostream>
#include <stdexcept>
#include "../src/Map.h"
#include "gtest/gtest.h"

namespace {
TEST(MapTest, Constructor){
    Map* m=new Map();
    // m->printMap();
    // Location* l=m->getTopLeft();
    // int i=0;
    // while(l->hasRight()){
    //     std::cout<<i++;
    //     l=l->getRight();
    // }
    delete m;
}
    
}