/// @author Julian Pienaar

#ifndef __LocationObserver_h__
#define __LocationObserver_h__

#include <string>

class Location;

class LocationObserver
{
public:
    LocationObserver(Location *_location);
    ~LocationObserver();
    void updateLocation(std::string _newColor);

private:
    Location *location;
};
#endif