#include <exception>
using namespace std;

#ifndef __EarlyStage_h__
#define __EarlyStage_h__

#include "WarStage.h"

// class WarStage;
class EarlyStage;

class EarlyStage: public WarStage
{
    public:    
        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();
        EarlyStage();
        ~EarlyStage();

	
};

#endif
