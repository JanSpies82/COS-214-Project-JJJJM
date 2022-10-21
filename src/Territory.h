#include <exception>
using namespace std;

#ifndef __Territory_h__
#define __Territory_h__

// #include "LocationIterator.h"
#include "Location.h"

class LocationIterator;
// class Location;
class Territory;

class Territory: public Location
{
	public:
		LocationIterator* locationIterators;

		/**
		 * @brief Construct a new Territory object
		 * 
		 * @param _x : int - x coordinate of the location
		 * @param _y : int - y coordinate of the location
		 */
		Territory(int _x, int _y);

		/**
		 * @brief Create a Iterator object and store it in locationIterators
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();

	protected:
		int xCoordinate, yCoordinate;

		/**
		 * @brief Add a neighbour to the neighbours array
		 * 
		 * @param _neighbour: The neighbour to be added
		 */
		void add(Neighbour* _neighbour);
};

#endif
