#ifndef __Territory_h__
#define __Territory_h__

#include <exception>
#include "Location.h"

class LocationIterator;
class Neighbour;
class Country;

class Territory: public Location
{
	
	public:
		/**
		 * @brief Construct a new Territory object.
		 * 
		 * @param _x : int - x coordinate of the location.
		 * @param _y : int - y coordinate of the location.
		 * @param _colour : char - colour of the territory.
		 */
		Territory(int _x, int _y, char _colour='a');

		/**
		 * @brief Destructor for the Territory class. Delete location if location is not NULL.
		 * 
		 */
		~Territory();

		/**
		 * @brief If location is NULL set location to equal _neighbour else call add on location sending _neighbour in as the parameter.
		 * 
		 * @param _neighbour : Location* - Pointer to the location to be added.
		 */
		void add(Location* _neighbour);

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
		 * @brief Create a copy of this locations attributes except for anything to do with it's neighbour.
		 * 
		 * @return Location* 
		 */
		Location* clone();
		
		/**
		 * @brief Return the colour attribute.
		 * 
		 * @return char 
		 */
		char getColour();

		/**
		 * @brief Return the xCoordinate value.
		 * 
		 * @return int 
		 */
		int getX();

		/**
		 * @brief Return the yCoordinate value.
		 * 
		 * @return int 
		 */
		int getY();

	protected:
		int xCoordinate, yCoordinate;

	private:
		Country* ownedBy;
		char colour;
		bool isCapital;
		bool isLand;

};

#endif
