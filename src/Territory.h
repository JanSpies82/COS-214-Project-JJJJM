#ifndef __Territory_h__
#define __Territory_h__

#include <exception>
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
		 * @brief Construct a new Territory object.
		 * 
		 * @param _x : int - x coordinate of the location.
		 * @param _y : int - y coordinate of the location.
		 */
		Territory(int _x, int _y);

		/**
		 * @brief Create an Iterator object and store it in locationIterators.
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();

		/**
		 * @brief Return a pointer to the country which owns this territory.
		 * 
		 * @return Country* 
		 */
		Country* getOwnedBy();


		/**
		 * @brief Set which country owns this territory.
		 * 
		 * @param _newOwner : Country* - the pointer to the new owner of the territory.
		 */
		void setOwnedBy(Country* _newOwner);

		 /**
		 * @brief Returns null.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief  Returns null.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Returns null.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Returns null.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

		~Territory();

	protected:
		int xCoordinate, yCoordinate;

	private:
		Country* ownedBy;
		bool capital;
		bool isLand;
};

#endif
