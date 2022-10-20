#include <exception>
using namespace std;

#ifndef __Strategy_h__
#define __Strategy_h__

// #include "Country.h"

class Country;
class Strategy;

__abstract class Strategy
{
	public: Country* countrys;

	public: virtual void algorithm() = 0;
};

#endif
