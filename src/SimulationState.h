#include <exception>
using namespace std;

#ifndef __SimulationState_h__
#define __SimulationState_h__

// #include "SimulationManager.h"
// #include "Memento.h"

#include <vector>
#include <ctime>

class SimulationManager;
class SimulationState;
class MapState;
class CountryState;
class MilitaryState;

class SimulationState
{
public:
	/**
	 * @brief Construct a new Simulation State object
	 *
	 * Sets the timestamp to the current time
	 *
	 * @param _simulationManager : SimulationManager* - Pointer to the SimulationManager object.
	 */
	SimulationState(SimulationManager *_simulationManager);

	/**
	 * @brief Destroy the Simulation State object and delete all held state objects
	 *
	 */
	~SimulationState();

	/**
	 * @brief Set the Map State object stored by the SimulationState
	 *
	 * @param _mapState : MapState* - Pointer to the MapState object.
	 */
	void setMapState(MapState *_mapState);

	/**
	 * @brief Add a CountryState object to the SimulationState
	 *
	 * @param _countryState : CountryState* - Pointer to the CountryState object.
	 */
	void addCountryState(CountryState *_countryState);

	/**
	 * @brief Add a MilitaryState object to the SimulationState
	 *
	 * @param _militaryState : MilitaryState* - Pointer to the MilitaryState object.
	 */
	void addMilitaryState(MilitaryState *_militaryState);

	/**
	 * @brief Get the Map State object stored by the SimulationState
	 * 
	 * Exceptions : std::out_of_range if the SimulationState does not hold a MapState
	 *
	 * @return MapState*
	 */
	MapState *getMapState();

	/**
	 * @brief Get the Country State object stored by the SimulationState
	 *
	 * Exceptions : std::out_of_range if the SimulationState does not hold a CountryState
	 * 
	 * @param index : int - Index of the CountryState object to return.
	 * @return CountryState*
	 */
	CountryState *getCountryState(int index);

	/**
	 * @brief Get the Military State object stored by the SimulationState
	 *
	 * Exceptions : std::out_of_range if the SimulationState does not hold a MilitaryState
	 * 
	 * @param index : int - Index of the MilitaryState object to return.
	 * @return MilitaryState*
	 */
	MilitaryState *getMilitaryState(int index);

	/**
	 * @brief Get the number of CountryState objects stored by the SimulationState
	 *
	 * @return int
	 */
	int getCountryStateCount();

	/**
	 * @brief Get the number of MilitaryState objects stored by the SimulationState
	 *
	 * @return int
	 */
	int getMilitaryStateCount();

	/**
	 * @brief Get the Timestamp object stored by the SimulationState
	 *
	 * @return std::time_t
	 */
	std::time_t getTimestamp();

private:
	MapState *mapState;
	SimulationManager *simulationManager;
	std::vector<CountryState *> *countryStates;
	std::vector<MilitaryState *> *militaryStates;
	std::time_t timestamp;
};

#endif
