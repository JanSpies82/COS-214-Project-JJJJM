/// @author Jake Mahloko

#ifndef __Plane_h__
#define __Plane_h__

class Country;

#include "Vehicle.h"
#include <exception>

class Plane : public Vehicle
{

public:
	/**
	 * @brief constructs the Plane Object
	 **/
	Plane();

	/**
	 * @brief destroys the Plane Object
	 **/
	~Plane();
};

#endif
