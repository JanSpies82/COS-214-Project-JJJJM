#include <gtest/gtest.h>

#include "../test/BackupTest.cpp"
#include "../test/BattalionTest.cpp"
#include "../test/BattalionObserverTest.cpp"
#include "../test/CitizenTest.cpp"
#include "../test/CountryTest.cpp"
#include "../test/CountryObserverTest.cpp"	
#include "../test/CountryMediatorTest.cpp"
#include "../test/CountryStateTest.cpp"
#include "../test/MementoTest.cpp"
#include "../test/MilitaryTest.cpp"
#include "../test/MilitaryStateTest.cpp"
#include "../test/PlaneFactoryTest.cpp"
#include "../test/PlaneTest.cpp"
#include "../test/ShipFactoryTest.cpp"
#include "../test/ShipTest.cpp"
#include "../test/SimulationManagerTest.cpp"
#include "../test/SimulationStateTest.cpp"
#include "../test/SuperpowerTest.cpp"
#include "../test/TankFactoryTest.cpp"
#include "../test/TankTest.cpp"
#include "../test/VehicleObserverTest.cpp"
#include "../test/RightNeighbourTest.cpp"
#include "../test/LeftNeighbourTest.cpp"
#include "../test/TopNeighbourTest.cpp"
#include "../test/BottomNeighbourTest.cpp"
#include "../test/TerritoryTest.cpp"
#include "../test/LocationIteratorTest.cpp"
#include "../test/MapTest.cpp"
#include "../test/MapStateTest.cpp"



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    //Terminal command for valgrind:
    //valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
    return RUN_ALL_TESTS();
}