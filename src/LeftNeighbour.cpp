/// @author Julian Pienaar

#include <iostream>
#include <exception>
#include "LeftNeighbour.h"

using namespace std;

LeftNeighbour::LeftNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* LeftNeighbour::getLeft(){
    return neighbour;
}

bool LeftNeighbour::hasLeft(){
    return true;
}