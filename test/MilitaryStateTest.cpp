#include <limits.h>
#include<iostream>
#include <stdexcept>
#include "../src/MilitaryState.h"
#include "../src/Military.h"
#include "../src/Battalion.h"
#include "../src/Plane.h"
#include "../src/Ship.h"
#include "../src/Tank.h"
#include "../src/Country.h"
#include "gtest/gtest.h"

namespace {

    TEST(MilitaryStateTest,constructor){
    	Military* military=new Military();
    	MilitaryState * generalOfficer=new MilitaryState(military);
    	EXPECT_EQ(generalOfficer->getState(),military);
    	delete generalOfficer;
    	delete military;
    }

    TEST(MilitaryStateTest,numTanks){
   		Military * military=new Military();
   		MilitaryState * generalOfficer=new MilitaryState(military);
		EXPECT_EQ(generalOfficer->getNumTanks(),0);
		Tank* rocker=new Tank();
		military->insertTanks(rocker);
		EXPECT_EQ(generalOfficer->getNumTanks(),1);
		Tank* rocker2=new Tank();
		military->insertTanks(rocker2);
		EXPECT_EQ(generalOfficer->getNumTanks(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,numPlanes){
   		Military * military=new Military();
   		MilitaryState * generalOfficer=new MilitaryState(military);
		EXPECT_EQ(generalOfficer->getNumPlanes(),0);
		Plane* rocker=new Plane();
		military->insertPlanes(rocker);
		EXPECT_EQ(generalOfficer->getNumPlanes(),1);
		Plane* rocker2=new Plane();
		military->insertPlanes(rocker2);
		EXPECT_EQ(generalOfficer->getNumPlanes(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,numShips){
   		Military * military=new Military();
   		MilitaryState * generalOfficer=new MilitaryState(military);
		EXPECT_EQ(generalOfficer->getNumShips(),0);
		Ship* rocker=new Ship();
		military->insertShips(rocker);
		EXPECT_EQ(generalOfficer->getNumShips(),1);
		Ship* rocker2=new Ship();
		military->insertShips(rocker2);
		EXPECT_EQ(generalOfficer->getNumShips(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,numBattalions){
   		Military * military=new Military();
   		MilitaryState * generalOfficer=new MilitaryState(military);
		EXPECT_EQ(generalOfficer->getNumBattalions(),0);
		Battalion* rocker=new Battalion();
		military->insertBatalions(rocker);
		EXPECT_EQ(generalOfficer->getNumBattalions(),1);
		Battalion* rocker2=new Battalion();
		military->insertBatalions(rocker2);
		EXPECT_EQ(generalOfficer->getNumBattalions(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,Nullptr){
		MilitaryState * generalOfficer=new MilitaryState();
		try{
			generalOfficer->getState();
			FAIL()<<"Expected std::invalid_argument";
		}catch(std::invalid_argument &err){
			EXPECT_EQ(err.what(),std::string("NULLPTR RECIEVED"));
		}catch(...){
			FAIL();
		}
		delete generalOfficer;
	}

	TEST(MilitaryStateTest,setNumTank){
		Military* military=new Military();
		MilitaryState* generalOfficer=new MilitaryState(military);
		generalOfficer->setNumTanks(3);
		EXPECT_EQ(generalOfficer->getNumTanks(),3);
		generalOfficer->setNumTanks(0);
		EXPECT_EQ(generalOfficer->getNumTanks(),0);
		generalOfficer->setNumTanks(2);
		EXPECT_EQ(generalOfficer->getNumTanks(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,setNumPlane){
		Military* military=new Military();
		MilitaryState* generalOfficer=new MilitaryState(military);
		generalOfficer->setNumPlanes(3);
		EXPECT_EQ(generalOfficer->getNumPlanes(),3);
		generalOfficer->setNumPlanes(0);
		EXPECT_EQ(generalOfficer->getNumPlanes(),0);
		generalOfficer->setNumPlanes(2);
		EXPECT_EQ(generalOfficer->getNumPlanes(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,setNumShip){
		Military* military=new Military();
		MilitaryState* generalOfficer=new MilitaryState(military);
		generalOfficer->setNumShips(3);
		EXPECT_EQ(generalOfficer->getNumShips(),3);
		generalOfficer->setNumShips(0);
		EXPECT_EQ(generalOfficer->getNumShips(),0);
		generalOfficer->setNumShips(2);
		EXPECT_EQ(generalOfficer->getNumShips(),2);
		delete generalOfficer;
		delete military;
	}

	TEST(MilitaryStateTest,setNumBattalions){
		Military* military=new Military();
		MilitaryState* generalOfficer=new MilitaryState(military);
		generalOfficer->setNumBatalion(3);
		EXPECT_EQ(generalOfficer->getNumBattalions(),3);
		generalOfficer->setNumBatalion(0);
		EXPECT_EQ(generalOfficer->getNumBattalions(),0);
		generalOfficer->setNumBatalion(2);
		EXPECT_EQ(generalOfficer->getNumBattalions(),2);
		delete generalOfficer;
		delete military;
	}
}