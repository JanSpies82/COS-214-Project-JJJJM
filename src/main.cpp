#include <gtest/gtest.h>

#include "BackupTest.cpp"
#include "BattalionTest.cpp"
#include "BattalionObserverTest.cpp"
#include "CitizenTest.cpp"
#include "CountryTest.cpp"
#include "CountryObserverTest.cpp"	
#include "CountryMediatorTest.cpp"
#include "CountryStateTest.cpp"
#include "MementoTest.cpp"
#include "MilitaryTest.cpp"
#include "MilitaryStateTest.cpp"
#include "PlaneFactoryTest.cpp"
#include "PlaneTest.cpp"
#include "ShipFactoryTest.cpp"
#include "ShipTest.cpp"
#include "SimulationManagerTest.cpp"
#include "SimulationStateTest.cpp"
#include "SuperpowerTest.cpp"
#include "TankFactoryTest.cpp"
#include "TankTest.cpp"
#include "VehicleObserverTest.cpp"


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}