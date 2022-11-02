#include <limits.h>
#include <stdexcept>
#include "../src/Plane.h"
#include"../src/Military.h"
#include"../src/Battalion.h"
#include"../src/Tank.h"
#include "gtest/gtest.h"

namespace {
	TEST(PlaneTest,setterGetter){
		Plane* army=new Plane();
		army->setNumPlanesDestroys(2);
		army->setNumTankDetroys(0);
		army->setNumBattalionDestroys(1);

		EXPECT_EQ(army->getPlanesDestroyed(),2);
		EXPECT_EQ(army->getTankDestroyed(),0);
		EXPECT_EQ(army->getBattalionDestroyed(),1);
    	delete army;
	}
	
}