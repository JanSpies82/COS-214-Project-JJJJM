#ifndef __Tank__h__
#define __Tank__h__

#include <exception>

#include "Vehicle.h"

class Tank : public Vehicle
{

public:
	/**
	 * @brief constructs the Tank Object
	 **/
	Tank();

	/**
	 * @brief destroys the Tank Object
	 **/
	~Tank();
};

#endif
