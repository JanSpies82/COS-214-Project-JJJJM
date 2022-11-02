///@author Mekhail Muller
#include <exception>
using namespace std;

#include "MiddleStage.h"
#include "WarStage.h"

int MiddleStage::getWarStage(){
	return 1;
}

MiddleStage::MiddleStage(){
}

MiddleStage::~MiddleStage(){
}

MiddleStage* MiddleStage::clone(){
	return new MiddleStage();
}