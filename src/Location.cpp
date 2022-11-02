/// @author Julian Pienaar

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

Iterator* Location::createIterator(){
    return new LocationIterator(this);
}

Country* Location::getOwnedBy(){
    return ownedBy;
}

void Location::setOwnedBy(Country* _newOwner){
    ownedBy=_newOwner;
}

char Location::getColour(){
    return colour;
}

void Location::setColour(char _colour){
    colour=_colour;
}

Location* Location::clone(){
    Location* tClone=new Territory(this->xCoordinate, this->yCoordinate, this->colour);

    tClone->setOwnedBy(this->getOwnedBy());
    tClone->setIsCapital(this->getIsCapital());
    tClone->setIsLand(this->getIsLand());

    return tClone;
}

int Location::getX(){
    return xCoordinate;
}

int Location::getY(){
    return yCoordinate;
}

bool Location::getIsLand(){
    return isLand;
}

void Location::setIsLand(bool _isLand){
    isLand=_isLand;
}

bool Location::getIsCapital(){
    return isCapital;
}

void Location::setIsCapital(bool _isCapital){
    isCapital=_isCapital;
}
