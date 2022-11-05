///@author Julian Pienaar

#include <iostream>
#include <limits.h>
#include <stdexcept>
#include "../src/Territory.h"
#include "../src/Country.h"
#include "../src/LocationObserver.h"
#include "gtest/gtest.h"

namespace {

    TEST(LocationObserverTest, attachTestSingleLocation)
    {
        Location* l=new Territory(0, 0, "\x1B[102m");
        Country* c=new Country("Country A");

        c->setColor("\x1B[46m");
        l->setOwnedBy(c);

        EXPECT_EQ("\x1B[46m", l->getColor());
        EXPECT_EQ(c, l->getOwnedBy());

        delete c;

        EXPECT_EQ("\x1B[100m", l->getColor());
        EXPECT_EQ(NULL, l->getOwnedBy());

        delete l;

    }

    TEST(LocationObserverTest, attachTestMultipleLocations)
    {
        Location* l0=new Territory(0, 0, "\x1B[102m");
        Location* l1=new Territory(1, 0, "\x1B[102m");
        Location* l2=new Territory(2, 0, "\x1B[102m");
        Location* l3=new Territory(3, 0, "\x1B[102m");

        Country* c=new Country("Country A");
        c->setColor("\x1B[46m");

        l0->setOwnedBy(c);
        l1->setOwnedBy(c);
        l2->setOwnedBy(c);
        l3->setOwnedBy(c);

        EXPECT_EQ("\x1B[46m", l0->getColor());
        EXPECT_EQ("\x1B[46m", l1->getColor());
        EXPECT_EQ("\x1B[46m", l2->getColor());
        EXPECT_EQ("\x1B[46m", l3->getColor());

        EXPECT_EQ(c, l0->getOwnedBy());
        EXPECT_EQ(c, l1->getOwnedBy());
        EXPECT_EQ(c, l2->getOwnedBy());
        EXPECT_EQ(c, l3->getOwnedBy());

        delete c;

        EXPECT_EQ("\x1B[100m", l0->getColor());
        EXPECT_EQ("\x1B[100m", l1->getColor());
        EXPECT_EQ("\x1B[100m", l2->getColor());
        EXPECT_EQ("\x1B[100m", l3->getColor());

        EXPECT_EQ(NULL, l0->getOwnedBy());
        EXPECT_EQ(NULL, l1->getOwnedBy());
        EXPECT_EQ(NULL, l2->getOwnedBy());
        EXPECT_EQ(NULL, l3->getOwnedBy());

        delete l0;
        delete l1;
        delete l2;
        delete l3;

    }

    TEST(LocationObserverTest, detachTest)
    {
        Location* l=new Territory(0, 0, "\x1B[102m");
        Country* a=new Country("Country A");
        Country* b=new Country("Country B");

        a->setColor("\x1B[46m");
        b->setColor("\x1B[107m");


        l->setOwnedBy(a);

        EXPECT_EQ("\x1B[46m", l->getColor());
        EXPECT_EQ(a, l->getOwnedBy());

        l->setOwnedBy(b);

        delete a;

        EXPECT_EQ(b, l->getOwnedBy());
        EXPECT_EQ("\x1B[107m", l->getColor());

        delete b;
        delete l;

    }
    

}

