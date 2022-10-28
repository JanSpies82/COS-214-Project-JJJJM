#ifndef __Neighbour_h__
#define __Neighbour_h__

#include <exception>
#include "Location.h"

// class Location;
// class Neighbour;
class Iterator;

class Neighbour: public Location
{
	public:

		/**
		 * @brief Constructor for Neighbour class.
		 * 
		 * @param _location : Location* - Pointer to the location to which the neighbour is added.
		 * @param _neighbour : Location* - Pointer to the added neighbour location.
		 */
		Neighbour(Location* _location, Location* _neighbour);

		/**
		 * @brief Create an Iterator object.
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator();


		/**
		 * @brief Returns right neighbour if it has a right neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight() = 0;

		/**
		 * @brief Returns left neighbour if it has a left neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft() = 0;

		/**
		 * @brief Returns top neighbour if it has a top neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop() = 0;

		/**
		 * @brief Returns bottom neighbour if it has a bottom neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom() = 0;

		virtual ~Neighbour();

		virtual bool hasBottom() = 0;
		virtual bool hasRight() = 0;
		virtual bool hasLeft() = 0;
		virtual bool hasTop() = 0;

	protected:
		Location* location;
		Location* neighbour;

};

#endif
