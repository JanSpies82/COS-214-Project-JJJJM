#include <exception>
using namespace std;

#ifndef __WarStage_h__
#define __WarStage_h__

// #include "Country.h"

class Country;
class WarStage;

class WarStage
{
	public: 
    virtual void handle() = 0;
    /**
     * @brief ??
     */
     virtual WarStage* nextStage() =0;
     /**
      * @brief Returns an object to the next stage of war
      */
     WarStage* clone();
};

#endif
