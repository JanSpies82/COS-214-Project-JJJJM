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

        Location* middle=new Territory(1,1,0);
        Location* right=new Territory(2,1,0);
        
        middle->add(new RightNeighbour(right));

        EXPECT_EQ(middle->getRight(),right);

        delete right;
        delete middle;

    }

    TEST(TerritoryTest, BottomTest){
        Location* middle=new Territory(1,1,0);

        Location* bottom=new Territory(1,2,0);

        middle->add(new BottomNeighbour(bottom));

        EXPECT_EQ(middle->getBottom(),bottom);

        delete middle;
        delete bottom;
    }

    TEST(TerritoryTest, LeftTest){
        Location* middle=new Territory(1,1,0);

        Location* left=new Territory(0,1,0);

        middle->add(new LeftNeighbour(left));

        EXPECT_EQ(middle->getLeft(),left);

        delete middle;
        delete left;

    }

    TEST(TerritoryTest, TopTest){
        Location* middle=new Territory(1,1,0);

        Location* top=new Territory(1,0,0);

        

        middle->add(new TopNeighbour(top));



        EXPECT_EQ(middle->getTop(),top);

        delete middle;
        delete top;

    }

    TEST(TerritoryTest, TestAll){
        
        Location* middle=new Territory(1,1,0);
        Location* right=new Territory(2,1,0);
        Location* left=new Territory(0,1,0);
        Location* top=new Territory(1,0,0);
        Location* bottom=new Territory(1,2,0);
        Location* rightRight=new Territory(3,1,0);

        
        middle->add(new RightNeighbour(right));
        middle->add(new LeftNeighbour(left));
        middle->add(new BottomNeighbour(bottom));
        middle->add(new TopNeighbour(top));
        right->add(new RightNeighbour(rightRight));

        EXPECT_EQ(middle->getLeft(),left);

        EXPECT_EQ(middle->getRight(),right);

        EXPECT_EQ(middle->getTop(),top);

        EXPECT_EQ(middle->getBottom(),bottom);

        EXPECT_EQ(middle->getRight()->getRight(), rightRight);

        delete middle;
        delete right;
        delete left;
        delete top;
        delete bottom;
        delete rightRight;

    }
    
}

