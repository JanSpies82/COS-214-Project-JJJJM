/// @author Janco Spies

#include "SimulationManager.h"
#include "Map.h"
#include "SimulationState.h"
#include "Superpower.h"
#include "Memento.h"
#include "Backup.h"
#include "StageContext.h"
#include "StageContextState.h"
#include "EarlyStage.h"
#include "MiddleStage.h"
#include "LateStage.h"
#include "Country.h"
#include "CountryState.h"
#include "MilitaryState.h"
#include "Battalion.h"
#include "Ship.h"
#include "Plane.h"
#include "Tank.h"
#include "TankFactory.h"
#include "PlaneFactory.h"
#include "ShipFactory.h"
#include "MapState.h"
#include "LocationIterator.h"
#include <string>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

const string mapVal[27] = {
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
const string countryColors[10] = {"\x1B[44m", "\x1B[40m", "\x1B[45m", "\x1B[46m", "\x1B[107m", "\x1B[106m", "\x1B[102m", "\x1B[41m", "\x1B[43m", "\x1B[105m"};
const std::string YELLOW = "\x1B[33m";
const std::string RESET = "\x1B[0m";

SimulationManager::SimulationManager()
{
    map = NULL;
    superpowers = NULL;
    backup = NULL;
    designMode = false;
    isRunning = false;
}

SimulationManager::~SimulationManager()
{
    for (int i = 0; i < superpowers->size(); i++)
        delete superpowers->at(i);
    delete superpowers;
    delete map;
    delete backup;
    delete StageContext::getInstance();
}

void SimulationManager::runSimulation()
{
    bool runAgain = true;
    while (runAgain)
    {
        resetSimulation();
        while (isSimulationRunning())
        {
            takeTurn();
            if (isSimulationRunning())
                processMenu();
        }
        finalMessage();

        cout << "Would you like to run the simulation again? (y/n)" << endl;
        string input = "";
        do
        {
            cout << "Choice: " << YELLOW;
            cin >> input;
            cout << RESET;
        } while (input != "y" && input != "n");
        runAgain = (input == "y");
    }
}

void SimulationManager::resetSimulation()
{
    if (superpowers != NULL)
    {
        for (int i = 0; i < superpowers->size(); i++)
            delete superpowers->at(i);
        delete superpowers;
    }
    if (map != NULL)
        delete map;
    if (backup != NULL)
        delete backup;

    delete StageContext::getInstance();

    system("clear");
    map = new Map();
    superpowers = new std::vector<Superpower *>();
    backup = new Backup();

    setSuperpowers();
    setDesignMode();
    turnCount = 0;
    isRunning = true;

    cout << "What would you like the maximum turn count to be? (10-100)" << endl;
    maxTurnCount = -1;
    do
    {
        cout << "Number: " << YELLOW;
        cin >> maxTurnCount;
        cout << RESET;
        if (!cin.good())
        {
            maxTurnCount = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (maxTurnCount < 10 || maxTurnCount > 100);
    StageContext::getInstance()->setSimulationLength(maxTurnCount);
    cout << "Simulation is ready to start!" << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

void SimulationManager::setDesignMode()
{
    cout << "Would you like to run the simulation in design mode?(y/n)" << endl;
    string input = "";
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> input;
        cout << RESET;
    } while (input != "y" && input != "n");
    designMode = (input == "y");
};

void SimulationManager::saveState()
{
    SimulationState *state = new SimulationState();
    state->setMapState(map->getState());
    state->addSuperpowerState(superpowers->at(0)->getState());
    state->addSuperpowerState(superpowers->at(1)->getState());
    state->setStageContextState(StageContext::getInstance()->getState());
    backup->addMemento(new Memento(state));
}

bool SimulationManager::restoreState()
{
    if (backup->getMementoCount() == 0)
    {
        cout << "No states to restore!" << endl;
        return false;
    }

    Memento *m = backup->getMemento();
    SimulationState *state = m->getState();
    StageContext::getInstance()->setState(state->getStageContextState());
    turnCount = StageContext::getInstance()->getCurrentRound();
    cout << "Restoring state at turn " << turnCount << endl;
    for (int i = 0; i < superpowers->size(); i++)
        delete superpowers->at(i);
    delete superpowers;
    delete map;
    map = state->getMapState()->clone();
    superpowers = new vector<Superpower *>();
    for (int i = 0; i < state->getSuperpowerStateCount(); i++)
        superpowers->push_back(new Superpower(state->getSuperpowerState(i)));

    for (int i = 0; i < superpowers->size(); i++)
    {
        superpowers->at(i)->resetLocations(map);
    }

    for (int i = 0; i < superpowers->size(); i++)
    {
        superpowers->at(i)->resetEnemies(superpowers->at((1 + i) % 2)->getAllCountries());
    }

    delete m;

    return true;
};

void SimulationManager::setSuperpowers()
{
    superpowers->push_back(new Superpower("Axis Powers"));
    superpowers->push_back(new Superpower("Allies"));

    Country *uk = new Country("United Kingdom");
    Country *france = new Country("France");
    Country *balkans = new Country("Balkans");
    Country *spainPortugal = new Country("Spain/Portugal");
    Country *sovietUnion = new Country("Soviet Union");
    Country *scandanavia = new Country("Scandanavia");
    Country *germany = new Country("Germany");
    Country *italy = new Country("Italy");

    superpowers->at(0)->addCountry(germany);
    superpowers->at(0)->addCountry(italy);

    superpowers->at(1)->addCountry(uk);
    superpowers->at(1)->addCountry(france);
    superpowers->at(1)->addCountry(balkans);
    superpowers->at(1)->addCountry(spainPortugal);
    superpowers->at(1)->addCountry(sovietUnion);
    superpowers->at(1)->addCountry(scandanavia);

    setUpUK(uk);
    setUpFrance(france);
    setUpBalkans(balkans);
    setUpSpainPortugal(spainPortugal);
    setUpSovietUnion(sovietUnion);
    setUpScandanavia(scandanavia);
    setUpGermany(germany);
    setUpItaly(italy);
}

void SimulationManager::setUpUK(Country *_uk)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '3')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_uk);
                if (map->getLocation(j, i)->getIsCapital())
                    _uk->setCapital(map->getLocation(j, i));
            }
    _uk->setColor(countryColors[3]);
    _uk->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _uk->setEnemies(enemies);
    _uk->setBorderStrength(0.32);
    _uk->setCapitalSafety(0.5);
    _uk->setDomesticMorale(0.5);
    _uk->setPoliticalStability(0.4);
    _uk->setSelfReliance(0.3);
    _uk->setWarSentiment(0.1);
    _uk->setTradeRouteSafety(0.2);
    _uk->setNumCitizens(545463825);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 2; i++)
        battalions->push_back(new Battalion(1));
    _uk->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 5; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _uk->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 15; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _uk->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 20; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _uk->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpFrance(Country *_france)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '4')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_france);
                if (map->getLocation(j, i)->getIsCapital())
                    _france->setCapital(map->getLocation(j, i));
            }
    _france->setColor(countryColors[4]);
    _france->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _france->setEnemies(enemies);
    _france->setBorderStrength(0.25);
    _france->setCapitalSafety(0.4);
    _france->setDomesticMorale(0.3);
    _france->setPoliticalStability(0.3);
    _france->setSelfReliance(0.5);
    _france->setWarSentiment(0.1);
    _france->setTradeRouteSafety(0.3);
    _france->setNumCitizens(111524472);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 3; i++)
        battalions->push_back(new Battalion(1));
    _france->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 8; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _france->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 5; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _france->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 5; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _france->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpBalkans(Country *_balkans)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '5')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_balkans);
                if (map->getLocation(j, i)->getIsCapital())
                    _balkans->setCapital(map->getLocation(j, i));
            }
    _balkans->setColor(countryColors[5]);
    _balkans->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _balkans->setEnemies(enemies);
    _balkans->setBorderStrength(0.45);
    _balkans->setCapitalSafety(0.4);
    _balkans->setDomesticMorale(0.25);
    _balkans->setPoliticalStability(0.3);
    _balkans->setSelfReliance(0.33);
    _balkans->setWarSentiment(0.4);
    _balkans->setTradeRouteSafety(0.3);
    _balkans->setNumCitizens(37000000);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 1; i++)
        battalions->push_back(new Battalion(1));
    _balkans->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 2; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _balkans->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 2; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _balkans->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 2; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _balkans->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpSpainPortugal(Country *_spainPortugal)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '2')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_spainPortugal);
                if (map->getLocation(j, i)->getIsCapital())
                    _spainPortugal->setCapital(map->getLocation(j, i));
            }
    _spainPortugal->setColor(countryColors[2]);
    _spainPortugal->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _spainPortugal->setEnemies(enemies);
    _spainPortugal->setBorderStrength(0.5);
    _spainPortugal->setCapitalSafety(0.4);
    _spainPortugal->setDomesticMorale(0.25);
    _spainPortugal->setPoliticalStability(0.33);
    _spainPortugal->setSelfReliance(0.4);
    _spainPortugal->setWarSentiment(0.5);
    _spainPortugal->setTradeRouteSafety(0.32);
    _spainPortugal->setNumCitizens(45418200);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 4; i++)
        battalions->push_back(new Battalion(1));
    _spainPortugal->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 4; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _spainPortugal->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 5; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _spainPortugal->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 5; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _spainPortugal->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpSovietUnion(Country *_sovietUnion)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '6')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_sovietUnion);
                if (map->getLocation(j, i)->getIsCapital())
                    _sovietUnion->setCapital(map->getLocation(j, i));
            }
    _sovietUnion->setColor(countryColors[6]);
    _sovietUnion->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _sovietUnion->setEnemies(enemies);
    _sovietUnion->setBorderStrength(0.5);
    _sovietUnion->setCapitalSafety(0.6);
    _sovietUnion->setDomesticMorale(0.2);
    _sovietUnion->setPoliticalStability(0.1);
    _sovietUnion->setSelfReliance(0.3);
    _sovietUnion->setWarSentiment(0.25);
    _sovietUnion->setTradeRouteSafety(0.2);
    _sovietUnion->setNumCitizens(168524000);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 5; i++)
        battalions->push_back(new Battalion(1));
    _sovietUnion->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 6; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _sovietUnion->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 0; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _sovietUnion->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 2; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _sovietUnion->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpScandanavia(Country *_scandanavia)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '9')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_scandanavia);
                if (map->getLocation(j, i)->getIsCapital())
                    _scandanavia->setCapital(map->getLocation(j, i));
            }
    _scandanavia->setColor(countryColors[9]);
    _scandanavia->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(0)->getCountry(i));

    _scandanavia->setEnemies(enemies);
    _scandanavia->setBorderStrength(0.3);
    _scandanavia->setCapitalSafety(0.4);
    _scandanavia->setDomesticMorale(0.5);
    _scandanavia->setPoliticalStability(0.5);
    _scandanavia->setSelfReliance(0.25);
    _scandanavia->setWarSentiment(0.34);
    _scandanavia->setTradeRouteSafety(0.4);
    _scandanavia->setNumCitizens(16945200);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 1; i++)
        battalions->push_back(new Battalion(1));
    _scandanavia->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 2; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _scandanavia->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 3; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _scandanavia->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 2; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _scandanavia->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpGermany(Country *_germany)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '7')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_germany);
                if (map->getLocation(j, i)->getIsCapital())
                    _germany->setCapital(map->getLocation(j, i));
            }
    _germany->setColor(countryColors[7]);
    _germany->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(1)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(1)->getCountry(i));

    _germany->setEnemies(enemies);
    _germany->setBorderStrength(0.6);
    _germany->setCapitalSafety(0.85);
    _germany->setDomesticMorale(0.9);
    _germany->setPoliticalStability(0.85);
    _germany->setSelfReliance(0.85);
    _germany->setWarSentiment(0.9);
    _germany->setTradeRouteSafety(0.75);
    _germany->setNumCitizens(222461581);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 20; i++)
        battalions->push_back(new Battalion(1));
    _germany->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 15; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _germany->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 15; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _germany->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 25; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _germany->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::setUpItaly(Country *_italy)
{
    vector<Location *> *locations = new vector<Location *>();
    for (int i = 0; i < 27; i++)
        for (int j = 0; j < 25; j++)
            if (mapVal[i][j] == '8')
            {
                locations->push_back(map->getLocation(j, i));
                map->getLocation(j, i)->setOwnedBy(_italy);
                if (map->getLocation(j, i)->getIsCapital())
                    _italy->setCapital(map->getLocation(j, i));
            }
    _italy->setColor(countryColors[8]);
    _italy->setLocations(locations);

    vector<Country *> *enemies = new vector<Country *>();
    for (int i = 0; i < superpowers->at(1)->getCountryCount(); i++)
        enemies->push_back(superpowers->at(1)->getCountry(i));

    _italy->setEnemies(enemies);
    _italy->setBorderStrength(0.5);
    _italy->setCapitalSafety(0.4);
    _italy->setDomesticMorale(0.5);
    _italy->setPoliticalStability(0.6);
    _italy->setSelfReliance(0.4);
    _italy->setWarSentiment(0.5);
    _italy->setTradeRouteSafety(0.5);
    _italy->setNumCitizens(73086517);

    vector<VehicleFactory *> *vFactories = new vector<VehicleFactory *>();
    vFactories->push_back(new TankFactory());
    vFactories->push_back(new ShipFactory());
    vFactories->push_back(new PlaneFactory());

    vector<Battalion *> *battalions = new vector<Battalion *>();
    for (int i = 0; i < 10; i++)
        battalions->push_back(new Battalion(1));
    _italy->getState()->getMilitaryState()->setBattalions(battalions);

    vector<Tank *> *tanks = new vector<Tank *>();
    for (int i = 0; i < 7; i++)
        tanks->push_back(((Tank *)(vFactories->at(0)->manufactureVehicle())));
    _italy->getState()->getMilitaryState()->setTanks(tanks);

    vector<Ship *> *ships = new vector<Ship *>();
    for (int i = 0; i < 8; i++)
        ships->push_back(((Ship *)vFactories->at(1)->manufactureVehicle()));
    _italy->getState()->getMilitaryState()->setShips(ships);

    vector<Plane *> *planes = new vector<Plane *>();
    for (int i = 0; i < 10; i++)
        planes->push_back(((Plane *)vFactories->at(2)->manufactureVehicle()));
    _italy->getState()->getMilitaryState()->setPlanes(planes);

    for (int i = 0; i < vFactories->size(); i++)
        delete vFactories->at(i);
    delete vFactories;
}

void SimulationManager::takeTurn()
{
    bool *countryIsDead = new bool[2];
    countryIsDead[0] = false;
    countryIsDead[1] = false;
    system("clear");
    saveState();
    turnCount++;
    StageContext::getInstance()->incrementRound();
    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
    {
        countryIsDead[0] = false;
        countryIsDead[1] = false;
        Country *countryB = superpowers->at(0)->getCountry(i)->takeTurn(countryIsDead);
        if (countryIsDead[0])
        {
            Country *c = superpowers->at(0)->getCountry(i);
            superpowers->at(0)->removeCountry(c);
            delete c;
        }
        else if (countryIsDead[1])
        {
            superpowers->at(1)->removeCountry(countryB);
            delete countryB;
        }
    }

    for (int i = 0; i < superpowers->at(1)->getCountryCount(); i++)
    {
        countryIsDead[0] = false;
        countryIsDead[1] = false;

        Country *countryB = superpowers->at(1)->getCountry(i)->takeTurn(countryIsDead);
        if (countryIsDead[0])
        {
            Country *c = superpowers->at(1)->getCountry(i);
            superpowers->at(1)->removeCountry(c);
            delete c;
        }
        else if (countryIsDead[1])
        {
            superpowers->at(0)->removeCountry(countryB);
            delete countryB;
        }
    }
    delete[] countryIsDead;
};

void SimulationManager::viewSummary()
{
    cout << "Results after turn " << turnCount << endl;
    map->printMap();

    for (int i = 0; i < superpowers->size(); i++)
        superpowers->at(i)->printSummary();

    isRunning = ((superpowers->at(0)->getCountryCount() > 0 && superpowers->at(1)->getCountryCount() > 0) && turnCount <= maxTurnCount);
};

void SimulationManager::processMenu()
{
    while (true)
    {
        viewSummary();
        cout << "What would you like to do next?" << endl;
        cout << "[1] Continue simulation" << endl;
        cout << "[2] Restore a previous state" << endl;
        cout << "[3] View a detailed summary of a country" << endl;
        if (designMode)
            cout << "[4] Change the simulation state" << endl;
        cout << "[9] Exit simulation" << endl;

        int choice = -1;
        do
        {
            cout << "Choice: " << YELLOW;
            cin >> choice;
            cout << RESET;
            if (!cin.good())
            {
                choice = -1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice < 1 || (choice > 4 && choice != 9) || (choice == 4 && !designMode));

        switch (choice)
        {
        case 1:
            return;
            break;
        case 2:
            if (restoreState())
                cout << "State restored successfully!" << endl;
            else
                cout << "State restoration failed!" << endl;
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 3:
            viewCountrySummary();
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 4:
            designModeAction();
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 9:
            isRunning = false;
            return;
            break;
        default:
            break;
        }
        system("clear");
    }
}

void SimulationManager::finalMessage()
{
    cout << endl
         << "Simulation ended after " << turnCount << " turns." << endl;
    if (superpowers->at(0)->getCountryCount() > 0 && superpowers->at(1)->getCountryCount() >= 3)
        cout << "The simulation ended in a stalemate." << endl;
    else if (superpowers->at(0)->getCountryCount() == 0)
        cout << "The simulation ended with the " << superpowers->at(1)->getName() << " winning." << endl;
    else
        cout << "The simulation ended with the " << superpowers->at(0)->getName() << " winning." << endl;
};

void SimulationManager::viewCountrySummary()
{
    vector<Country *> *countries = new vector<Country *>();
    for (int i = 0; i < superpowers->size(); i++)
        for (int j = 0; j < superpowers->at(i)->getCountryCount(); j++)
            countries->push_back(superpowers->at(i)->getCountry(j));

    cout << "Choose a country you would like to view a summary of:" << endl;
    int i;
    for (i = 0; i < countries->size(); i++)
        cout << "[" << i + 1 << "] " << countries->at(i)->getName() << endl;
    cout << "[" << i + 1 << "] Cancel" << endl;
    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > countries->size() + 1);

    if (choice == countries->size() + 1)
    {
        cout << "Action cancelled." << endl;
        delete countries;
        return;
    }

    countries->at(choice - 1)->printSummary();
    delete countries;
};

void SimulationManager::designModeAction()
{
    cout << "Select an action to perform:" << endl;
    cout << "[1] Change the simulation length" << endl;
    cout << "[2] Remove a country" << endl;
    cout << "[3] Alter the state of a country" << endl;
    cout << "[4] Change the current war stage" << endl;
    cout << "[9] Cancel" << endl;

    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || (choice > 4 && choice != 9));

    if (choice == 9)
    {
        cout << "Action cancelled." << endl;
        return;
    }

    saveState();

    switch (choice)
    {
    case 1:
        changeSimulationLength();
        break;
    case 2:
        removeCountry();
        break;
    case 3:
        alterCountryState();
        break;
    case 4:
        changeWarStage();
        break;
    default:
        break;
    }
};

void SimulationManager::changeSimulationLength()
{
    do
    {
        cout << "Enter the new simulation length (" << ((turnCount > 4) ? turnCount : 4) << "-100): " << YELLOW;
        cin >> maxTurnCount;
        cout << RESET;
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            return;
        }
    } while (maxTurnCount < 4 || maxTurnCount > 100 || maxTurnCount < turnCount);
    cout << "Simulation length changed to " << maxTurnCount << " turns." << endl;
};

void SimulationManager::removeCountry()
{
    vector<Country *> *countries = new vector<Country *>();
    for (int i = 0; i < superpowers->size(); i++)
        for (int j = 0; j < superpowers->at(i)->getCountryCount(); j++)
            countries->push_back(superpowers->at(i)->getCountry(j));

    cout << "Choose a country you would like to remove:" << endl;
    int i;
    for (i = 0; i < countries->size(); i++)
        cout << "[" << i + 1 << "] " << countries->at(i)->getName() << endl;
    cout << "[" << i + 1 << "] Cancel" << endl;
    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > countries->size() + 1);

    if (choice == countries->size() + 1)
    {
        cout << "Action cancelled." << endl;
        delete countries;
        return;
    }
    try
    {
        int index;
        if (choice <= superpowers->at(0)->getCountryCount())
            index = 0;
        else
            index = 1;

        superpowers->at(index)->removeCountry(countries->at(choice - 1));
        cout << countries->at(choice - 1)->getName() << " removed." << endl;
        delete countries->at(choice - 1);
    }
    catch (exception &e)
    {
        cout << "Error removing country" << endl;
    }
    delete countries;
};

void SimulationManager::alterCountryState()
{
    vector<Country *> *countries = new vector<Country *>();
    for (int i = 0; i < superpowers->size(); i++)
        for (int j = 0; j < superpowers->at(i)->getCountryCount(); j++)
            countries->push_back(superpowers->at(i)->getCountry(j));

    cout << "Choose a country you would like to alter:" << endl;
    int i;
    for (i = 0; i < countries->size(); i++)
        cout << "[" << i + 1 << "] " << countries->at(i)->getName() << endl;
    cout << "[" << i + 1 << "] Cancel" << endl;
    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > countries->size() + 1);

    if (choice == countries->size() + 1)
    {
        cout << "Action cancelled." << endl;
        delete countries;
        return;
    }

    cout << "Select which of the following you would like to change:" << endl;
    cout << "[1] Border strength (currently " << countries->at(choice - 1)->getBorderStrength() << ")" << endl;
    cout << "[2] Population (currently " << countries->at(choice - 1)->getNumCitizens() << ")" << endl;
    cout << "[4] Political stability (currently " << countries->at(choice - 1)->getPoliticalStability() << ")" << endl;
    cout << "[5] Self relience (currently " << countries->at(choice - 1)->getSelfReliance() << ")" << endl;
    cout << "[6] War sentiment (currently " << countries->at(choice - 1)->getWarSentiment() << ")" << endl;
    cout << "[7] Trade route safety (currently " << countries->at(choice - 1)->getTradeRouteSafety() << ")" << endl;
    cout << "[8] Military attributes " << endl;
    cout << "[9] Cancel" << endl;

    int choice2 = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice2;
        cout << RESET;
        if (!cin.good())
        {
            choice2 = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice2 < 1 || choice2 > 9);

    if (choice2 == 9)
    {
        cout << "Action cancelled." << endl;
        delete countries;
        return;
    }

    switch (choice2)
    {
    case 1:
        changeBorderStrength(countries->at(choice - 1));
        break;
    case 2:
        changePopulation(countries->at(choice - 1));
        break;
    case 4:
        changePoliticalStability(countries->at(choice - 1));
        break;
    case 5:
        changeSelfReliance(countries->at(choice - 1));
        break;
    case 6:
        changeWarSentiment(countries->at(choice - 1));
        break;
    case 7:
        changeTradeRouteSafety(countries->at(choice - 1));
        break;
    case 8:
        changeMilitaryAttributes(countries->at(choice - 1));
        break;
    default:
        break;
    }
    delete countries;
}

void SimulationManager::changeWarStage()
{
    cout << "Select the new war stage: " << endl;
    cout << "[1] Early stage" << endl;
    cout << "[2] Middle stage" << endl;
    cout << "[3] Late stage" << endl;
    cout << "[9] Cancel" << endl;

    int choice = -1;
    do
    {
        cout << "Choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || (choice > 3 && choice != 9));

    if (choice == 9)
    {
        cout << "Action cancelled." << endl;
        return;
    }

    saveState();

    StageContext::getInstance()->moveToStage(choice - 1);

    string stageName;

    switch (choice)
    {
    case 1:
        stageName = "Early";
        break;
    case 2:
        stageName = "Middle";
        break;
    case 3:
        stageName = "Late";
        break;
    default:
        break;
    }
    cout << "War stage changed to " << stageName << " Stage." << endl;
}

void SimulationManager::changeBorderStrength(Country *_country)
{
    double borderStrength = -1;
    do
    {
        cout << "Enter the new border strength (0-1): " << YELLOW;
        cin >> borderStrength;
        cout << RESET;
        if (!cin.good())
        {
            borderStrength = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (borderStrength < 0 || borderStrength > 1);
    _country->setBorderStrength(borderStrength);
    cout << "Border strength changed to " << borderStrength << "." << endl;
}

void SimulationManager::changePopulation(Country *_country)
{
    int population = -1;
    do
    {
        cout << "Enter the new population (0-1 000 000 000): " << YELLOW;
        cin >> population;
        cout << RESET;
        if (!cin.good())
        {
            population = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (population < 0 || population > 1000000000);
    _country->setNumCitizens(population);
    cout << "Population changed to " << population << "." << endl;
}

void SimulationManager::changePoliticalStability(Country *_country)
{
    double politicalStability = -1;
    do
    {
        cout << "Enter the new political stability (0-1): " << YELLOW;
        cin >> politicalStability;
        cout << RESET;
        if (!cin.good())
        {
            politicalStability = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (politicalStability < 0 || politicalStability > 1);
    _country->setPoliticalStability(politicalStability);
    cout << "Political stability changed to " << politicalStability << "." << endl;
}

void SimulationManager::changeSelfReliance(Country *_country)
{
    double selfReliance = -1;
    do
    {
        cout << "Enter the new self reliance (0-1): " << YELLOW;
        cin >> selfReliance;
        cout << RESET;
        if (!cin.good())
        {
            selfReliance = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (selfReliance < 0 || selfReliance > 1);
    _country->setSelfReliance(selfReliance);
    cout << "Self reliance changed to " << selfReliance << "." << endl;
}

void SimulationManager::changeWarSentiment(Country *_country)
{
    double warSentiment = -1;
    do
    {
        cout << "Enter the new war sentiment (0-1): " << YELLOW;
        cin >> warSentiment;
        cout << RESET;
        if (!cin.good())
        {
            warSentiment = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (warSentiment < 0 || warSentiment > 1);
    _country->setWarSentiment(warSentiment);
    cout << "War sentiment changed to " << warSentiment << "." << endl;
}

void SimulationManager::changeTradeRouteSafety(Country *_country)
{
    double tradeRouteSafety = -1;
    do
    {
        cout << "Enter the new trade route safety (0-1): " << YELLOW;
        cin >> tradeRouteSafety;
        cout << RESET;
        if (!cin.good())
        {
            tradeRouteSafety = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (tradeRouteSafety < 0 || tradeRouteSafety > 1);
    _country->setTradeRouteSafety(tradeRouteSafety);
    cout << "Trade route safety changed to " << tradeRouteSafety << "." << endl;
}

void SimulationManager::changeMilitaryAttributes(Country *_country)
{
    cout << "Select which action to perform: " << endl;
    cout << "[1] Add Tanks (current: " << _country->getMilitaryState()->getNumTanks() << ")" << endl;
    cout << "[2] Remove Tanks (current: " << _country->getMilitaryState()->getNumTanks() << ")" << endl;
    cout << "[3] Add Planes (current: " << _country->getMilitaryState()->getNumPlanes() << ")" << endl;
    cout << "[4] Remove Planes (current: " << _country->getMilitaryState()->getNumPlanes() << ")" << endl;
    cout << "[5] Add Troops (current: " << _country->getMilitaryState()->getNumTroops() << ")" << endl;
    cout << "[6] Remove Troops (current: " << _country->getMilitaryState()->getNumTroops() << ")" << endl;
    cout << "[7] Add Ships (current: " << _country->getMilitaryState()->getNumShips() << ")" << endl;
    cout << "[8] Remove Ships (current: " << _country->getMilitaryState()->getNumShips() << ")" << endl;
    cout << "[9] Add Battalions (current: " << _country->getMilitaryState()->getNumBattalions() << ")" << endl;
    cout << "[10] Remove Battalions (current: " << _country->getMilitaryState()->getNumBattalions() << ")" << endl;
    cout << "[11] Cancel" << endl;

    int choice = -1;
    do
    {
        cout << "Enter your choice: " << YELLOW;
        cin >> choice;
        cout << RESET;
        if (!cin.good())
        {
            choice = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice < 1 || choice > 11);

    int max = 100;
    switch (choice)
    {
    case 1:
        cout << "Enter the number of tanks to add (0-100)" << endl;
        break;
    case 2:
        cout << "Enter the number of tanks to remove (0-" << _country->getMilitaryState()->getNumTanks() << ")" << endl;
        max = _country->getMilitaryState()->getNumTanks();
        break;
    case 3:
        cout << "Enter the number of planes to add (0-100)" << endl;
        break;
    case 4:
        cout << "Enter the number of planes to remove (0-" << _country->getMilitaryState()->getNumPlanes() << ")" << endl;
        max = _country->getMilitaryState()->getNumPlanes();
        break;
    case 5:
        cout << "Enter the number of troops to add (0-1000000)" << endl;
        max = 1000000;
        break;
    case 6:
        cout << "Enter the number of troops to remove (0-" << _country->getMilitaryState()->getNumTroops() << ")" << endl;
        max = _country->getMilitaryState()->getNumTroops();
        break;
    case 7:
        cout << "Enter the number of ships to add (0-100)" << endl;
        break;
    case 8:
        cout << "Enter the number of ships to remove (0-" << _country->getMilitaryState()->getNumShips() << endl;
        max = _country->getMilitaryState()->getNumShips();
        break;
    case 9:
        cout << "Enter the number of battalions to add (0-100)" << endl;
        break;
    case 10:
        cout << "Enter the number of battalions to remove (0-" << _country->getMilitaryState()->getNumBattalions() << endl;
        max = _country->getMilitaryState()->getNumBattalions();
        break;
    case 11:
        cout << "Action cancelled." << endl;
        return;
    }

    int num = -1;
    do
    {
        cout << "Number: " << YELLOW;
        cin >> num;
        cout << RESET;
        if (!cin.good())
        {
            num = -1;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (num < 0 || num > max);

    switch (choice)
    {
    case 1:
        _country->getMilitaryState()->updateNumTanks(num, true);
        break;
    case 2:
        _country->getMilitaryState()->updateNumTanks(num, false);
        break;
    case 3:
        _country->getMilitaryState()->updateNumPlanes(num, true);
        break;
    case 4:
        _country->getMilitaryState()->updateNumPlanes(num, false);
        break;
    case 5:
        _country->getMilitaryState()->updateNumTroops(num, true);
        break;
    case 6:
        _country->getMilitaryState()->updateNumTroops(num, false);
        break;
    case 7:
        _country->getMilitaryState()->updateNumShips(num, true);
        break;
    case 8:
        _country->getMilitaryState()->updateNumShips(num, false);
        break;
    case 9:
        _country->getMilitaryState()->updateNumBattalions(num, true);
        break;
    case 10:
        _country->getMilitaryState()->updateNumBattalions(num, false);
        break;
    case 11:
        cout << "Action cancelled." << endl;
        return;
    }
    cout << "Change successful." << endl;
}

bool SimulationManager::isSimulationRunning()
{
    return isRunning;
}