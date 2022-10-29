#include <exception>
using namespace std;

#include "MapState.h"
#include "SimulationState.h"

MapState::MapState(Map* m) {
    mapState=m->clone();
}

MapState::~MapState(){
    delete mapState;
}

Map* MapState::clone(){
    return mapState->clone();
}

