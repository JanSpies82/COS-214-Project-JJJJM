
#ifndef __Backup_h__
#define __Backup_h__

// #include "SimulationManager.h"
// #include "Memento.h"

#include <vector>

class SimulationManager;
class Memento;
class Backup;

class Backup
{
public:
	Backup();
	~Backup();
	void addMemento(Memento *_memento);
	Memento *getMemento();
	int getMementoCount();
	void clear();

private:
	SimulationManager *simulationManager;
	std::vector<Memento *> *mementos;
};

#endif
