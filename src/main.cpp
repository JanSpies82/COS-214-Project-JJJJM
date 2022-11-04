/// @author Janco Spies

#include "SimulationManager.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "Welcome to the COS 214 Group JJJJM Project" << std::endl;
    SimulationManager *simulationManager = new SimulationManager();
    simulationManager->runSimulation();
    delete simulationManager;
    return 0;
}