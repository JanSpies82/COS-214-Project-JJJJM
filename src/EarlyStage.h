#include <exception>
using namespace std;

#ifndef __EarlyStage_h__
#define __EarlyStage_h__

#include "WarStage.h"

// class WarStage;
class EarlyStage;

class EarlyStage: public WarStage
{

	public: void handle();

    WarStage* nextStage();
    /**
     * @brief initialises a MiddleStage object and returns it
     */
};

#endif
