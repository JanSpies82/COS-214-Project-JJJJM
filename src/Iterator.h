/// @author Janco Spies

#ifndef __Iterator_h__
#define __Iterator_h__

#include <exception>
#include "Location.h"

class Location;

class Iterator
{

	public:
		/**
		 * @brief Sets current to the next location in the sequential iteration of the map.
		 * 
		 * Exceptions : out_of_range if there is no next location.
		 *
		 */
		virtual void next() = 0;

		/**
		 * @brief Sets current to the top left location of the map.
		 *
		 */
		virtual void first() = 0;

		/**
		 * @brief Returns true if sequential iteration is complete and false otherwise.
		 *
		 * @return boolean
		 */
		virtual bool isDone() = 0;

		/**
		 * @brief Returns the pointer to the current location.
		 *
		 * @return Location*
		 */
		virtual Location *getCurrent() = 0;

	protected:
		Location *current;

};

#endif
