/// @author Julian Pienaar

#include "LeftNeighbour.h"
#include <iostream>

using namespace std;

LeftNeighbour::LeftNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* LeftNeighbour::getLeft()
{
    return neighbour;
}

bool LeftNeighbour::hasLeft()
{
    return true;
}