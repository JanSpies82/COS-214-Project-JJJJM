#include <limits.h>
#include <stdexcept>
#include "../src/Superpower.h"
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

}