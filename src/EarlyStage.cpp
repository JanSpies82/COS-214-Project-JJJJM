#include <exception>
using namespace std;

#include "EarlyStage.h"
#include "WarStage.h"

int EarlyStage::getWarStage(){
	return 0;
}

EarlyStage::EarlyStage(){
}

EarlyStage::~EarlyStage(){
}

EarlyStage* EarlyStage::clone(){
	return new EarlyStage();
}