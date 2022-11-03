/// @author Julian Pienaar

#include "Territory.h"
#include "LocationIterator.h"
#include "Location.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Territory::Territory(int _x, int _y, string _color)
{
    xCoordinate=_x;
    yCoordinate=_y;
    color=_color;
    location=NULL;
    isLand=true;
    isCapital=false;
    ownedBy=NULL;
}

void Territory::add(Location* _neighbour)
{
    if(location!=NULL)
        location->add(_neighbour);
    else
        location=_neighbour;
}

Territory::~Territory()
{
    if(location!=NULL)
        delete location;
}