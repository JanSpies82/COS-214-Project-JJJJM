/// @author Janco Spies

#include "Backup.h"
#include "SimulationManager.h"
#include "Memento.h"

using namespace std;

Backup::Backup()
{
    this->mementos = new vector<Memento *>();
}

Backup::~Backup()
{
    this->clear();
    delete this->mementos;
}

void Backup::addMemento(Memento *_memento)
{
    this->mementos->push_back(_memento);
}

Memento *Backup::getMemento()
{
    if (this->mementos->size() == 0)
        __throw_out_of_range("Backup is empty");
    
    Memento *memento = this->mementos->back();
    this->mementos->pop_back();
    return memento;
}

int Backup::getMementoCount()
{
    return this->mementos->size();
}

void Backup::clear()
{
    for (int i = 0; i < this->mementos->size(); i++)
        delete this->mementos->at(i);
    
    this->mementos->clear();
}

