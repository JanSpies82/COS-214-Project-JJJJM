using namespace std;
#include <stdexcept>
#include "Territory.h"
#include "LocationIterator.h"
#include "Location.h"

Territory::Territory(int _x, int _y){
    
}

Iterator* Territory::createIterator() {
	throw "Not yet implemented";
}

Location* Territory::getRight(){
    __throw_out_of_range("No Right Neighbour");
    
    //return NULL;
}

Location* Territory::getLeft(){
        __throw_out_of_range("No Left Neighbour");
    return NULL;
}

Location* Territory::getTop(){
        __throw_out_of_range("No Top Neighbour");
    return NULL;
}

Location* Territory::getBottom(){
        __throw_out_of_range("No Bottom Neighbour");
    return NULL;
}

Territory::~Territory(){}
