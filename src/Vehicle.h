#include <exception>
using namespace std;

#ifndef __Vehicle_h__
#define __Vehicle_h__
#include"Country.h"//every vehicle is going to use attack to attack each Country
	/**
	 * @brief The Vehicle class is an abstract class of the different vehicle. 
	 * derived Vehicles inherit from the Vehicle class
	 **/
 class Vehicle
{
	
	public:
		/**
		 * @brief constructs a Vehicle object
		 **/ 
		Vehicle();
		/**
		 * @brief destroys a Vechile object
		 **/
		virtual ~Vehicle();

};

#endif
