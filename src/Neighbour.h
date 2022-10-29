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

		virtual ~Neighbour();

		/**
		 * @brief Create an Iterator object.
		 * 
		 * @return Iterator* 
		 */
		virtual Iterator* createIterator();

		virtual char getColour();
		virtual void add(Location* _neighbour);

	protected:
		Location* neighbour;

};

#endif
