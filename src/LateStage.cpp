///@author Mekhail Muller

#include "LateStage.h"
using namespace std;

int LateStage::getWarStage()
{
	return 2;
}

LateStage::LateStage(){}

LateStage::~LateStage(){}

LateStage* LateStage::clone()
{
	return new LateStage();
}