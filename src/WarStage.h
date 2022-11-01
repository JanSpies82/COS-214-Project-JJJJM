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
        static WarStage* getInstance();
        void setSimulationLength(int length);
        void incrementRound();
        int getCurrentRound();
        string getWarStage();
    
    protected:
        WarStage();
    
    private:
        static WarStage* onlyInstance;
        int simulationLength;
        int currentRound;
        string warStage;
    
    public: 
    // virtual void handle() = 0;
    // /**
    //  * @brief ??
    //  */
    //  virtual WarStage* nextStage() =0;
    //  /**
    //   * @brief Returns an object to the next stage of war
    //   */
};

#endif