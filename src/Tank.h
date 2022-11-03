/// @author Jake Mahloko

#ifndef __Tank__h__
#define __Tank__h__

#include <exception>
#include "Vehicle.h"

class Tank: public Vehicle
{

public:
	/**
	 * @brief constructor for the tank object
	 **/
	Tank();

	/**
	 * @brief destructor for the tank object
	 **/
	~Tank();
};

#endif
