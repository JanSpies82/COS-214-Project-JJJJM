using namespace std;
#include <iostream>
#include <stdexcept>
#include "Territory.h"
#include "LocationIterator.h"
#include "Location.h"

Territory::Territory(int _x, int _y, char _colour){
    xCoordinate=_x;
    yCoordinate=_y;
    colour=_colour;
}

Iterator* Territory::createIterator() {
	throw "Not yet implemented";
}

Location* Territory::getRight(){
    __throw_out_of_range("No Right Neighbour");
}

Location* Territory::getLeft(){
    __throw_out_of_range("No Left Neighbour");
}

Location* Territory::getTop(){
    __throw_out_of_range("No Top Neighbour");
}

Location* Territory::getBottom(){
    __throw_out_of_range("No Bottom Neighbour");
}

Territory::~Territory(){
    
    
}

char Territory::getColour(){
    return colour;
}

bool Territory::hasRight(){
    return false;
}

bool Territory::hasLeft(){
    return false;
}

bool Territory::hasTop(){
    return false;
}

bool Territory::hasBottom(){
    return false;
}
