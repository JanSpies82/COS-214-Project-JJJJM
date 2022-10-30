#ifndef __Location_h__
#define __Location_h__

class Map;
class Observer;
class Iterator;

class Location
{
	public: 

		/**
		 * @brief Returns a new Iterator object with current set to this Location.
		 * 
		 * @return Iterator* 
		 */
		Iterator* createIterator();

		/**
		 * @brief If location is NULL throw exception else call getRight on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range
		 * 
		 * @return Location* 
		 */
		virtual Location* getRight();
		/**
		 * @brief If location is NULL throw exception else call getLeft on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range
		 * 
		 * @return Location* 
		 */
		virtual Location* getLeft();

		/**
		 * @brief If location is NULL throw exception else call getTop on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range
		 * 
		 * @return Location* 
		 */
		virtual Location* getTop();

		/**
		 * @brief If location is NULL throw exception else call getBottom on the location object.
		 * 
		 * Exceptions : std::__throw_out_of_range
		 * 
		 * @return Location* 
		 */
		virtual Location* getBottom();

		/**
		 * @brief Abstract function specifying how to add neighbour to a location.
		 * 
		 * @param _neighbour 
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
		 * @brief Abstract function specifying how to get a locations colour.
		 * 
		 * @return char 
		 */
		virtual char getColour() = 0;
	
	protected:
		Location* location;
		const int RIGHT=0,LEFT=1,UP=2,DOWN=3;
};

#endif
