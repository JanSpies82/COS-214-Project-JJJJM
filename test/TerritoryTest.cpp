#include <iostream>
#include <limits.h>
#include <stdexcept>
#include "../src/Territory.h"
#include "../src/RightNeighbour.h"
#include "../src/LeftNeighbour.h"
#include "../src/BottomNeighbour.h"
#include "../src/TopNeighbour.h"
#include "gtest/gtest.h"

namespace {

    TEST(TerritoryTest, RightTest){

        Location* middle=new Territory(1,1);
        Location* right=new Territory(2,1);
        
        middle=new RightNeighbour(middle,right);

        EXPECT_EQ(middle->getRight(),right);

        delete right;
        delete middle;

    }

    TEST(TerritoryTest, BottomTest){
        Location* middle=new Territory(1,1);

        Location* bottom=new Territory(1,2);

        middle=new BottomNeighbour(middle,bottom);

        EXPECT_EQ(middle->getBottom(),bottom);

        delete middle;
        delete bottom;
    }

    TEST(TerritoryTest, LeftTest){
        Location* middle=new Territory(1,1);

        Location* left=new Territory(0,1);

        middle=new LeftNeighbour(middle,left);

        EXPECT_EQ(middle->getLeft(),left);

        delete middle;
        delete left;

    }

    TEST(TerritoryTest, TopTest){
        Location* middle=new Territory(1,1);

        Location* top=new Territory(1,0);

        

        middle=new TopNeighbour(middle,top);



        EXPECT_EQ(middle->getTop(),top);

        delete middle;
        delete top;

    }

    TEST(TerritoryTest, TestAll){
        
        Location* middle=new Territory(1,1);
        Location* right=new Territory(2,1);
        Location* left=new Territory(0,1);
        Location* top=new Territory(1,0);
        Location* bottom=new Territory(1,2);

        
        middle=new RightNeighbour(middle,right);
        middle=new LeftNeighbour(middle,left);
        middle=new BottomNeighbour(middle,bottom);
        middle=new TopNeighbour(middle,top);

        EXPECT_EQ(middle->getRight(),right);

        EXPECT_EQ(middle->getLeft(),left);

        EXPECT_EQ(middle->getTop(),top);

        EXPECT_EQ(middle->getBottom(),bottom);

        delete middle;
        delete right;
        delete left;
        delete top;
        delete bottom;

    }
    
}

