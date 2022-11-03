/// @author Jake Mahloko

#ifndef __Ship_h__
#define __Ship_h__

#include "Vehicle.h"
#include <exception>

class Ship : public Vehicle
{
public:
	/**
	 * @brief constructs the Ship Object
	 **/
	Ship();

	/**
	 * @brief destroys the Ship Object
	 **/
	~Ship();
};

#endif
