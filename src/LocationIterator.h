#include <exception>
using namespace std;

#ifndef __LocationIterator_h__
#define __LocationIterator_h__

// #include "Territory.h"
// #include "Location.h"
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


		//void isDone();		
		//void current();
};

#endif
