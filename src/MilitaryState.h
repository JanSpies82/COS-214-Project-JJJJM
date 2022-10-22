#include <exception>

#include <ctime>

#ifndef __MilitaryState_h__
#define __MilitaryState_h__


class MilitaryState;
class Military;

class MilitaryState
{
	private: std::time_t timestamp;

	public: MilitaryState(Military* m);

	public: virtual void simulationState();
};

#endif
