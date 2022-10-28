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

TopNeighbour::~TopNeighbour(){
    delete location;
}

bool TopNeighbour::hasRight(){
    return location->hasRight();
}

bool TopNeighbour::hasLeft(){
    return location->hasLeft();
}

bool TopNeighbour::hasTop(){
    return true;
}

bool TopNeighbour::hasBottom(){
    return location->hasBottom();
}