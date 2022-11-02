/// @author Janco Spies

#include "SimulationManager.h"
#include "Map.h"
#include "SimulationState.h"
#include "Superpower.h"
#include "Memento.h"
#include "Backup.h"
#include "WarStage.h"
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

const std::string RED = "\x1B[31m";
const std::string GREEN = "\x1B[32m";
const std::string YELLOW = "\x1B[33m";
const std::string BLUE = "\x1B[34m";
const std::string CYAN = "\x1B[36m";
const std::string RESET = "\x1B[0m";

SimulationManager::SimulationManager()
{
    map = NULL;
    superpowers = NULL;
    backup = NULL;
    warStage = NULL;
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
    // delete warStage;
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
            viewSummary();
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
    if (map != NULL)
        delete map;
    if (superpowers != NULL)
    {
        for (int i = 0; i < superpowers->size(); i++)
            delete superpowers->at(i);
        delete superpowers;
    }
    if (backup != NULL)
        delete backup;
    if (warStage != NULL)
        delete warStage;

    system("clear");
    map = new Map();
    superpowers = new std::vector<Superpower *>();
    backup = new Backup();
    // warStage = new WarStage(); //Maybe not necessary since takeTurn will already handle this?

    setSuperpowers();
    setDesignMode();
    turnCount = 0;
    isRunning = true;

    cout << "What would you like the maximum turn count to be? (4-100)" << endl;
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
    } while (maxTurnCount < 4 || maxTurnCount > 100);
    cout << "Simulation is ready to start!" << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

void SimulationManager::setDesignMode()
{
    cout << "Would you like to run the simulation in design mode?(y/n)" << endl;
    string input = "";
    cout << "Choice: " << YELLOW;
    cin >> input;
    cout << RESET;
    designMode = (input == "y" || input == "Y");
};

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

    setUpUK(uk);
    setUpFrance(france);
    setUpBalkans(balkans);
    setUpSpainPortugal(spainPortugal);
    setUpSovietUnion(sovietUnion);
    setUpScandanavia(scandanavia);
    setUpGermany(germany);
    setUpItaly(italy);

    superpowers->at(0)->addCountry(germany);
    superpowers->at(0)->addCountry(italy);

    superpowers->at(1)->addCountry(uk);
    superpowers->at(1)->addCountry(france);
    superpowers->at(1)->addCountry(balkans);
    superpowers->at(1)->addCountry(spainPortugal);
    superpowers->at(1)->addCountry(sovietUnion);
    superpowers->at(1)->addCountry(scandanavia);
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

    _uk->setBorderStrength(0.75);
    _uk->setCapitalSafety(0.65);
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

    _balkans->setBorderStrength(0.45);
    _balkans->setCapitalSafety(0.4);
    _balkans->setDomesticMorale(0.6);
    _balkans->setPoliticalStability(0.3);
    _balkans->setSelfReliance(0.6);
    _balkans->setWarSentiment(0.4);
    _balkans->setTradeRouteSafety(0.3);
    _balkans->setNumCitizens(17000000); // Educated guess

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

    _spainPortugal->setBorderStrength(0.7);
    _spainPortugal->setCapitalSafety(0.7);
    _spainPortugal->setDomesticMorale(0.8);
    _spainPortugal->setPoliticalStability(0.6);
    _spainPortugal->setSelfReliance(0.7);
    _spainPortugal->setWarSentiment(0.6);
    _spainPortugal->setTradeRouteSafety(0.5);
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

    _sovietUnion->setBorderStrength(0.9);
    _sovietUnion->setCapitalSafety(0.9);
    _sovietUnion->setDomesticMorale(0.5);
    _sovietUnion->setPoliticalStability(0.4);
    _sovietUnion->setSelfReliance(0.8);
    _sovietUnion->setWarSentiment(0.5);
    _sovietUnion->setTradeRouteSafety(0.5);
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

    _scandanavia->setBorderStrength(0.75);
    _scandanavia->setCapitalSafety(0.9);
    _scandanavia->setDomesticMorale(0.6);
    _scandanavia->setPoliticalStability(0.7);
    _scandanavia->setSelfReliance(0.7);
    _scandanavia->setWarSentiment(0.5);
    _scandanavia->setTradeRouteSafety(0.5);
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

    _italy->setBorderStrength(0.5);
    _italy->setCapitalSafety(0.6);
    _italy->setDomesticMorale(0.65);
    _italy->setPoliticalStability(0.65);
    _italy->setSelfReliance(0.7);
    _italy->setWarSentiment(0.9);
    _italy->setTradeRouteSafety(0.7);
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
    system("clear");
    saveState();

    turnCount++;
    if (turnCount <= floor(maxTurnCount * 0.3))
    {
        // Move to Early Stage
    }
    else if (turnCount <= ceil(maxTurnCount * 0.6))
    {
        // Move to Middle Stage
    }
    else
    {
        // Move to Late Stage
    }

    for (int i = 0; i < superpowers->at(0)->getCountryCount(); i++)
        superpowers->at(0)->getCountry(i)->takeTurn(NULL); // TODO check whether input parameter should be removed

    for (int i = 0; i < superpowers->at(1)->getCountryCount(); i++)
        superpowers->at(1)->getCountry(i)->takeTurn(NULL); // TODO check whether input parameter should be removed
};

void SimulationManager::viewSummary()
{
    cout << "Results after turn " << turnCount << endl;
    map->printMap();

    for (int i = 0; i < superpowers->size(); i++)
        superpowers->at(i)->printSummary();

    isRunning = ((superpowers->at(0)->getCountryCount() > 0 && superpowers->at(1)->getCountryCount() > 0) && turnCount <= maxTurnCount);
    // cout << "Press enter to continue..." << endl;
    // cin.ignore();
    // cin.get();
};

void SimulationManager::processMenu()
{
    while (true)
    {
        cout << "What would you like to do next?" << endl;
        cout << "[1] Continue simulation" << endl;
        cout << "[2] Restore a previous state" << endl;
        cout << "[3] View a detailed summary of a country" << endl;
        cout << "[4] View the map" << endl;
        cout << "[5] View the summary of the system again" << endl;
        if (designMode)
            cout << "[6] Change the simulation state" << endl;
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
        } while (choice < 1 || (choice > 6 && choice != 9) || (choice == 6 && !designMode));

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
            map->printMap();
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 5:
            viewSummary();
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 6:
            designModeAction();
            cout << "Press enter to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        case 9:
            isRunning = false;
            return;
            break;
        }
        system("clear");
    }
}

void SimulationManager::finalMessage()
{
    cout << endl
         << "Simulation ended after " << turnCount << " turns." << endl;
    if (superpowers->at(0)->getCountryCount() > 0 && superpowers->at(1)->getCountryCount() > 0)
        cout << "The simulation ended in a stalemate." << endl;
    else if (superpowers->at(0)->getCountryCount() > 0)
        cout << "The simulation ended with the " << superpowers->at(0)->getName() << " winning." << endl;
    else
        cout << "The simulation ended with the " << superpowers->at(1)->getName() << " winning." << endl;
};

void SimulationManager::viewCountrySummary(){};

void SimulationManager::designModeAction(){};

bool SimulationManager::restoreState(){};

bool SimulationManager::isSimulationRunning()
{
    return isRunning;
}