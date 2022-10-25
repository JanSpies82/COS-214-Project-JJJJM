#include <exception>
using namespace std;

#ifndef __VehicleFactory_h__
#define __VehicleFactory_h__
#include"Vehicle.h"
	/**
 	*@brief VehicleFactory class is an abstract class that services as a template class 
 	* for the children class of VehicleFactory. The factories are used to create objects of Vehicles 
 	**/
 class VehicleFactory
{
	public:
		/**
		 * @brief construct a new VehichleFactory Object
		 **/
		VehicleFactory();
		/**
		 * @brief destroy a VehicleFactiry object
		 **/
		~VehicleFactory();
		/**
		 * @brief pure virtual -children classes creates Vehicles referenced objects
		 * @return Vehicle* -newly created vehicle
		 **/
		virtual Vehicle* manufactureVehicle() = 0;

		
		
};

#endif
