#include <exception>
using namespace std;

#ifndef __ShipFactory_h__
#define __ShipFactory_h__

#include "VehicleFactory.h"
	/**
	*@brief ShipFactory Inherits from the VehicleFactory class which it uses the factory method 
	*to create Ship objects and return pointer to the object 
 	**/
class ShipFactory: public VehicleFactory
{

	public: 
		/**
		 * @brief construct a new ShipFactory object
		 **/
		ShipFactory();
		/**
		 * @brief destroy a ShipFactory object
		 **/
		~ShipFactory();
		/**
		 * @brief creates Ship object which inherits from Vehicle
		 * @return Vehicle* but this class will send a Ship object 
		 **/
		 Vehicle* manufactureVehicle();
};

#endif
