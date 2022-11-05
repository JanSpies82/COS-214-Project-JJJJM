/// @author Julian Pienaar

#include "LocationObserver.h"
#include "Location.h"
#include <iostream>

using namespace std;

LocationObserver::LocationObserver(Location *_location)
{
    location = _location;
}

LocationObserver::~LocationObserver() {}

void LocationObserver::updateLocation(string _newColor = "\x1B[100m")
{
    if (location != NULL)
    {
        location->setColor(_newColor);
        location->setIsCapital(false);
        location->setOwnedBy(NULL);
    }
}