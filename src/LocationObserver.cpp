/// @author Julian Pienaar

#include "LocationObserver.h"
#include "Location.h"
#include <iostream>

using namespace std;

LocationObserver::LocationObserver(Location* _location)
{
    location=_location;
}

LocationObserver::~LocationObserver(){}

void LocationObserver::updateLocation()
{
    if(location!=NULL)
    {
        location->setColor("\x1B[100m");
        location->setIsCapital(false);
        location->setOwnedBy(NULL);
    }
}