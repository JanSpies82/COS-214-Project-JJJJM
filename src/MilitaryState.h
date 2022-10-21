#include <exception>
using namespace std;

#ifndef __MilitaryState_h__
#define __MilitaryState_h__



// class SimulationState;
class MilitaryState;

class MilitaryState
{
	private: std::time_t timestamp;

	public: MilitaryState(Military* m);

	public: virtual void simulationState();
};

#endif
