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

    TEST(TerritoryTest, ExtensiveTest){
        Location* t00=new Territory(0,0,0);
        Location* t10=new Territory(1,0,0);
        Location* t20=new Territory(2,0,0);
        Location* t01=new Territory(0,1,0);
        Location* t11=new Territory(1,1,0);
        Location* t21=new Territory(2,1,0);
        Location* t02=new Territory(0,2,0);
        Location* t12=new Territory(1,2,0);
        Location* t22=new Territory(2,2,0);

        t00->add(new RightNeighbour(t10));
        t10->add(new RightNeighbour(t20));
        t01->add(new RightNeighbour(t11));
        t11->add(new RightNeighbour(t21));
        t02->add(new RightNeighbour(t12));
        t12->add(new RightNeighbour(t22));

        t00->add(new BottomNeighbour(t01));
        t01->add(new BottomNeighbour(t02));
        t10->add(new BottomNeighbour(t11));
        t11->add(new BottomNeighbour(t12));
        t20->add(new BottomNeighbour(t21));
        t21->add(new BottomNeighbour(t22));

        t10->add(new LeftNeighbour(t00));
        t20->add(new LeftNeighbour(t10));
        t11->add(new LeftNeighbour(t01));
        t21->add(new LeftNeighbour(t11));
        t12->add(new LeftNeighbour(t02));
        t22->add(new LeftNeighbour(t12));

        t01->add(new TopNeighbour(t00));
        t02->add(new TopNeighbour(t01));
        t11->add(new TopNeighbour(t10));
        t12->add(new TopNeighbour(t11));
        t21->add(new TopNeighbour(t20));
        t22->add(new TopNeighbour(t21));

        // t12->add(new RightNeighbour(t00));
        // t12->add(new RightNeighbour(t22));
        // t12->add(new RightNeighbour(t12));
        

        delete t00;
        delete t10;
        delete t20;
        delete t01;
        delete t11;
        delete t21;
        delete t02;
        delete t12;
        delete t22;
    }
    
}

