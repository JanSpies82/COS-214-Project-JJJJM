#include <exception>
using namespace std;

#ifndef __LateStage_h__
#define __LateStage_h__

#include "WarStage.h"

// class WarStage;
class LateStage;

class LateStage: public WarStage
{

	public:    
        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();
        LateStage();
        ~LateStage();
};

#endif
