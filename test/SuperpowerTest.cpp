#include <limits.h>
#include <stdexcept>
#include "../src/Superpower.h"
#include "../src/SuperpowerState.h"
#include "../src/Country.h"
#include "gtest/gtest.h"

namespace
{
    TEST(SuperpowerTest, Constructor)
    {
        Superpower *superpower = new Superpower("Superpower");
        EXPECT_EQ("Superpower", superpower->getName());
        EXPECT_EQ(0, superpower->getCountryCount());
        delete superpower;
    }

    TEST(SuperpowerTest, addCountry)
    {
        Superpower *superpower = new Superpower("Superpower");
        Country *country1 = new Country("");
        superpower->addCountry(country1);
        EXPECT_EQ(1, superpower->getCountryCount());
        Country *country2 = new Country("");
        superpower->addCountry(country2);
        EXPECT_EQ(2, superpower->getCountryCount());
        delete superpower;
    }

    TEST(SuperpowerTest, getCountryPos)
    {
        Superpower *superpower = new Superpower("Superpower");
        Country *country1 = new Country("");
        Country *country2 = new Country("");
        superpower->addCountry(country1);
        superpower->addCountry(country2);
        EXPECT_EQ(country1, superpower->getCountry(0));
        EXPECT_EQ(country2, superpower->getCountry(1));
        delete superpower;
    }

    TEST(SuperpowerTest, getCountryNeg)
    {
        Superpower *superpower = new Superpower("Superpower");
        Country *country1 = new Country("");
        Country *country2 = new Country("");
        try
        {
            superpower->getCountry(0);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Index out of range"), e.what());
        }
        superpower->addCountry(country1);
        superpower->addCountry(country2);
        try
        {
            superpower->getCountry(-1);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Index out of range"), e.what());
        }
        try
        {
            superpower->getCountry(2);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Index out of range"), e.what());
        }
        delete superpower;
    }

    TEST(SuperpowerTest, removeCountryPos)
    {
        Superpower *superpower = new Superpower("Superpower");
        Country *country1 = new Country("");
        Country *country2 = new Country("");
        superpower->addCountry(country1);
        superpower->addCountry(country2);
        superpower->removeCountry(country1);
        EXPECT_EQ(1, superpower->getCountryCount());
        EXPECT_EQ(country2, superpower->getCountry(0));
        superpower->removeCountry(country2);
        EXPECT_EQ(0, superpower->getCountryCount());
        delete superpower;
        delete country1;
        delete country2;
    }

    TEST(SuperpowerTest, removeCountryNeg)
    {
        Superpower *superpower = new Superpower("Superpower");
        Country *country1 = new Country("");
        Country *country2 = new Country("");
        try
        {
            superpower->removeCountry(NULL);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Country not owned by superpower"), e.what());
        }
        try
        {
            superpower->removeCountry(country1);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Country not owned by superpower"), e.what());
        }
        superpower->addCountry(country1);
        superpower->addCountry(country2);
        try
        {
            superpower->removeCountry(country1);
            superpower->removeCountry(country1);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Country not owned by superpower"), e.what());
        }
        try
        {
            superpower->removeCountry(NULL);
            FAIL();
        }
        catch (std::out_of_range &e)
        {
            EXPECT_EQ(std::string("Country not owned by superpower"), e.what());
        }
        delete superpower;
        delete country1;
    }

    TEST(SuperpowerTest, getState)
    {
        Superpower *superpower1 = new Superpower("Superpower");
        Country *country1 = new Country("");
        Country *country2 = new Country("");
        superpower1->addCountry(country1);
        superpower1->addCountry(country2);
        SuperpowerState *state = superpower1->getState();
        Superpower *superpower2 = new Superpower(state);
        EXPECT_EQ(superpower1->getName(), superpower2->getName());
        EXPECT_EQ(superpower1->getCountryCount(), superpower2->getCountryCount());
        for (int i = 0; i < superpower1->getCountryCount(); i++)
            EXPECT_EQ(superpower1->getCountry(i)->getName(), superpower2->getCountry(i)->getName());
        delete superpower1;
        delete superpower2;
        delete state;
    }

}