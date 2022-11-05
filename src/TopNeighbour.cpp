/// @author Julian Pienaar

#include "TopNeighbour.h"
#include <iostream>
#include <exception>

using namespace std;

TopNeighbour::TopNeighbour(Location *_neighbour) : Neighbour(_neighbour) {}

Location *TopNeighbour::getTop()
{
    return neighbour;
}

bool TopNeighbour::hasTop()
{
    return true;
}