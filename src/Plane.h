#include <exception>


#ifndef __Plane_h__
#define __Plane_h__

#include "Vehicle.h"
class Country;
	/**
	 * @brief The Plane class is an inherited class from vehicle. 
	 * defines the operations and attributes of the Plane class
	 **/
class Plane : public Vehicle
{

	public: 
		/**
		 * @brief constructs the Plane Object
		 **/
		Plane();
		/**
		 * @brief constructor for Plane
		 * 
		 * @param int int int
		 */ 
		Plane(int,int,int);


		/**
		 * @brief destroys the Plane Object
		 **/
		virtual ~Plane();

		/**
		 * @brief Plane attacks an enemy country 
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
		void destroyEnemy(Country * enemy);

		/**
		 * @brief sets the number Battalions an attack of a PLane kills.
		 * @param int of the number of Battalions
		 **/
		void setNumBattalionDestroys(int);

		/**
		 * @brief sets the number of Tanks an attack of a Plane destroys.
		 * @param int of the number of Tanks
		 **/
		void setNumTankDetroys(int);

		/**
		 * @brief sets the number of Planes an attack of a Plane destroys.
		 * @param int of the number of Planes
		 **/
		void setNumPlanesDestroys(int);

		/**
		 * @brief retrieve number of Tanks the plane can destroy
		 * @return int - number of Tanks
		 **/
		int getTankDestroyed();

		/**
		 * @brief retrieve number of battallions the tank can destroy
		 * @return int - number of Battalions
		 **/
		int getBattalionDestroyed();

		/**
		 * @brief retrieve number of Planes the plane can destroy
		 * @return int - number of Planes
		 **/
		int getPlanesDestroyed();
	private:
		int numBattalionDestroys;
		int numTankDestroys;
		int numPlanesDestroys;
};

#endif
