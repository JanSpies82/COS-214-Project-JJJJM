#include <limits.h>
#include <stdexcept>
#include "../src/PlaneFactory.h"
#include "../src/VehicleFactory.h"
#include"../src/Plane.h"
#include "gtest/gtest.h"

namespace {

	TEST(PlaneFactoryTest,creationOfObject){
    	PlaneFactory* planeManufacture=new PlaneFactory();
    	Plane* plane=static_cast<Plane*>(planeManufacture->manufactureVehicle());
    	plane->setNumPlanesDestroys(2);
    	EXPECT_EQ(plane->getPlanesDestroyed(),2);
    	delete planeManufacture;
    	delete plane;
    }
}