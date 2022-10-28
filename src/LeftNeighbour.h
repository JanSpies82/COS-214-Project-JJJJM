#ifndef __LeftNeighbour_h__
#define __LeftNeighbour_h__

#include <exception>
#include "Neighbour.h"

// class Neighbour;
class Location;
class LeftNeighbour;

class LeftNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for left neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the left neighbour of a location 
		 * @param _location : Location* - location to which _neighbour is added 
		 */
		LeftNeighbour(Location* _location, Location* _neighbour);

		/**
		 * @brief Set the leftLocation object to the passed in _left parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the leftLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

		 /**
		 * @brief Calls the getLeft function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief Returns left neighbour if it has a left neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Calls the getLeft function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Calls the getLeft function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

				~LeftNeighbour();
};

#endif
