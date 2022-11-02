#ifndef __Plane_h__
#define __Plane_h__

#include <exception>

#include "Vehicle.h"

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
