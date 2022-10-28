#include <exception>
using namespace std;

#include "LeftNeighbour.h"

LeftNeighbour::LeftNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* LeftNeighbour::getRight(){
    return this->location->getRight();
}

Location* LeftNeighbour::getLeft(){
    return neighbour;
}

Location* LeftNeighbour::getTop(){
    return this->location->getTop();
}

Location* LeftNeighbour::getBottom(){
    return this->location->getBottom();
}

LeftNeighbour::~LeftNeighbour(){}