#include <exception>
using namespace std;

#include "Territory.h"
#include "LocationIterator.h"
#include "Location.h"

Iterator* Territory::createIterator() {
	throw "Not yet implemented";
}

Location* Territory::getRight(){
    return NULL;
}

Location* Territory::getLeft(){
    return NULL;
}

Location* Territory::getTop(){
    return NULL;
}

Location* TopNeighbTerritoryour::getBottom(){
    return NULL;
}

