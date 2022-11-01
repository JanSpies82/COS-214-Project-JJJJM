/// @author Janco Spies

#include "SimulationManager.h"
#include "Map.h"
#include "SimulationState.h"
#include "Superpower.h"
#include "Memento.h"
#include "Backup.h"
#include "WarStage.h"

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

void SimulationManager::saveState(){
    SimulationState *state = new SimulationState(this);
    state->setMapState(map->getState());
    state->addSuperpowerState(superpowers->at(0)->getState());
    state->addSuperpowerState(superpowers->at(1)->getState());
    state->setWarStage(warStage->clone());
    backup->addMemento(new Memento(state));
}