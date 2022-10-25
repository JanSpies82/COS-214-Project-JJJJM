#include <exception>

#include <ctime>

#ifndef __MilitaryState_h__
#define __MilitaryState_h__

#include <vector>

class Military;
//TODO how does this work? If a state object is constructed in the contructor then what does storeState() do? Why is the "state" object being stored a military? Does this object just make a deep copy of a military and store that?
class MilitaryState
{
	public:
		/**
		 * @brief construct a MilitaryState Object
		 * @param Military object
		**/
		MilitaryState(Military* m);

		/**
		 * @brief stores the state of the military
		 * @param Military object
		 **/
		void storeState(Military * m);

		/**
		 * @brief retrieve the militaryState object
		 * @return the MilitaryState
		 **/
		Military* getState();
		
		private:
		std::vector<Military*>* State;
		std::time_t timestamp;
	
};

#endif
