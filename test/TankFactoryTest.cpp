#include <limits.h>
#include <stdexcept>
#include "../src/TankFactory.h"
#include"../src/Tank.h"
#include "gtest/gtest.h"

namespace {

	TEST(TankFactoryTest,creationOfObject){
    	TankFactory* tankManufacture=new TankFactory();
    	Tank* tank=static_cast<Tank*>(tankManufacture->manufactureVehicle());
    	tank->setNumTankDetroys(2);
    	EXPECT_EQ(tank->getTankDestroyed(),2);
    	delete tankManufacture;
    	delete tank;
    }
    
}