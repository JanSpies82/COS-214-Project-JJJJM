/// @author Janco Spies

#include "Memento.h"
#include "SimulationState.h"

using namespace std;

Memento::Memento()
{
	state = NULL;
}

Memento::Memento(SimulationState *_simulationState)
{
	this->state = _simulationState;
}

Memento::~Memento()
{
	delete state;
}

SimulationState *Memento::getState()
{
	if (state == NULL)
		__throw_out_of_range("Memento does not hold a SimulationState");
	return this->state;
}

void Memento::setState(SimulationState *_simulationState)
{
	this->state = _simulationState;
}
