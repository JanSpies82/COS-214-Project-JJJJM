/// @author Janco Spies

#include "SimulationManager.h"
#include "Map.h"
#include "SimulationState.h"
#include "Superpower.h"
#include "Memento.h"
#include "Backup.h"
#include "WarStage.h"
#include "Country.h"

using namespace std;

string mapVal[27] = {
    "000000000000000099000066",
    "000000000000000996666666",
    "000000000000009996666666",
    "000000000000009966660066",
    "000000000000099966666666",
    "000000000000099906666666",
    "000000000000999906666666",
    "000000000009999006666666",
    "000000000009999906666666",
    "000000030009999900666666",
    "000000330009099990777666",
    "000000330000709007777766",
    "000033330000770007777777",
    "000033033000777777777777",
    "000300333077777777777777",
    "000003330447777777777777",
    "000000004447777777777777",
    "000004444444777777777777",
    "000000444444887777777777",
    "000000044444888877777777",
    "002220044444880888777777",
    "002222224440088008877755",
    "002222222000008800855555",
    "022222220000800888050055",
    "022222200000800080055005",
    "002222000000008880005000",
    "000000000000000800000550",
};

SimulationManager::SimulationManager()
{
    map = new Map();
    superpowers = new vector<Superpower *>();
    backup = new Backup();
    designMode = false;
    isRunning = false;
}

SimulationManager::~SimulationManager()
{
    delete map;
    for (int i = 0; i < superpowers->size(); i++)
        delete superpowers->at(i);
    delete superpowers;
    delete backup;
}

void SimulationManager::runSimulation()
{
    resetSimulation();
    while (isSimulationRunning())
    {
        turnCount++;
        takeTurn();
        viewSummary();
    }
    finalMessage();
}

void SimulationManager::resetSimulation()
{
    setSuperpowers();
    setDesignMode();
    turnCount = 0;
}

void SimulationManager::setDesignMode(){};

void SimulationManager::saveState()
{
    SimulationState *state = new SimulationState(this);
    state->setMapState(map->getState());
    state->addSuperpowerState(superpowers->at(0)->getState());
    state->addSuperpowerState(superpowers->at(1)->getState());
    // state->setWarStage(warStage->clone());
    backup->addMemento(new Memento(state));
}

void SimulationManager::setSuperpowers()
{
    superpowers->push_back(new Superpower("Allies"));
    superpowers->push_back(new Superpower("Axis Powers"));

    Country *uk = new Country(/*"United Kingdom"*/);
    Country *france = new Country(/*"France"*/);
    Country *balkans = new Country(/*"Balkans"*/);
    Country *spainPortugal = new Country(/*"Spain/Portugal"*/);
    Country *sovietUnion = new Country(/*"Soviet Union"*/);
    Country *scandanavia = new Country(/*"Scandanavia"*/);

    Country *germany = new Country(/*"Germany"*/);
    Country *italy = new Country(/*"Italy"*/);

    setUpUK(uk);

    superpowers->at(0)->addCountry(uk);
    superpowers->at(0)->addCountry(france);
    superpowers->at(0)->addCountry(balkans);
    superpowers->at(0)->addCountry(spainPortugal);
    superpowers->at(0)->addCountry(sovietUnion);
    superpowers->at(0)->addCountry(scandanavia);

    superpowers->at(1)->addCountry(germany);
    superpowers->at(1)->addCountry(italy);
}

void SimulationManager::setUpUK(Country *_uk)
{
    vector<Location *> *ukLocations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '3')
            {
                ukLocations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_uk);
                if (map->getLocation(j, i)->getIsCapital())
                {
                    // _uk->setCapital(map->getLocation(j, i));
                }
            }
    // _uk->setLocations(ukLocations);

    _uk->setBorderStrength(0.75);
    _uk->setCapitalSafety(0.65);
    _uk->setDomesticMorale(0.5);
    _uk->setPoliticalStability(0.4);
    _uk->setSelfReliance(0.3);
    _uk->setWarSentiment(0.1);
    _uk->setTradeRouteSafety(0.2);
    _uk->setNumCitizens(10000000);
    // How to set military?

    delete ukLocations;//TODO Remove later
}

void SimulationManager::takeTurn(){};

void SimulationManager::viewSummary(){};

void SimulationManager::finalMessage(){};

bool SimulationManager::isSimulationRunning()
{
    return isRunning;
}