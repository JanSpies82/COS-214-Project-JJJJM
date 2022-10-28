#ifndef __RightNeighbour_h__
#define __RightNeighbour_h__

#include <exception>
#include "Neighbour.h"

// class Neighbour;
class Location;
class RightNeighbour;

class RightNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for right neighbour
		 * 
		 * @param _neighbour : Location* - Adds this location as the right neighbour of a location
		 * @param _location : Location* - Location to which _neighbour is added  
		 */
		RightNeighbour(Location* _location, Location* _neighbour);

		/**
		 * @brief Set the rightLocation object to the passed in _right parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the rightLocation object to 
		 */
		void setNeighbour(Location* _neighbour);

		 /**
		 * @brief Calls the getRight function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief Returns right neighbour if it has a right neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Calls the getRight function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Calls the getRight function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

				~RightNeighbour();
};

#endif
