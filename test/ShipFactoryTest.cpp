#include <limits.h>
#include <stdexcept>
#include "../src/ShipFactory.h"
#include"../src/Ship.h"
#include "gtest/gtest.h"

namespace {
	TEST(ShipFactoryTest,creationOfObject){
    	ShipFactory* shipManufacture=new ShipFactory();
    	Ship* ship=static_cast<Ship*>(shipManufacture->manufactureVehicle());
    	ship->setNumShipDestroys(2);
    	EXPECT_EQ(ship->getShipDestroyed(),2);
    	delete shipManufacture;
    	delete ship;
    }
    
}