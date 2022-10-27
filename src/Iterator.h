#ifndef __Iterator_h__
#define __Iterator_h__

#include <exception>
#include "Territory.h"
#include "Location.h"

class Location;
class Iterator;

class Iterator
{

	public: 
		Location* current;
		
		/**
		 * @brief Sets current to the next location in the sequential iteration of the map
		 * 
		 */
		virtual void next() = 0;

		/**
		 * @brief Sets current to the top left location of the map
		 * 
		 */
		virtual void topLeft() = 0;	

		/**
		 * @brief Shifts current pointer to it's right neighbour
		 * 
		 */
		virtual void right() = 0;	

		/**
		 * @brief Shifts current pointer to it's left neighbour
		 * 
		 */	
		virtual void left() = 0;

		/**
		 * @brief Shifts current pointer to it's bottom neighbour
		 * 
		 */		
		virtual void down() = 0;

		/**
		 * @brief Shifts current pointer to it's top neighbour
		 * 
		 */		
		virtual void up() = 0;	

		/**
		 * @brief Returns true if sequential iteration is complete and false otherwise
		 * 
		 * @return boolean 
		 */
		virtual bool isDone() = 0;	
			
		/**
		 * @brief Returns the pointer to the current location
		 * 
		 * @return Location* 
		 */
		virtual Location* getCurrent() = 0;
};

#endif
