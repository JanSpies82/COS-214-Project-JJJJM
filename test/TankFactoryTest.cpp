//@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/TankFactory.h"
#include "gtest/gtest.h"

namespace {


    TEST(TankFactoryTest,creationOfObject){
    	TankFactory* tankManufacture=new TankFactory();
    	EXPECT_EQ(tankManufacture->manufactureVehicle()!=NULL,true);
    	EXPECT_EQ(tankManufacture->clone()!=NULL,true);
    	delete tankManufacture;
    	
    }

}