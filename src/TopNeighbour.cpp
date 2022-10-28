#include <exception>
using namespace std;

#include "TopNeighbour.h"
#include "Neighbour.h"

TopNeighbour::TopNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* TopNeighbour::getRight(){
    return this->location->getRight();
}

Location* TopNeighbour::getLeft(){
    return this->location->getLeft();
}

Location* TopNeighbour::getTop(){
    return neighbour;
}

Location* TopNeighbour::getBottom(){
    return this->location->getBottom();
}

TopNeighbour::~TopNeighbour(){}