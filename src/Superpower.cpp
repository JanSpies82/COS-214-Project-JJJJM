///@author Janco Spies

#include "Superpower.h"
#include "Country.h"
#include "SuperpowerState.h"
#include "CountryState.h"
#include "Map.h"
#include <stdexcept>
#include <iostream>

using namespace std;

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

Superpower::Superpower(string _name)
{
    name = _name;
    countries = new vector<Country *>();
}

Superpower::Superpower(SuperpowerState *_state)
{
    name = _state->getName();
    countries = new vector<Country *>();
    for (int i = 0; i < _state->getCountryStateCount(); i++)
    {
        Country *c = new Country();
        c->setState(_state->getCountryState(i)->clone());
        c->getState()->setIsBeingStored(false);
        countries->push_back(c);
    }
}

Superpower::~Superpower()
{
    for (int i = 0; i < countries->size(); i++)
    {
        delete countries->at(i);
    }
    delete countries;
}

string Superpower::getName()
{
    return name;
}

void Superpower::addCountry(Country *_country)
{
    countries->push_back(_country);
}

int Superpower::getCountryCount()
{
    return countries->size();
}

Country *Superpower::getCountry(int _index)
{
    if (_index < 0 || _index >= countries->size())
    {
        throw out_of_range("Index out of range");
    }
    return countries->at(_index);
}

void Superpower::removeCountry(Country *_country)
{
    for (int i = 0; i < countries->size(); i++)
    {
        if (countries->at(i) == _country)
        {
            countries->erase(countries->begin() + i);
            return;
        }
    }
    throw out_of_range("Country not owned by superpower");
}

SuperpowerState *Superpower::getState()
{
    SuperpowerState *state = new SuperpowerState(name);
    for (int i = 0; i < countries->size(); i++)
    {
        state->addCountryState(countries->at(i)->getState()->clone());
        state->getCountryState(i)->setIsBeingStored(true);
    }
    return state;
}

void Superpower::printSummary()
{
    cout << CYAN << "Superpower: " << name << RESET << endl;
    cout << "Countries: " << countries->size() << endl;
    for (int i = 0; i < countries->size(); i++)
    {
        cout << "\t" << countries->at(i)->getName() << endl;
    }
}

void Superpower::resetLocations(Map *_map)
{
    for (int i = 0; i < countries->size(); i++)
    {
        countries->at(i)->resetLocations(_map);
    }
}

void Superpower::resetEnemies(vector<Country *> *_enemies)
{
    for (int i = 0; i < countries->size(); i++)
    {
        countries->at(i)->resetEnemies(_enemies);
    }
}

std::vector<Country *> *Superpower::getAllCountries()
{
    return countries;
}
