using namespace std;
#include <iostream>
#include <stdexcept>
#include "Territory.h"
#include "LocationIterator.h"
#include "Location.h"

Territory::Territory(int _x, int _y, char _colour){
    xCoordinate=_x;
    yCoordinate=_y;
    colour=_colour;
    location=NULL;
}

void Territory::add(Location* _neighbour){
    if(location!=NULL)
        location->add(_neighbour);
    else
        location=_neighbour;
}

Country* Territory::getOwnedBy(){
    return ownedBy;
}

void Territory::setOwnedBy(Country* _newOwner){
    ownedBy=_newOwner;
}

Territory::~Territory(){
    if(location!=NULL)
        delete location;
}

char Territory::getColour(){
    return colour;
}

Location* Territory::clone(){
    Location* tClone=new Territory(this->xCoordinate, this->yCoordinate, this->colour);
    ((Territory*)tClone)->setOwnedBy(this->getOwnedBy());
    return tClone;
}

int Territory::getX(){
    return xCoordinate;
}

int Territory::getY(){
    return yCoordinate;
}