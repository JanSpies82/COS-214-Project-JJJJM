/// @author Julian Pienaar

#include "RightNeighbour.h"
#include <iostream>

using namespace std;

RightNeighbour::RightNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* RightNeighbour::getRight()
{
    return neighbour;
}

bool RightNeighbour::hasRight()
{
    return true;
}