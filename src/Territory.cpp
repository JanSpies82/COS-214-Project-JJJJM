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

Iterator* Territory::createIterator() {
	throw "Not yet implemented";
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
    return tClone;
}
