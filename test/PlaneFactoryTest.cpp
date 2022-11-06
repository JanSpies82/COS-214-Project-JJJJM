///@author Jacob Mahloko
#include <limits.h>
#include <stdexcept>
#include "../src/PlaneFactory.h"
#include"../src/Plane.h"
#include "gtest/gtest.h"

namespace {
	TEST(PlaneFactoryTest,creationOfObject){
    	PlaneFactory* planeManufacture=new PlaneFactory();
    	Plane* plane=static_cast<Plane*>(planeManufacture->manufactureVehicle());
    	PlaneFactory* plant2=planeManufacture->clone();
    	 	
    	delete plane;
    	delete plant2;
    	delete planeManufacture;
    	  	
    }
    
}