#include <exception>
using namespace std;

#include "BottomNeighbour.h"


BottomNeighbour::BottomNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* BottomNeighbour::getRight(){
    if(location!=NULL)
        return this->location->getRight();
    return NULL;
}

Location* BottomNeighbour::getLeft(){
    if(location!=NULL)
        return this->location->getLeft();
    return NULL;
}

Location* BottomNeighbour::getTop(){
    if(location!=NULL)
        return this->location->getTop();
    return NULL;
}

Location* BottomNeighbour::getBottom(){
    return neighbour;
}

BottomNeighbour::~BottomNeighbour(){}
