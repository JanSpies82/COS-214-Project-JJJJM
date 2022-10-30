#include <exception>

using namespace std;

#include "Map.h"
#include "MapState.h"
#include "SimulationState.h"

MapState::MapState(Map* _m) {
    mapState=new Map(_m);
}

MapState::~MapState(){
    delete mapState;
}

Map* MapState::clone(){
    return new Map(mapState);
}

