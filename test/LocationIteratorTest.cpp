// #include <limits.h>
// #include <stdexcept>
// #include "../src/LocationIterator.h"
// #include "../src/Territory.h"
// #include "../src/LeftNeighbour.h"
// #include "../src/RightNeighbour.h"
// #include "../src/TopNeighbour.h"
// #include "../src/BottomNeighbour.h"
// #include "gtest/gtest.h"
// #include <iostream>

// class IteratorTest : public testing::Test
// {
// public:
//     virtual void SetUp() override
//     {
//         t00 = new Territory(0, 0);
//         t01 = new Territory(0, 1);
//         t02 = new Territory(0, 2);
//         t10 = new Territory(1, 0);
//         t11 = new Territory(1, 1);
//         t12 = new Territory(1, 2);
//         t20 = new Territory(2, 0);
//         t21 = new Territory(2, 1);
//         t22 = new Territory(2, 2);

//         t00->add(new RightNeighbour(t01));
//         t00->add(new BottomNeighbour(t10));

//         t01->add(new LeftNeighbour(t00));
//         t01->add(new RightNeighbour(t02));
//         t01->add(new BottomNeighbour(t11));

//         t02->add(new LeftNeighbour(t01));
//         t02->add(new BottomNeighbour(t12));

//         t10->add(new TopNeighbour(t00));
//         t10->add(new RightNeighbour(t11));
//         t10->add(new BottomNeighbour(t20));

//         t11->add(new TopNeighbour(t01));
//         t11->add(new LeftNeighbour(t10));
//         t11->add(new RightNeighbour(t12));
//         t11->add(new BottomNeighbour(t21));

//         t12->add(new TopNeighbour(t02));
//         t12->add(new LeftNeighbour(t11));
//         t12->add(new BottomNeighbour(t22));

//         t20->add(new TopNeighbour(t10));
//         t20->add(new RightNeighbour(t21));

//         t21->add(new TopNeighbour(t11));
//         t21->add(new LeftNeighbour(t20));
//         t21->add(new RightNeighbour(t22));

//         t22->add(new TopNeighbour(t12));
//         t22->add(new LeftNeighbour(t21));
//     }
//     virtual void TearDown() override
//     {
//         delete t00;
//         delete t01;
//         delete t02;
//         delete t10;
//         delete t11;
//         delete t12;
//         delete t20;
//         delete t21;
//         delete t22;
//     }

//     Location *t00;
//     Location *t01;
//     Location *t02;
//     Location *t10;
//     Location *t11;
//     Location *t12;
//     Location *t20;
//     Location *t21;
//     Location *t22;
// };

// namespace
// {
//     TEST_F(IteratorTest, Constructor)
//     {
//         Iterator *it = new LocationIterator(t00);
//         EXPECT_EQ(it->getCurrent(), t00);
//         EXPECT_EQ(it->isDone(), false);
//         delete it;
//     }
// }
// namespace
// {
//     TEST_F(IteratorTest, CreateIterator)
//     {
//         Iterator *it00 = t00->createIterator();
//         EXPECT_EQ(it00->getCurrent(), t00);
//         EXPECT_EQ(it00->isDone(), false);
//         delete it00;
//         Iterator *it01 = t01->createIterator();
//         EXPECT_EQ(it01->getCurrent(), t01);
//         EXPECT_EQ(it01->isDone(), false);
//         delete it01;
//         Iterator *it02 = t02->createIterator();
//         EXPECT_EQ(it02->getCurrent(), t02);
//         EXPECT_EQ(it02->isDone(), false);
//         delete it02;
//         Iterator *it10 = t10->createIterator();
//         EXPECT_EQ(it10->getCurrent(), t10);
//         EXPECT_EQ(it10->isDone(), false);
//         delete it10;
//         Iterator *it11 = t11->createIterator();
//         EXPECT_EQ(it11->getCurrent(), t11);
//         EXPECT_EQ(it11->isDone(), false);
//         delete it11;
//         Iterator *it12 = t12->createIterator();
//         EXPECT_EQ(it12->getCurrent(), t12);
//         EXPECT_EQ(it12->isDone(), false);
//         delete it12;
//         Iterator *it20 = t20->createIterator();
//         EXPECT_EQ(it20->getCurrent(), t20);
//         EXPECT_EQ(it20->isDone(), false);
//         delete it20;
//         Iterator *it21 = t21->createIterator();
//         EXPECT_EQ(it21->getCurrent(), t21);
//         EXPECT_EQ(it21->isDone(), false);
//         delete it21;
//         Iterator *it22 = t22->createIterator();
//         EXPECT_EQ(it22->getCurrent(), t22);
//         EXPECT_EQ(it22->isDone(), true);
//         delete it22;
//     }
// }

// namespace
// {
//     TEST_F(IteratorTest, First)
//     {
//         Iterator *it00 = t00->createIterator();
//         Iterator *it01 = t01->createIterator();
//         Iterator *it02 = t02->createIterator();
//         Iterator *it10 = t10->createIterator();
//         Iterator *it11 = t11->createIterator();
//         Iterator *it12 = t12->createIterator();
//         Iterator *it20 = t20->createIterator();
//         Iterator *it21 = t21->createIterator();
//         Iterator *it22 = t22->createIterator();

//         it00->first();
//         it01->first();
//         it02->first();
//         it10->first();
//         it11->first();
//         it12->first();
//         it20->first();
//         it21->first();
//         it22->first();

//         EXPECT_EQ(it00->getCurrent(), t00);
//         EXPECT_EQ(it00->isDone(), false);
//         EXPECT_EQ(it01->getCurrent(), t00);
//         EXPECT_EQ(it01->isDone(), false);
//         EXPECT_EQ(it02->getCurrent(), t00);
//         EXPECT_EQ(it02->isDone(), false);
//         EXPECT_EQ(it10->getCurrent(), t00);
//         EXPECT_EQ(it10->isDone(), false);
//         EXPECT_EQ(it11->getCurrent(), t00);
//         EXPECT_EQ(it11->isDone(), false);
//         EXPECT_EQ(it12->getCurrent(), t00);
//         EXPECT_EQ(it12->isDone(), false);
//         EXPECT_EQ(it20->getCurrent(), t00);
//         EXPECT_EQ(it20->isDone(), false);
//         EXPECT_EQ(it21->getCurrent(), t00);
//         EXPECT_EQ(it21->isDone(), false);
//         EXPECT_EQ(it22->getCurrent(), t00);
//         EXPECT_EQ(it22->isDone(), false);

//         delete it00;
//         delete it01;
//         delete it02;
//         delete it10;
//         delete it11;
//         delete it12;
//         delete it20;
//         delete it21;
//         delete it22;
//     }
// }
// namespace
// {
//     TEST_F(IteratorTest, NextPos)
//     {
//         Iterator *it00 = t00->createIterator();

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t01);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t02);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t12);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t11);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t10);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t20);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t21);
//         EXPECT_EQ(it00->isDone(), false);

//         it00->next();
//         EXPECT_EQ(it00->getCurrent(), t22);
//         EXPECT_EQ(it00->isDone(), true);

//         delete it00;
//     }
// }

// namespace
// {
//     TEST_F(IteratorTest, NextNeg)
//     {
//         Iterator *it = t00->createIterator();

//         while (!it->isDone())
//             it->next();

//         try
//         {
//             it->next();
//             FAIL()<< "Did not throw exception";
//         }
//         catch (std::out_of_range &e)
//         {
//             EXPECT_EQ(e.what(), std::string("No next location"));
//         }
//         catch (...)
//         {
//             FAIL()<< "Threw wrong exception";
//         }
//         delete it;
//     }
// }
