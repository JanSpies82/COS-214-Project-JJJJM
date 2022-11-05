///@author Mekhail Muller

#include "MiddleStage.h"

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