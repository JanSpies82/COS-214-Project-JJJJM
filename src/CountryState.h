#include <exception>
using namespace std;

#ifndef __CountryState_h__
#define __CountryState_h__

// #include "Country.h"
#include "SimulationState.h"

class Country;
// class SimulationState;
class CountryState;

class CountryState: public SimulationState
{
	private: std::time_t timestamp;
	public: Country* request;

	public: CountryState(Country* c);

	public: virtual void simulationState();
};

#endif
