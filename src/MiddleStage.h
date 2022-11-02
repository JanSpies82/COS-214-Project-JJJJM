#include <exception>
using namespace std;

#ifndef __MiddleStage_h__
#define __MiddleStage_h__

#include "WarStage.h"

// class WarStage;
class MiddleStage;

class MiddleStage: public WarStage
{

	public:    
        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();
        MiddleStage();
        ~MiddleStage();
};

#endif
