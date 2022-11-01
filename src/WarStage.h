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
        // /**
        //  * @brief initialises our singleton object and returns it
        // */
        // virtual WarStage* getInstance();

        /**
         * @brief Creates a copy of the singleton class and returns for storage purposes
        */
        virtual WarStage* clone()=0;

        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        virtual int getWarStage() = 0;

        /**
         * @brief Moves current warstage to next warstage
        */
        virtual void changeStage() = 0;

        /**
         * @brief increments round/turn to go to the next round
        */
        void incrementRound();
        /**
         * @brief sets the simulationLength: how many turns/rounds do we want to run the simulation for
         * 
         * @param length, the length wanted for the simulation
        */
        void setSimulationLength(int length);
        /**
         * @brief returns the current round we are on
        */
        int getCurrentRound();

    
    protected:
        WarStage();
        int simulationLength;
        int currentRound; 
    
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