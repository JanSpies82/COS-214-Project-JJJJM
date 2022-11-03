///@author Mekhail Muller

#include "MiddleStage.h"
#include "WarStage.h"

using namespace std;

int MiddleStage::getWarStage()
{
	return 1;
}

MiddleStage::MiddleStage(){}

MiddleStage::~MiddleStage(){}

MiddleStage* MiddleStage::clone()
{
	return new MiddleStage();
}