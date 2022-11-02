/// @author Julian Pienaar

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
    isLand=true;
    isCapital=false;
    ownedBy=NULL;
}

void Territory::add(Location* _neighbour){
    if(location!=NULL)
        location->add(_neighbour);
    else
        location=_neighbour;
}

Territory::~Territory(){
    if(location!=NULL)
        delete location;
}