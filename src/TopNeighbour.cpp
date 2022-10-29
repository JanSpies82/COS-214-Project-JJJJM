#include <iostream>
#include <exception>
#include "TopNeighbour.h"

using namespace std;

TopNeighbour::TopNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* TopNeighbour::getTop(){
    return neighbour;
}

bool TopNeighbour::hasTop(){
    return true;
}