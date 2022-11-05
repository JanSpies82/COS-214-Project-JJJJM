///@author Janco Spies
#include <gtest/gtest.h>

#include "BackupTest.cpp"
#include "CountryTest.cpp"
#include "MementoTest.cpp"
#include "MilitaryStateTest.cpp"
#include "PlaneFactoryTest.cpp"
#include "ShipFactoryTest.cpp"
#include "SimulationStateTest.cpp"
#include "SuperpowerTest.cpp"
#include "TankFactoryTest.cpp"
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