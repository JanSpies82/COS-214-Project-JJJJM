#include <exception>
using namespace std;

#ifndef __CountryMediator_h__
#define __CountryMediator_h__

// #include "Country.h"

class Country;
class CountryMediator;

class CountryMediator
{
	public: Country* countrys;

	public: void notify(Country* country);
};

#endif
