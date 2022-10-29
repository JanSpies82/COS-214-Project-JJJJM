#include <iostream>
#include <exception>
#include "Location.h"
#include "Map.h"
#include "LocationIterator.h"
#include "Observer.h"
#include "Neighbour.h"

using namespace std;

Location::~Location(){}


Location* Location::getRight(){
    if(location!=NULL)
        return location->getRight();
    else
        __throw_out_of_range("No Right Neighbour");
}

Location* Location::getLeft(){
    if(location!=NULL)
        return location->getLeft();
    else
        __throw_out_of_range("No Left Neighbour");
}

Location* Location::getTop(){
    if(location!=NULL)
        return location->getTop();
    else
        __throw_out_of_range("No Top Neighbour");
}

Location* Location::getBottom(){
    if(location!=NULL)
        return location->getBottom();
    else
        __throw_out_of_range("No Bottom Neighbour");
}

bool Location::hasRight(){
    if(location!=NULL)
        return location->hasRight();
    else
        return false;    
}

bool Location::hasLeft(){
    if(location!=NULL)
        return location->hasLeft();
    else
        return false;    
}

bool Location::hasTop(){
    if(location!=NULL)
        return location->hasTop();
    else
        return false;    
}

bool Location::hasBottom(){
    if(location!=NULL)
        return location->hasBottom();
    else
        return false;    
}
