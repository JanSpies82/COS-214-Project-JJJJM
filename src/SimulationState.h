///@author Janco Spies

#ifndef __SimulationState_h__
#define __SimulationState_h__

#include <vector>
#include <ctime>

class MapState;
class SuperpowerState;
class StageContextState;

class SimulationState
{
public:
	/**
	 * @brief Construct a new Simulation State object
	 *
	 * Sets the timestamp to the current time
	 */
	SimulationState();

	/**
	 * @brief Destroy the Simulation State object and delete all held state objects
	 *
	 */
	~SimulationState();

	/**
	 * @brief Set the Map State object stored by the SimulationState
	 *
	 * If a MapState is already stored, it is deleted
	 *
	 * @param _mapState : MapState* - Pointer to the MapState object.
	 */
	void setMapState(MapState *_mapState);

	/**
	 * @brief Set the Stage Context State object stored by the SimulationState
	 *
	 * @param _stageContextState : StageContextState* - Pointer to the StageContextState object.
	 */
	void setStageContextState(StageContextState *_stageContextState);

	/**
	 * @brief Add a SuperpowerState object to the SimulationState
	 *
	 * @param _superpowerState : SuperpowerState* - Pointer to the SuperpowerState object.
	 */
	void addSuperpowerState(SuperpowerState *_superpowerState);

	/**
	 * @brief Get the number of SuperpowerState objects stored by the SimulationState
	 *
	 * @return int
	 */
	int getSuperpowerStateCount();

	/**
	 * @brief Get the SuperpowerState object stored by the SimulationState
	 *
	 * Exceptions : std::out_of_range if the index is out of range
	 *
	 * @param index : int - Index of the SuperpowerState object to return.
	 * @return SuperpowerState*
	 */
	SuperpowerState *getSuperpowerState(int _index);

	/**
	 * @brief Get the Map State object stored by the SimulationState
	 *
	 * Exceptions : std::out_of_range if the SimulationState does not hold a MapState
	 *
	 * @return MapState*
	 */
	MapState *getMapState();

	/**
	 * @brief Get the StageContextState object stored by the SimulationState
	 *
	 * Exceptions : std::out_of_range if the SimulationState does not hold a StageContextState
	 *
	 * @return StageContextState*
	 */
	StageContextState *getStageContextState();

	/**
	 * @brief Get the Timestamp object stored by the SimulationState
	 *
	 * @return std::time_t
	 */
	std::time_t getTimestamp();

private:
	MapState *mapState;
	StageContextState *stageContextState;
	std::vector<SuperpowerState *> *superpowerStates;
	std::time_t timestamp;
};

#endif
