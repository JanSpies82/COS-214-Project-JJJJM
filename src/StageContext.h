#include <exception>
#include <string>
using namespace std;

#ifndef __StageContext_h__
#define __StageContext_h__

// #include "Country.h"

class Country;
class WarStage;

class StageContext
{
	public:

        /**
         * @brief Moves current warstage to next warstage
        */
        void changeStage();

        /**
         * @brief Creates a copy of the singleton class and returns for storage purposes
        */
        StageContext* clone();

        /**
         * @brief returns the current round we are on
        */
        int getCurrentRound();

        /**
         * @brief initialises our singleton object and returns it
        */
        static StageContext* getInstance();

        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();

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

        ~StageContext();
        
    
    protected:
        StageContext();
        StageContext(int simulationLength);
        int simulationLength;
        int currentRound; 
        static StageContext* onlyInstance;
        static WarStage* currentStage;
};

#endif