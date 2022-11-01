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
         * @brief initialises our singleton object and returns it
        */
        static WarStage* getInstance();
        /**
         * @brief sets the simulationLength: how many turns/rounds do we want to run the simulation for
         * 
         * @param length, the length wanted for the simulation
        */
        void setSimulationLength(int length);
        /**
         * @brief increments round/turn to go to the next round
        */
        void incrementRound();
        /**
         * @brief returns the current round we are on
        */
        int getCurrentRound();
        /**
         * @brief calculates which war stage we are on and returns it via a string
        */
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