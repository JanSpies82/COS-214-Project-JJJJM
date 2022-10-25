#include <exception>
using namespace std;

#include "MiddleStage.h"
#include "WarStage.h"

void MiddleStage::handle()
{
	throw "Not yet implemented";
}

WarStage *MiddleStage::nextStage()
{
	return NULL;
};
