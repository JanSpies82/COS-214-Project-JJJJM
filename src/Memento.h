/// @author Janco Spies

#ifndef __Memento_h__
#define __Memento_h__

class Backup;
class SimulationState;

class Memento
{
public:
	/**
	 * @brief Construct a new Memento object
	 *
	 */
	Memento();

	/**
	 * @brief Construct a new Memento object and save the passed in state
	 *
	 * @param _state : SimulationState* - The state to save
	 */
	Memento(SimulationState *_simulationState);

	/**
	 * @brief Destroy the Memento object and delete its stored SimulationState
	 *
	 */
	~Memento();

	/**
	 * @brief Get the SimulationState object stored by the Memento
	 *
	 * Exceptions : std::out_of_range if the Memento does not hold a SimulationState
	 *
	 * @return SimulationState*
	 */
	SimulationState *getState();

	/**
	 * @brief Set the SimulationState object stored by the Memento
	 *
	 * @param _state : SimulationState* - the state to store
	 */
	void setState(SimulationState *_simulationState);

private:
	SimulationState *state;
};

#endif
