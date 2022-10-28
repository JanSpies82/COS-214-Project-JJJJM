#ifndef __TopNeighbour_h__
#define __TopNeighbour_h__

#include <exception>
#include "Neighbour.h"

// class Neighbour;
class Location;
class TopNeighbour;


class TopNeighbour: public Neighbour
{
	public:

		/**
		 * @brief The constructor for top neighbour
		 * 
		 * @param _neighbour : Location* - adds this location as the top neighbour of a location 
		 */
		TopNeighbour(Location* _location, Location* _neighbour);

		/**
		 * @brief Set the topLocation object to the passed in _top parameter
		 * 
		 * @param _neighbour : Location* - parameter to set the topLocation object to 
		 * @param _location : Location* - location to which _neighbour is added 
		 */
		void setNeighbour(Location* _neighbour);
		
 		/**
		 * @brief Calls the getTop function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getRight();

		/**
		 * @brief  Calls the getTop function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getLeft();

		/**
		 * @brief Returns top neighbour if it has a top neighbour return null otherwise.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getTop();

		/**
		 * @brief Calls the getTop function of location.
		 * 
		 * Exceptions : null_pointer_exception
		 * 
		 * @return Location* 
		 */
		Location* getBottom();

		~TopNeighbour();

		bool hasRight();
		bool hasLeft();
		bool hasTop();
		bool hasBottom();
};

#endif
