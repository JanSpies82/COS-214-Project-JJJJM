#include <exception>
#include <stdexcept>
using namespace std;

#include "Neighbour.h"
#include "Location.h"

Neighbour::Neighbour(Location* _neighbour){
    this->neighbour=_neighbour;
    location=NULL;
}

void Neighbour::add(Location* _neighbour){
    if(location!=NULL)
        location->add(_neighbour);
    else
        location=_neighbour;
}

Neighbour::~Neighbour(){
    if(location!=NULL)
        delete location;
}


char Neighbour::getColour(){
    location->getColour();
}