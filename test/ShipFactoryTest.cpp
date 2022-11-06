//@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/ShipFactory.h"
#include "gtest/gtest.h"

namespace {

    TEST(shipFactoryTest,creationOfObject){
    	ShipFactory* shipManufacture=new ShipFactory();
    	EXPECT_EQ(shipManufacture->manufactureVehicle()!=NULL,true);
    	EXPECT_EQ(shipManufacture->clone()!=NULL,true);
    	delete shipManufacture;
    	
    }
}