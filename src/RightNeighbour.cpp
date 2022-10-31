/// @author Julian Pienaar

#include <iostream>
#include <exception>
#include "RightNeighbour.h"

using namespace std;

RightNeighbour::RightNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* RightNeighbour::getRight(){
    return neighbour;
}

bool RightNeighbour::hasRight(){
    return true;
}