#include <exception>
using namespace std;

#include "RightNeighbour.h"
#include "Neighbour.h"

RightNeighbour::RightNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* RightNeighbour::getRight(){
    return neighbour;
}

Location* RightNeighbour::getLeft(){
    return this->location->getLeft();
}

Location* RightNeighbour::getTop(){
    return this->location->getTop();
}

Location* RightNeighbour::getBottom(){
    return this->location->getBottom();
}

RightNeighbour::~RightNeighbour(){}