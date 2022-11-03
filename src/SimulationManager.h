
#ifndef __SimulationManager_h__
#define __SimulationManager_h__

// #include "Map.h"
// #include "SimulationState.h"
// #include "Superpower.h"
// #include "Backup.h"

#include <vector>

class Map;
class SimulationState;
class Superpower;
class Backup;
class SimulationManager;
class Country;

class SimulationManager
{
public:
	/**
	 * @brief Construct a new Simulation Manager object
	 *
	 */
	SimulationManager();

	/**
	 * @brief Destroy the Simulation Manager object and free all memory
	 *
	 */
	virtual ~SimulationManager();

	/**
	 * @brief Run the simulation from an initial state to completion
	 *
	 */
	void runSimulation();

protected:
	/**
	 * @brief Restore the state of the simulation to the last saved state
	 *
	 * @return true if the state was restored
	 * @return false if the state was not restored
	 */
	bool restoreState();

	/**
	 * @brief Save the current state of the simulation in the backup
	 *
	 */
	void saveState();

	/**
	 * @brief Setup the simulation to its initial state
	 *
	 */
	void resetSimulation();

	/**
	 * @brief Check whether the simulation has completed or not
	 *
	 * @return true if the simulation has not completed
	 * @return false if the simulation has completed
	 */
	bool isSimulationRunning();

	/**
	 * @brief Take a turn in the simulation by having each country take a turn
	 * 
	 * Increments the turn count and facilitates the switching of war stages. Also saves the state of the system before the turn is taken
	 *
	 */
	void takeTurn();

	/**
	 * @brief Provide the user with a summary of the simulation at this point in time
	 * 
	 * Also view the menu of next options available to the user
	 */
	void viewSummary();

	/**
	 * @brief Display the menu of options available to the user and perform that action
	 * 
	 * In design mode will allow the user to change the state of the simulation
	 */
	void processMenu();

	/**
	 * @brief Display a detailed summary of a country within the simulation
	 * 
	 */
	void viewCountrySummary();

	/**
	 * @brief Change the state of the simulation in design mode
	 * 
	 */
	void designModeAction();

	/**
	 * @brief Display the last message of the simulation providing a summary of the simulation as a whole after completion
	 * 
	 */
	void finalMessage();

private:
	Map *map;
	std::vector<Superpower *> *superpowers;
	Backup *backup;
	bool designMode, isRunning;
	int turnCount, maxTurnCount;
	void setSuperpowers();
	void setDesignMode();
	void setUpUK(Country *_uk);
	void setUpFrance(Country *_france);
	void setUpBalkans(Country *_balkans);
	void setUpSpainPortugal(Country *_spainPortugal);
	void setUpSovietUnion(Country *_sovietUnion);
	void setUpScandanavia(Country *_scandanavia);
	void setUpGermany(Country *_germany);
	void setUpItaly(Country *_italy);
	void changeSimulationLength();
	void removeCountry();
	void alterCountryState();
	void changeWarStage();
};

#endif
