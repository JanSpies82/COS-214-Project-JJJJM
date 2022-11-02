///@author Janco Spies
#ifndef __SuperpowerState_h__
#define __SuperpowerState_h__

#include <vector>
#include <string>

class CountryState;

class SuperpowerState
{
public:
    /**
     * @brief Construct a new Superpower State object
     * 
     * @param _name : std::string - The name of the Superpower.
     */
    SuperpowerState(std::string _name);

    /**
     * @brief Destroy the Superpower State object
     * 
     */
    ~SuperpowerState();

    /**
     * @brief Add a CountryState object to the SuperpowerState
     * 
     * @param _countryState : CountryState* - Pointer to the CountryState object.
     */
    void addCountryState(CountryState *_countryState);

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName();

    /**
	 * @brief Get the number of CountryState objects stored by the SuperpowerState
	 *
	 * @return int
	 */
	int getCountryStateCount();

    /**
     * @brief Get the Country States object
     * 
     * Exceptions : std::__throw_out_of_range if _index is out of range.
     * 
     * @return CountryState*
     */
    CountryState* getCountryState(int _index);
protected:
    std::string name;
    std::vector<CountryState*>* countryStates;
};
#endif