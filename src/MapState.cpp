/// @author Julian Pienaar

#include "Map.h"
#include "MapState.h"
#include "SimulationState.h"
#include <exception>

using namespace std;

MapState::MapState(Map* _m)
{
    mapState=new Map(_m);
}

MapState::~MapState()
{
    delete mapState;
}

Map* MapState::clone()
{
    return new Map(mapState);
}

