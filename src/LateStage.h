#include <exception>
using namespace std;

#ifndef __LateStage_h__
#define __LateStage_h__

#include "WarStage.h"

// class WarStage;
class LateStage;

class LateStage: public WarStage
{

	public: void handle();

    WarStage* nextStage();
    /**
     * @brief returns NULL
     */
};

#endif
