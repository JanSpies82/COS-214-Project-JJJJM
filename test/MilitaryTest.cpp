#include <limits.h>
#include<iostream>
#include <stdexcept>
#include "../src/Military.h"
#include "../src/Battalion.h"
#include "../src/Plane.h"
#include "../src/Ship.h"
#include "../src/Tank.h"
#include "../src/Country.h"
#include "../src/VehicleFactory.h"
#include "../src/Vehicle.h"
#include "gtest/gtest.h"

namespace {
	TEST(MilitaryTest,defaultConstructor){

		Military * military=new Military();
		EXPECT_EQ(military->getMilitary(),military);
		EXPECT_EQ(military->getNumBattalions(),0);
		EXPECT_EQ(military->getNumTanks(),0);
		EXPECT_EQ(military->getNumPlanes(),0);
		EXPECT_EQ(military->getNumShips(),0);
		delete military;
	}

	TEST(MilitaryTest,destructor){
		Military * military=new Military();
		delete military;
	}
    
   TEST(MilitaryTest,insertShips){
   		Military * military=new Military();
		EXPECT_EQ(military->getNumShips(),0);
		Ship* boat=new Ship();
		military->insertShips(boat);
		EXPECT_EQ(military->getNumShips(),1);
		Ship* boat2=new Ship();
		military->insertShips(boat2);
		EXPECT_EQ(military->getNumShips(),2);
		delete military;
	
	}

	TEST(MilitaryTest,insertPlane){
   		Military * military=new Military();
		EXPECT_EQ(military->getNumPlanes(),0);
		Plane* NASA=new Plane();
		military->insertPlanes(NASA);
		EXPECT_EQ(military->getNumPlanes(),1);
		Plane* NASA2=new Plane();
		military->insertPlanes(NASA2);
		EXPECT_EQ(military->getNumPlanes(),2);
		delete military;
		
	}

	TEST(MilitaryTest,insertTanks){
   		Military * military=new Military();
		EXPECT_EQ(military->getNumTanks(),0);
		Tank* rocker=new Tank();
		military->insertTanks(rocker);
		EXPECT_EQ(military->getNumTanks(),1);
		Tank* rocker2=new Tank();
		military->insertTanks(rocker2);
		EXPECT_EQ(military->getNumTanks(),2);
		delete military;
		
	}

	TEST(MilitaryTest,getMilitary){
		Military * military=new Military();
		EXPECT_EQ(military->getMilitary(),military);
		delete military;
	}

	TEST(MilitaryTest,TestPreconditionNullptr){
		Military* military=new Military();
		try{
			military->insertPlanes(NULL);
			FAIL()<<"Expected std::invalid_argument";
		}catch(std::invalid_argument & err){
			EXPECT_EQ(err.what(),std::string("NULL plane error"));
		}catch(...){
			FAIL();
		}
	}

}