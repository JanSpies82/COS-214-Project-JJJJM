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
         * @brief returns warstage via int = 1
        */
        int getWarStage();
        MiddleStage();
        ~MiddleStage();
};

#endif
