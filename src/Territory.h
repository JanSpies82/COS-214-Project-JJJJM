#include <exception>
using namespace std;

#ifndef __Territory_h__
#define __Territory_h__

// #include "Country.h"
// #include "LocationIterator.h"
#include "Location.h"

class LocationIterator;
class Neighbour;
class Country;
// class Location;
// class Territory;

class Territory: public Location
{
	public:
		LocationIterator* locationIterator;

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

		/**
		 * @brief Return a pointer to the country which owns this territory
		 * 
		 * @return Country* 
		 */
		Country* getOwnedBy();


		/**
		 * @brief Set which country owns this territory
		 * 
		 * @param _newOwner : Country* - the pointer to the new owner of the territory.
		 */
		void setOwnedBy(Country* _newOwner);

	protected:
		int xCoordinate, yCoordinate;

		/**
		 * @brief Add a neighbour to the neighbours array
		 * 
		 * @param _neighbour: The neighbour to be added
		 */
		void add(Neighbour* _neighbour);

	private:
		Country* ownedBy;
};

#endif
