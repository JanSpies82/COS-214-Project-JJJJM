///@author Janco Spies
#include "Superpower.h"
#include "Country.h"
#include "SuperpowerState.h"
#include <stdexcept>
using namespace std;

Superpower::Superpower(string _name){
    name = _name;
    countries = new vector<Country*>();
}

Superpower::~Superpower(){
    for (int i = 0; i < countries->size(); i++){
        delete countries->at(i);
    }
    delete countries;
}

string Superpower::getName(){
    return name;
}

void Superpower::addCountry(Country *_country){
    countries->push_back(_country);
}

int Superpower::getCountryCount(){
    return countries->size();
}

Country *Superpower::getCountry(int _index){
    if (_index < 0 || _index >= countries->size()){
        throw out_of_range("Index out of range");
    }
    return countries->at(_index);
}

void Superpower::removeCountry(Country *_country){
    for (int i = 0; i < countries->size(); i++){
        if (countries->at(i) == _country){
            countries->erase(countries->begin() + i);
            return;
        }
    }
    throw out_of_range("Country not owned by superpower");
}

SuperpowerState *Superpower::getState(){
    SuperpowerState *state = new SuperpowerState(name);
    for (int i = 0; i < countries->size(); i++){
        state->addCountryState(countries->at(i)->getState());
    }
    return state;
}