#include <limits.h>
#include <stdexcept>
#include "../src/Tank.h"
#include "../src/Battalion.h"
#include "gtest/gtest.h"

namespace {

    TEST(tankTest,setterGetter){
		Tank* army=new Tank();
		
		army->setNumTankDetroys(0);
		army->setNumBattalionDestroys(1);

		EXPECT_EQ(army->getTankDestroyed(),0);
		EXPECT_EQ(army->getBattalionDestroyed(),1);
    	delete army;
	}
}