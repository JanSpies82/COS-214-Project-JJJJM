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
         * @brief Virtual function for returning the warstage
        */
        virtual int getWarStage() = 0;
        WarStage();
    
};

#endif