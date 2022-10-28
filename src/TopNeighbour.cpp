#include <exception>
using namespace std;

#include "TopNeighbour.h"
#include "Neighbour.h"

TopNeighbour::TopNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* TopNeighbour::getRight(){
    return neighbour;
}

Location* TopNeighbour::getLeft(){
    return this->location->getLeft();
}

Location* TopNeighbour::getTop(){
    return this->location->getTop();
}

Location* TopNeighbour::getBottom(){
    return this->location->getBottom();
}

TopNeighbour::~TopNeighbour(){}