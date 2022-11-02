#include <gtest/gtest.h>

#include "BackupTest.cpp"
#include "BattalionTest.cpp"
#include "BattalionObserverTest.cpp"
#include "CountryTest.cpp"
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
#include "RightNeighbourTest.cpp"
#include "LeftNeighbourTest.cpp"
#include "TopNeighbourTest.cpp"
#include "BottomNeighbourTest.cpp"
#include "TerritoryTest.cpp"
#include "LocationIteratorTest.cpp"
#include "MapTest.cpp"
#include "MapStateTest.cpp"



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    //Terminal command for valgrind:
    //valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./test
    return RUN_ALL_TESTS();
}