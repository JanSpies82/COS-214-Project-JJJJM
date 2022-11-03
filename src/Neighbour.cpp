/// @author Julian Pienaar

#include "Neighbour.h"
#include "Location.h"
#include <exception>
#include <stdexcept>

using namespace std;

Neighbour::Neighbour(Location* _neighbour)
{
    this->neighbour=_neighbour;
    location=NULL;
}

void Neighbour::add(Location* _neighbour)
{
    if(location!=NULL)
        location->add(_neighbour);
    else
        location=_neighbour;
}

Neighbour::~Neighbour()
{
    if(location!=NULL)
        delete location;
}