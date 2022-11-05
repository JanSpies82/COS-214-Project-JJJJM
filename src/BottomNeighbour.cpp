/// @author Julian Pienaar

#include "BottomNeighbour.h"
#include <iostream>

using namespace std;

BottomNeighbour::BottomNeighbour(Location *_neighbour) : Neighbour(_neighbour) {}

Location *BottomNeighbour::getBottom()
{
    return neighbour;
}

bool BottomNeighbour::hasBottom()
{
    return true;
}