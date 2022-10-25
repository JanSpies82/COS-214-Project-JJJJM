#include <exception>
using namespace std;

#include "EarlyStage.h"
#include "WarStage.h"

void EarlyStage::handle() {
	throw "Not yet implemented";
}

 WarStage* EarlyStage::nextStage(){
	return NULL;
 };