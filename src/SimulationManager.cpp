#include "SimulationManager.h"
#include "Map.h"
#include "SimulationState.h"
#include "Superpower.h"
#include "Backup.h"

using namespace std;

SimulationManager::SimulationManager()
{
    map = new Map();
    superpowers = new vector<Superpower *>();
    backup = new Backup();
    designMode = false;
    isRunning = false;
}

SimulationManager::~SimulationManager()
{
    delete map;
    for (int i = 0; i < superpowers->size(); i++)
        delete superpowers->at(i);
    delete superpowers;
    delete backup;
}