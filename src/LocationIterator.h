#ifndef __LocationIterator_h__
#define __LocationIterator_h__

#include <exception>
#include "Iterator.h"

class Location;

class LocationIterator : public Iterator
{

	public:
		/**
		 * @brief Construct a new Location Iterator object.
		 *
		 * @param _location : Location* - pointer to the location that is set as the current location.
		 */
		LocationIterator(Location* _location);

		/**
		 * @brief Destroy the Location Iterator object
		 *
		 */
		~LocationIterator();

		/**
		 * @brief Sets current to the next location in the sequential iteration of the map.
		 * 
		 * Exceptions : out_of_range if there is no next location.
		 *
		 */
		void next();

		/**
		 * @brief Sets current to the top left location of the map.
		 *
		 */
		void first();

		/**
		 * @brief Returns true if sequential iteration is complete and false otherwise.
		 *
		 * @return boolean
		 */
		bool isDone();

		/**
		 * @brief Returns the pointer to the current location.
		 *
		 * @return Location*
		 */
		Location *getCurrent();

	protected:
		Location *current;
		Location* nextLocation;
		bool hasNext();
		Location* nextRow();

};

#endif
