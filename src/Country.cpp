/// @author Jake Weatherhead

#include "Country.h"
#include "WarStage.h"
#include "Superpower.h"
#include "Military.h"
#include "CountryState.h"
#include "CountryMediator.h"
#include "Strategy.h"

Country::Country() 
{

}

void Country::request()
{
	return;
}

void Country::notify()
{
	return;
}

void Country::attach()
{
	return;
}

void Country::detach()
{
	return;
}

void Country::algorithm()
{
	return;
}

CountryState* Country::getState()
{
  // generate current state
  // return current state
  return NULL;
}

double Country::getCountryRating()
{
  std::vector<int> militaryCoefficients;
  std::vector<int> mapCoefficients;
  std::vector<int> domesticCoefficients;

  militaryCoefficients = getMilitaryCoefficients();
  mapCoefficients = getMapCoefficients();
  domesticCoefficients = getDomesticCoefficients();


}

std::vector<int> Country::getMilitaryCoefficients()
{
  std::vector<int> militaryCoefficients;
  // evaluate all aspects of military
  return militaryCoefficients;
}

std::vector<int> Country::getMapCoefficients()
{
  std::vector<int> mapCoefficients;
  // evaluate all aspects of map
  return mapCoefficients;
}

std::vector<int> Country::getDomesticCoefficients()
{
  std::vector<int> domesticCoefficients;
  // evaluate all domestic aspects of this country
  return domesticCoefficients;
}

