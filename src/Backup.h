
#ifndef __Backup_h__
#define __Backup_h__

// #include "Memento.h"

#include <vector>

class Memento;
class Backup;

class Backup
{
public:
	/**
	 * @brief Construct a new Backup object
	 * 
	 */
	Backup();

	/**
	 * @brief Destroy the Backup object and all its Mementos
	 * 
	 */
	~Backup();

	/**
	 * @brief Add a new memento to the backup
	 * 
	 * @param _memento : Memento* - the memento to add
	 */
	void addMemento(Memento *_memento);

	/**
	 * @brief Get the last added Memento object and remove it from the backup
	 * 
	 * Exceptions : std::out_of_range if the backup is empty
	 * 
	 * @return Memento* - pointer to the last added Memento
	 */
	Memento *getMemento();

	/**
	 * @brief Get the number of Mementos currently stored in the backup
	 * 
	 * Returns 0 if the backup is empty
	 * 
	 * @return int 
	 */
	int getMementoCount();

	/**
	 * @brief Delete all of the Mementos stored in the backup
	 * 
	 */
	void clear();

private:
	std::vector<Memento *> *mementos;
};

#endif
