/// @author Jake Weatherhead

#include "Country.h"
#include "WarStage.h"
#include "Superpower.h"
#include "Military.h"
#include "CountryState.h"
#include "CountryMediator.h"
#include "Strategy.h"

/// @todo fine-tune weights and numWeights per class
Country::Country() 
{
  for (int i = 0; i < 10; i++)
  {
    mapWeights.push_back(0.2);
  }

  for (int i = 0; i < 10; i++)
  {
    militaryWeights.push_back(0.2);
  }

  for (int i = 0; i < 10; i++)
  {
    domesticWeights.push_back(0.2);
  }
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

/**
 * @brief  composite function that generates this country's strength score
 * @return the strength score of this country
 */
double Country::getCountryRating()
{
  std::vector<int> militaryCoefficients;
  std::vector<int> mapCoefficients;
  std::vector<int> domesticCoefficients;

  militaryCoefficients = getMilitaryCoefficients();
  mapCoefficients = getMapCoefficients();
  domesticCoefficients = getDomesticCoefficients();

  double strengthRating = 0.0;

  for (int i = 0; i < militaryCoefficients.size(); i++)
  {
    strengthRating += militaryCoefficients[i] * militaryWeights.at(i);
  }

  for (int i = 0; i < mapCoefficients.size(); i++)
  {
    strengthRating += mapCoefficients[i] * mapWeights.at(i);
  }

  for (int i = 0; i < domesticCoefficients.size(); i++)
  {
    strengthRating += domesticCoefficients[i] * domesticWeights.at(i);
  }

  return strengthRating;
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

