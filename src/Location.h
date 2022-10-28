#ifndef __Location_h__
#define __Location_h__

#include <exception>
// #include "Map.h"
// #include "LocationIterator.h"
// #include "Observer.h"
// #include "Neighbour.h"

class Map;
// class LocationIterator;
class Observer;
class Iterator;
// class Neighbour;
// class Location;

class Location
{
	public: 
		Map* map;
		// LocationIterator* locationIterator;
		Observer* observer;
		// Neighbour* neighbour;


		/**
		 * @brief Abstract function which specifies that all inheriting classes should have a createIterator() function.
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator() = 0;

		/**
		 * @brief Returns right neighbour if it has a right neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getRight() = 0;

		/**
		 * @brief Returns left neighbour if it has a left neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getLeft() = 0;

		/**
		 * @brief Returns top neighbour if it has a top neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getTop() = 0;

		/**
		 * @brief Returns bottom neighbour if it has a bottom neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getBottom() = 0;

		virtual ~Location();
	
	protected:
		const int RIGHT=0,LEFT=1,UP=2,DOWN=3;
};

#endif
