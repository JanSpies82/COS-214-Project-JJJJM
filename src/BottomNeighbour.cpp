#include <exception>
using namespace std;

#include "BottomNeighbour.h"


BottomNeighbour::BottomNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* BottomNeighbour::getRight(){
    return this->location->getRight();
}

Location* BottomNeighbour::getLeft(){
    return this->location->getLeft();
}

Location* BottomNeighbour::getTop(){
    return this->location->getTop();
}

Location* BottomNeighbour::getBottom(){
    return neighbour;
}

BottomNeighbour::~BottomNeighbour(){
    delete location;
}
