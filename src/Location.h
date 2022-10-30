#ifndef __Location_h__
#define __Location_h__

#include <exception>

class Map;
class Observer;
class Iterator;

class Location
{
	public: 
		Map* map;
		Observer* observer;

		virtual ~Location();

		/**
		 * @brief Abstract function which specifies that all inheriting classes should have a createIterator() function.
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();

		/**
		 * @brief Returns right neighbour if it has a right neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getRight();

		/**
		 * @brief Returns left neighbour if it has a left neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getLeft();

		/**
		 * @brief Returns top neighbour if it has a top neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getTop();

		/**
		 * @brief Returns bottom neighbour if it has a bottom neighbour return null otherwise
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		virtual Location* getBottom();

		virtual void add(Location* _neighbour) = 0;
		virtual bool hasBottom();
		virtual bool hasRight();
		virtual bool hasLeft();
		virtual bool hasTop();
		virtual char getColour() = 0;
	
	protected:
		Location* location;
		const int RIGHT=0,LEFT=1,UP=2,DOWN=3;
};

#endif
