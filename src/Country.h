#include <exception>
using namespace std;

#ifndef __Country_h__
#define __Country_h__

#include "WarStage.h"
// #include "Superpower.h"
// #include "Military.h"
// #include "CountryState.h"
// #include "Citizen.h"
// #include "CountryMediator.h"
// #include "Strategy.h"

class WarStage;
class Superpower;
class Military;
class CountryState;
class Citizen;
class CountryMediator;
class Strategy;
class Country;

class Country
{
	private: WarStage warStage;
	private: Strategy* strategy;
	private: CountryMediator* mediator;
	public: Superpower* superpowers;
	public: WarStage* warStages;
	public: Military* militarys;
	public: CountryState* request;
	public: Citizen* citizens;
	public: CountryMediator* countryMediators;
	public: Strategy* strategys;

	public: void request();

	public: void notify();

	public: void attach();

	public: void detach();

	public: void algorithm();
};

#endif
