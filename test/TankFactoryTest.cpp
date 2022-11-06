//@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/TankFactory.h"
#include"../src/Tank.h"
#include "gtest/gtest.h"

namespace {


    TEST(TankFactoryTest,creationOfObject){
    	TankFactory* tankManufacture=new TankFactory();
        Tank* tank =static_cast<Tank*>(tankManufacture->manufactureVehicle());
        TankFactory* plant2=tankManufacture->clone();
    
    	delete tank;
        delete plant2;
        delete tankManufacture;
        
    }

}