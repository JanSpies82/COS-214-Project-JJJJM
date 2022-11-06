//@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/ShipFactory.h"
#include"../src/Ship.h"
#include "gtest/gtest.h"

namespace {

    TEST(shipFactoryTest,creationOfObject){
    	ShipFactory* shipManufacture=new ShipFactory();
        Ship* ship=static_cast<Ship*>(shipManufacture->manufactureVehicle());
        ShipFactory* plant2=shipManufacture->clone();
    	
        delete ship;
        delete plant2;
    	delete shipManufacture;
    }
}