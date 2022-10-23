#include <exception>

#include <ctime>

#ifndef __MilitaryState_h__
#define __MilitaryState_h__


class MilitaryState
{
	

	public:

		std::time_t timestamp;
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
		vector<Military>* State;
	
};

#endif
