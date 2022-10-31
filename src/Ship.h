#include <exception>


#ifndef __Ship_h__
#define __Ship_h__

#include "Vehicle.h"
	/**
	 * @brief The Ship class is an inherited class from vehicle. 
	 * defines the operations and attributes of the Ship class
	 **/

class Ship: public Vehicle
{

	public: 
		/**
		 * @brief constructs the Ship Object
		 **/
		Ship();
		/**
		 * @brief destroys the Ship Object
		 **/
		virtual ~Ship();
		/**
		 * @brief Ship attacks an enemy country 
		 * @param Country* - passes in country to be attacked
		 **/
		void attack(Country* enemy);
		/**
		 *@brief finds a enemy geologically
		 **/
		void findEnemy();
		/**
		 * @brief destroys an enemy country 
		 * @param Country* - passes in country to be eliminated
		 **/
		void destroyEnemy(Country* enemy);
		/**
		 * @brief sets the number Battalions an attack of a Ship kills.
		 * @param int of the number of Battalions
		 **/
		void setNumBattalionDestroys(int);
		/**
		 * @brief sets the number of Ships an attack of a Ship destroys.
		 * @param int of the number of Ships
		 **/
		void setNumShipDestroys(int);
		/**
		 * @brief retrieve number of battallions the Ship can destroy
		 * @return int - number of Battalions
		 **/
		int getBattalionDestroyed();
		/**
		 * @brief retrieve number of Ship the Ship can destroy
		 * @return int - number of Ships
		 **/
		int getShipDestroyed();
	private:
		int numBattalionDestroys;
		int numShipDestroys;
};

#endif
