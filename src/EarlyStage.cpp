///@author Mekhail Muller

#include "EarlyStage.h"
using namespace std;

int EarlyStage::getWarStage()
{
	return 0;
}

EarlyStage::EarlyStage(){}

EarlyStage::~EarlyStage(){}

EarlyStage* EarlyStage::clone()
{
	return new EarlyStage();
}