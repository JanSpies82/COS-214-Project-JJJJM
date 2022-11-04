/// @author Julian Pienaar

#ifndef __LocationObserver_h__
#define __LocationObserver_h__

class Location;

class LocationObserver
{
    public:
        LocationObserver(Location* _location);
        ~LocationObserver();
        void updateLocation();

    private:
        Location* location;
};
#endif