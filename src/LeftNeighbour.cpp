#include <exception>
using namespace std;

#include "LeftNeighbour.h"

LeftNeighbour::LeftNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* LeftNeighbour::getRight(){
    if(location!=NULL)
        return this->location->getRight();
    return NULL;
}

Location* LeftNeighbour::getLeft(){
    return neighbour;
}

Location* LeftNeighbour::getTop(){
    if(location!=NULL)
        return this->location->getTop();
    return NULL;
}

Location* LeftNeighbour::getBottom(){
    if(location!=NULL)
        return this->location->getBottom();
    return NULL;
}
