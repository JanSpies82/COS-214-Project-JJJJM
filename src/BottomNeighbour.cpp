#include <iostream>
#include <exception>
#include "BottomNeighbour.h"

using namespace std;

BottomNeighbour::BottomNeighbour(Location* _neighbour) : Neighbour(_neighbour){}

Location* BottomNeighbour::getBottom(){
    return neighbour;
}

bool BottomNeighbour::hasBottom(){
    return true;
}


