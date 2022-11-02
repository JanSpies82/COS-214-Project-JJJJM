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
		/**
		 * @brief pure virtual -children class has to implement function
		 * used to attack other countries.
		 * 
		 * @description template method
		 * 
		 * The attack method in used as a template method 
		 * 
		 * where each vehicle has to possess the functionality
		 * 
		 * @param Country*-enemy Country reference object 
		 **/
		virtual void attack(Country* enemy)=0;//is it the same thing as destroy?
		/**
		 * @brief finds our enemy geologically
		 **/
		virtual void findEnemy() = 0;
		/**
		 * @brief pure virtual -children class has to implement function used to 
		 * eliminate Country
		 * @param Country*-enemy Country reference object 
		 **/
		virtual void destroyEnemy(Country* enemy) = 0;

};

#endif
