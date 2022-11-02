#include <exception>
#include <string>
using namespace std;

#ifndef __Stage_h__
#define __Stage_h__

// #include "Country.h"

class Country;
class WarStage;

class Stage
{
	public:
        /**
         * @brief initialises our singleton object and returns it
        */
        static WarStage* getInstance();

        /**
         * @brief Creates a copy of the singleton class and returns for storage purposes
        */
        Stage* clone();

        /**
         * @brief handle() function: Calculates if currentRound is within its current warstage, and returns warstage int
        */
        int getWarStage();

        /**
         * @brief Moves current warstage to next warstage
        */
        void changeStage();

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
        Stage();
        Stage(int simulationLength);
        int simulationLength;
        int currentRound; 
        static Stage* onlyInstance;
        static WarStage* currentStage;
};

#endif