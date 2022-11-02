///@author Janco Spies
#include "Superpower.h"
#include "Country.h"
#include "SuperpowerState.h"
#include <stdexcept>
#include <iostream>

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

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

void Superpower::printSummary(){
    cout << CYAN << "Superpower: " << name << RESET << endl;
    cout << "Countries: " << countries->size() << endl;
    for (int i = 0; i < countries->size(); i++){
        // countries->at(i)->printSummary();
    }
}