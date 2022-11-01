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
        static WarStage* getInstance();
        static WarStage* getInstance(int length);

        /**
         * @brief Creates a copy of the singleton class and returns for storage purposes
        */
        WarStage* clone();

        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();

        /**
         * @brief Moves current warstage to next warstage
        */
        WarStage* changeStage();
    protected:
        static WarStage* onlyInstance;
        EarlyStage();
        EarlyStage(int length);
	
};

#endif
