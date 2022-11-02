#include <limits.h>
#include <stdexcept>
#include "../src/Ship.h"
#include "../src/Battalion.h"
#include "../src/Vehicle.h"
#include "gtest/gtest.h"

namespace {
	TEST(ShipTest,setterGetter){
		Ship* army=new Ship();
		
		army->setNumShipDestroys(0);
		army->setNumBattalionDestroys(1);

		EXPECT_EQ(army->getShipDestroyed(),0);
		EXPECT_EQ(army->getBattalionDestroyed(),1);
    	delete army;
	}
}