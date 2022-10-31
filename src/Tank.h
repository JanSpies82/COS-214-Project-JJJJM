#include <exception>

#ifndef __Tank__h__
#define __Tank__h__

#include "Vehicle.h"
	/**
	 * @brief The Tank class is an inherited class from vehicle. 
	 * defines the operations and attributes of the Tank class
	 **/

class Tank: public Vehicle
{

	public: 
		/**
		 * @brief constructs the Tank Object
		 **/
		Tank();
		/**
		 * @brief constructs the Tank Object
		 * @param int - damage
		 **/
		Tank(int,int);
		/**
		 * @brief destroys the Tank Object
		 **/
		virtual ~Tank();
		/**
		 * @brief attacks an enemy country 
		 * @param Country* - passes in country to be attacked
		 **/
		void attack(Country* enemy);
		/**
		 * @brief finds a enemy geologically
		 **/
		void findEnemy();
		/**
		 * @brief destroys an enemy country 
		 * @param Country* - passes in country to be eliminated
		 **/
		void destroyEnemy(Country* enemy);
		/**
		 * @brief sets the number Battalions an attack of a Tank kills.
		 * @param int of the number of Battalions
		 **/
		void setNumBattalionDestroys(int);
		/**
		 * @brief sets the number of Tanks an attack of a Tank destroys.
		 * @param int of the number of Tanks
		 **/
		void setNumTankDetroys(int);
		/**
		 * @brief retrieve number of battallions the tank can destroy
		 * @return int - number of Battalions
		 **/
		int getBattalionDestroyed();
		/**
		 * @brief retrieve number of Tanks the tank can destroy
		 * @return int - number of Tanks
		 **/
		int getTankDestroyed();
	private: 
		int numBattalionDestroys;
		int numTankDestroys;

};

#endif
