/// @author Janco Spies

//https://github.com/DeadpanSplash82/COS-214-Project-JJJJM

#include "SimulationManager.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    SimulationManager *simulationManager = new SimulationManager();
    simulationManager->runSimulation();
    delete simulationManager;
    return 0;
}