/// @author Julian Pienaar

#ifndef __Location_h__
#define __Location_h__

#include <string>

class Map;
class Observer;
class Iterator;
class Country;

class Location
{

	public: 
		/**
		 * @brief Destructor for the Location class.
		 * 
		 */
		virtual ~Location();
		
		/**
		 * @brief Returns a new Iterator object with current set to this Location.
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();

		/**
		 * @brief If location is NULL throw exception else call getRight on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range if this location has no right neighbour.
		 * 
		 * @return Location* 
		 */
		virtual Location* getRight();

		/**
		 * @brief If location is NULL throw exception else call getLeft on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range if this location has no left neighbour.
		 * 
		 * @return Location* 
		 */
		virtual Location* getLeft();

		/**
		 * @brief If location is NULL throw exception else call getTop on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range if this location has no top neighbour.
		 * 
		 * @return Location* 
		 */
		virtual Location* getTop();

		/**
		 * @brief If location is NULL throw exception else call getBottom on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range if this location has no bottom neighbour.
		 * 
		 * @return Location* 
		 */
		virtual Location* getBottom();

		/**
		 * @brief Abstract function specifying how to add neighbour to a location.
		 * 
		 * @param _neighbour : Location* -  Pointer to the neighbour to be added.
		 */
		virtual void add(Location* _neighbour) = 0;

		/**
		 * @brief Return false if location is NULL and call hasBottom on location otherwise.
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool hasBottom();

		/**
		 * @brief Return false if location is NULL and call hasRight on location otherwise.
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool hasRight();

		/**
		 * @brief Return false if location is NULL and call hasLeft on location otherwise.
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool hasLeft();

		/**
		 * @brief Return false if location is NULL and call hasTop on location otherwise.
		 * 
		 * @return true 
		 * @return false 
		 */
		virtual bool hasTop();

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
		std::string getColor();

		/**
		 * @brief Set the Colour attribute.
		 * 
		 * @param _colour : char - variable to set colour to.
		 */
		void setColor(/*char _colour*/std::string _color);

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

		/**
		 * @brief Get the Is Land attribute.
		 * 
		 * @return bool 
		 */
		bool getIsLand();

		/**
		 * @brief Set the Is Land attribute.
		 * 
		 * @param _isLand : bool - variable to set isLand to.
		 */
		void setIsLand(bool _isLand);

		/**
		 * @brief Get the Is Capital attribute.
		 * 
		 * @return bool
		 */
		bool getIsCapital();

		/**
		 * @brief Set the Is Capital attribute.
		 * 
		 * @param _isCapital : bool - variable to set isCapital to.
		 */
		void setIsCapital(bool _isCapital);
	
	protected:
		Location* location;
		Country* ownedBy;
		std::string color;
		bool isCapital;
		bool isLand;
		int xCoordinate, yCoordinate;

};

#endif
