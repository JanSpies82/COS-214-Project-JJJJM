#include <exception>

#include "Strategy.h"
#include "Country.h"

Strategy::Strategy()
{
}

void Strategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB)
{
}

// void Strategy::takeTurn(double* strengthRatings, Country* countryA, Country* countryB)
// {
//     //ifCountryA is weaker than CountryB
//     if(strengthRatings[0] < strengthRatings[1])
//     {
//         weakerMove(countryA,countryB);
//     }
//     //if CountryA is stronger than CountryB
//     else if(strengthRatings[0] > strengthRatings[1])
//     {
//         strongerMove(countryA,countryB);
//     }
//     //if CountryA is equal in strength to COuntryB
//     else{
//         equalStrength(countryA,countryB);
//     }
// }

