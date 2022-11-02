#ifndef __Neighbour_h__
#define __Neighbour_h__

#include "Location.h"

class Neighbour: public Location
{

	public:
		/**
		 * @brief Constructor for Neighbour class.
		 * 
		 * @param _neighbour : Location* - Pointer to the added neighbour location.
		 */
		Neighbour(Location* _neighbour);

		/**
		 * @brief Destructor for the Neighbour class.
		 * 
		 */
		virtual ~Neighbour();

		/**
		 * @brief If location is NULL set location to equal _neighbour else call add on location sending _neighbour in as the parameter.
		 * 
		 * @param _neighbour : Location* - Pointer to the location to be added.
		 */
		virtual void add(Location* _neighbour);

	protected:
		Location* neighbour;

};

#endif
