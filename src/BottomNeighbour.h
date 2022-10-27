#ifndef __BottomNeighbour_h__
#define __BottomNeighbour_h__

#include <exception>
#include "Neighbour.h"

class Location;
// class Neighbour;
class BottomNeighbour;

class BottomNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for bottom neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the bottom neighbour of a location 
		 * @param _location : Location* - location to which _neighbour is added 
		 */
		BottomNeighbour(Location* _location, Location* _neighbour);

		/**
		 * @brief Set the bottomLocation object to the passed in _bottom parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the bottomLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

		 /**
		 * @brief Calls the getBottom function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief Calls the getBottom function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Calls the getBottom function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Returns bottom neighbour if it has a bottom neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();
};

#endif
