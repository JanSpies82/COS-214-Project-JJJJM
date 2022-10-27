#include <exception>
using namespace std;

#include "TopNeighbour.h"
#include "Neighbour.h"

TopNeighbour::TopNeighbour(Location* _location, Location* _neighbour) : Neighbour(_location, _neighbour){}

Location* TopNeighbour::getRight(){
    return neighbour;
}

Location* TopNeighbour::getLeft(){
    if(location!=NULL)
        return this->location->getLeft();
    return NULL;
}

Location* TopNeighbour::getTop(){
    if(location!=NULL)
        return this->location->getTop();
    return NULL;
}

Location* TopNeighbour::getBottom(){
    if(location!=NULL)
        return this->location->getBottom();
    return NULL;
}