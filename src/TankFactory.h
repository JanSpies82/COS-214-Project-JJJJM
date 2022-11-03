#include <exception>

#ifndef __TankFactory_h__
#define __TankFactory_h__

#include "VehicleFactory.h"
	/**
	*@brief TankFactory Inherits from the VehicleFactory class which it uses the factory method 
	*to create Tank objects and return pointer to the object 
 	**/
class TankFactory: public VehicleFactory
{

	public: 
		/**
		 * @brief construct a new TankFactory object
		 **/
		TankFactory();
		/**
		 * @brief destroy a TankFactory object
		 **/
		~TankFactory();
		/**
		 * @brief creates Tank object which inherits from Vehicle
		 * @return Vehicle* but this class will send a Tank object  
		 **/
		Vehicle* manufactureVehicle();
		Vehicle* manufactureVehicle(int,int);
		/**
		 * @brief Create a deep copy of the current object
		 * 
		 * @return TankFactory* 
		 */
		TankFactory* clone();
};

#endif
