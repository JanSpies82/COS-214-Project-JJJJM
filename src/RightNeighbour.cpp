#include <exception>
using namespace std;

#include "RightNeighbour.h"
#include "Neighbour.h"

RightNeighbour::RightNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* RightNeighbour::getRight(){
    return neighbour;
}

Location* RightNeighbour::getLeft(){
    if(location!=NULL)
        return this->location->getLeft();
    return NULL;
}

Location* RightNeighbour::getTop(){
    if(location!=NULL)
        return this->location->getTop();
    return NULL;
}

Location* RightNeighbour::getBottom(){
    if(location!=NULL)
        return this->location->getBottom();
    return NULL;
}

RightNeighbour::~RightNeighbour(){}