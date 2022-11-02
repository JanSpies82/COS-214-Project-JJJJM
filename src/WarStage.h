#include <exception>
#include <string>
using namespace std;

#ifndef __WarStage_h__
#define __WarStage_h__

// #include "Country.h"

class Country;
class WarStage;

class WarStage
{
	public:
        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        virtual int getWarStage() = 0;
        WarStage();
    
};

#endif