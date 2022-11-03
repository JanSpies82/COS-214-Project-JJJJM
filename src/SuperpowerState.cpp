///@author Janco Spies

#include "SuperpowerState.h"
#include "CountryState.h"
#include <stdexcept>

using namespace std;

SuperpowerState::SuperpowerState(string _name)
{
    name = _name;
    countryStates = new vector<CountryState*>();
}

SuperpowerState::~SuperpowerState()
{
    for (int i = 0; i < countryStates->size(); i++)
        delete countryStates->at(i);
    delete countryStates;
}

void SuperpowerState::addCountryState(CountryState *_countryState)
{
    countryStates->push_back(_countryState);
}

int SuperpowerState::getCountryStateCount()
{
    return countryStates->size();
}

string SuperpowerState::getName()
{
    return name;
}

CountryState* SuperpowerState::getCountryState(int _index)
{
    if (_index < 0 || _index >= countryStates->size())
        throw out_of_range("Index out of range");
    return countryStates->at(_index);
}