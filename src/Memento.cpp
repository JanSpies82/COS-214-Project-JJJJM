
#include "Memento.h"
#include "Backup.h"
#include "SimulationState.h"

SimulationState* Memento::getState() {
	return this->state;
}

void Memento::setState(SimulationState* s) {
	this->state = s;
}

