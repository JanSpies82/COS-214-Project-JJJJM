///@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/PlaneFactory.h"
#include "gtest/gtest.h"

namespace {
	TEST(PlaneFactoryTest,creationOfObject){
    	PlaneFactory* planeManufacture=new PlaneFactory();
    	EXPECT_EQ(planeManufacture->manufactureVehicle()!=NULL,true);
    	EXPECT_EQ(planeManufacture->clone()!=NULL,true);
    	delete planeManufacture;
    	
    }
    
}