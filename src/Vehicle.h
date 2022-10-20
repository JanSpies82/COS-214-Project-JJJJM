#include <exception>
using namespace std;

#ifndef __Vehicle_h__
#define __Vehicle_h__

// #include "Military.h"

class Military;
class Vehicle;

__abstract class Vehicle
{
	public: Military* militarys;

	public: void attack();

	public: virtual void findEnemy() = 0;

	public: virtual void destroyEnemy() = 0;
};

#endif
