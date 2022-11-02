#ifndef __Ship_h__
#define __Ship_h__

#include <exception>

#include "Vehicle.h"
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
