///@author Janco Spies

#ifndef __StageContextState_h__
#define __StageContextState_h__

class StageContext;
class WarStage;

class StageContextState
{
public:
    /**
     * @brief Construct a new StageContext State object
     *
     */
    StageContextState();

    /**
     * @brief Destroy the StageContext State object
     *
     */
    ~StageContextState();

    /**
     * @brief Set the Simulation Length
     *
     * @param _length : int - the length of the simulation
     */
    void setSimulationLength(int _length);

    /**
     * @brief Get the simulation length
     *
     * @return int : the length of the simulation
     */
    int getSimulationLength();

    /**
     * @brief Set the Current Round
     *
     * @param _round : int - the round we want to set the current round to
     */
    void setCurrentRound(int _round);

    /**
     * @brief returns the current round we are on
     */
    int getCurrentRound();

    /**
     * @brief Set the Current Stage
     *
     * @param _stage : WarStage* - the stage we want to set the current stage to
     */
    void setCurrentStage(WarStage *_stage);

    /**
     * @brief Get the Current Stage
     *
     * @return WarStage*
     */
    WarStage *getCurrentStage();

private:
    int simulationLength;
    int currentRound;
    WarStage *currentStage;
};
#endif