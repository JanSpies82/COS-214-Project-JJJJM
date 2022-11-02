///@author Mekhail Muller
#include <exception>
using namespace std;

#include "LateStage.h"
#include "WarStage.h"

int LateStage::getWarStage(){
	return 2;
}

LateStage::LateStage(){
}

LateStage::~LateStage(){
}

LateStage* LateStage::clone(){
	return new LateStage();
}