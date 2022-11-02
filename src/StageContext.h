///@author Mekhail Muller

#ifndef __StageContext_h__
#define __StageContext_h__

#include <string>

class Country;
class WarStage;
class StageContextState;

class StageContext
{
public:
    /**
     * @brief Creates a copy of the singleton class and returns for storage purposes
     */
    StageContextState *getState();

    /**
     * @brief returns the current round we are on
     */
    int getCurrentRound();

    /**
     * @brief initialises our singleton object and returns it
     */
    static StageContext *getInstance();

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
    void setSimulationLength(int _length);

    /**
     * @brief Destroy the Stage Context object
     *
     */
    ~StageContext();

    /**
     * @brief Set the Current Round object
     *
     * @param _round : int - the round we want to set the current round to
     */
    void setCurrentRound(int _round);

    /**
     * @brief Set the Current Stage object
     *
     * @param _stage : WarStage* - the stage we want to set the current stage to
     */
    void setCurrentStage(WarStage *_stage);

    /**
     * @brief Set the StageContext equal to the StageContextState
     *
     * @param _state : StageContextState* - the state we want to set the StageContext to
     */
    void setState(StageContextState *_state);

    /**
     * @brief Get the Simulation Length
     *
     * @return int
     */
    int getSimulationLength();

protected:
    StageContext();
    StageContext(int _simulationLength);
    int simulationLength;
    int currentRound;
    static StageContext *onlyInstance;
    WarStage *currentStage;
};

#endif