#ifndef __LocationIterator_h__
#define __LocationIterator_h__

#include <exception>
#include "Iterator.h"

class Territory;
class Location;
class Iterator;
class LocationIterator;

class LocationIterator: public Iterator
{
	public:
		Location* current;
		
		/**
		 * @brief Sets current to the next location in the sequential iteration of the map
		 * 
		 */
		void next();

		/**
		 * @brief Sets current to the top left location of the map
		 * 
		 */
		void topLeft();	

		/**
		 * @brief Shifts current pointer to it's right neighbour
		 * 
		 */
		void right();	

		/**
		 * @brief Shifts current pointer to it's left neighbour
		 * 
		 */	
		void left();

		/**
		 * @brief Shifts current pointer to it's bottom neighbour
		 * 
		 */		
		void down();

		/**
		 * @brief Shifts current pointer to it's top neighbour
		 * 
		 */		
		void up();	

		/**
		 * @brief Returns true if sequential iteration is complete and false otherwise
		 * 
		 * @return boolean 
		 */
		bool isDone();	
			
		/**
		 * @brief Returns the pointer to the current location
		 * 
		 * @return Location* 
		 */
		Location* getCurrent();
};

#endif
