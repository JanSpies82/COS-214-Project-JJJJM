#include <exception>
using namespace std;

#include "Neighbour.h"
#include "Location.h"

Neighbour::Neighbour(Location* _location, Location* _neighbour){
    this->location=_location;
    this->neighbour=_neighbour;
}

Neighbour::~Neighbour(){}

Iterator* Neighbour::createIterator(){
    return NULL;
}
// void Neighbour::operation() {
// 	throw "Not yet implemented";
// }

// Iterator* Neighbour::createIterator() {
// 	throw "Not yet implemented";
// }

