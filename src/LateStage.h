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
         * @brief returns warstage via int = 2
         */
        int getWarStage();
        LateStage();
        ~LateStage();
};

#endif
