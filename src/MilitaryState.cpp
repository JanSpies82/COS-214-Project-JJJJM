/// @author Jacob Mahloko

#include "Military.h"
#include "MilitaryState.h"
#include "Ship.h"
#include "Plane.h"
#include "Tank.h"
#include "Battalion.h"
#include "VehicleFactory.h"
#include "TankFactory.h"
#include "ShipFactory.h"
#include "PlaneFactory.h"
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////
// MilitaryState()
///////////////////////////////////////////////////////////

MilitaryState::MilitaryState()
{
  ships = new vector<Ship *>();
  planes = new vector<Plane *>();
  tanks = new vector<Tank *>();
  battalions = new vector<Battalion *>();
  vehicleFactories = new vector<VehicleFactory *>();
  vehicleFactories->push_back(new ShipFactory());
  vehicleFactories->push_back(new PlaneFactory());
  vehicleFactories->push_back(new TankFactory());
  numTroops = 0;
}

///////////////////////////////////////////////////////////
// ~MilitaryState()
///////////////////////////////////////////////////////////

MilitaryState::~MilitaryState()
{

  for (int i = 0; i < ships->size(); i++)
    delete ships->at(i);

  delete ships;

  for (int i = 0; i < planes->size(); i++)
    delete planes->at(i);

  delete planes;

  for (int i = 0; i < tanks->size(); i++)
    delete tanks->at(i);

  delete tanks;

  for (int i = 0; i < battalions->size(); i++)
    delete battalions->at(i);

  delete battalions;

  for (int i = 0; i < vehicleFactories->size(); i++)
    delete vehicleFactories->at(i);

  delete vehicleFactories;
}

///////////////////////////////////////////////////////////
// setShips()
///////////////////////////////////////////////////////////

void MilitaryState::setShips(std::vector<Ship *> *_ships)
{
  for (int i = 0; i < ships->size(); i++)
    delete ships->at(i);
  delete ships;
  ships = _ships;
}

///////////////////////////////////////////////////////////
// setPlanes()
///////////////////////////////////////////////////////////

void MilitaryState::setPlanes(std::vector<Plane *> *_planes)
{
  for (int i = 0; i < planes->size(); i++)
    delete planes->at(i);
  delete planes;
  planes = _planes;
}

///////////////////////////////////////////////////////////
// setTanks()
///////////////////////////////////////////////////////////

void MilitaryState::setTanks(std::vector<Tank *> *_tanks)
{
  for (int i = 0; i < tanks->size(); i++)
    delete tanks->at(i);
  delete tanks;
  tanks = _tanks;
}

///////////////////////////////////////////////////////////
// setBattalions()
///////////////////////////////////////////////////////////

void MilitaryState::setBattalions(std::vector<Battalion *> *_battalions)
{
  for (int i = 0; i < battalions->size(); i++)
    delete battalions->at(i);
  delete battalions;
  battalions = _battalions;
}

///////////////////////////////////////////////////////////
// setTroops()
///////////////////////////////////////////////////////////

void MilitaryState::setTroops(int _troops)
{
  numTroops = _troops;
}

///////////////////////////////////////////////////////////
// setVehicleFactories()
///////////////////////////////////////////////////////////

void MilitaryState::setVehicleFactories(std::vector<VehicleFactory *> *_vehicleFactories)
{
  for (int i = 0; i < vehicleFactories->size(); i++)
    delete vehicleFactories->at(i);
  delete vehicleFactories;
  vehicleFactories = _vehicleFactories;
}

///////////////////////////////////////////////////////////
// getNumTroops()
///////////////////////////////////////////////////////////

int MilitaryState::getNumTroops()
{
  return numTroops;
}

///////////////////////////////////////////////////////////
// updateNumTroops()
///////////////////////////////////////////////////////////

void MilitaryState::updateNumTroops(int _numTroops, bool isAddition)
{
  if (isAddition)
  {
    numTroops = numTroops + _numTroops;
    return;
  }
  // subtract
  if (numTroops - _numTroops < 0)
    numTroops = 0;
  else
    numTroops = numTroops - _numTroops;
}

///////////////////////////////////////////////////////////
// getNumTanks()
///////////////////////////////////////////////////////////

int MilitaryState::getNumTanks()
{
  return tanks->size();
}

///////////////////////////////////////////////////////////
// updateNumTanks()
///////////////////////////////////////////////////////////

void MilitaryState::updateNumTanks(int _numTanks, bool isAddition)
{
  if (isAddition)
  {
    for (int i = 0; i < _numTanks; i++)
      tanks->push_back((Tank *)vehicleFactories->at(2)->manufactureVehicle());
    return;
  }
  // subtract
  else
  {
    for (int i = 0; i < _numTanks; i++)
    {
      Tank *tank = tanks->back();
      tanks->pop_back();
      delete tank;
      if (tanks->empty())
        break;
    }
  }
}

///////////////////////////////////////////////////////////
// getNumShips()
///////////////////////////////////////////////////////////

int MilitaryState::getNumShips()
{
  return ships->size();
}

///////////////////////////////////////////////////////////
// setNumShips()
///////////////////////////////////////////////////////////

void MilitaryState::updateNumShips(int _numShips, bool isAddition)
{
  if (isAddition)
  {
    for (int i = 0; i < _numShips; i++)
      ships->push_back((Ship *)vehicleFactories->at(0)->manufactureVehicle());
    return;
  }
  // subtract
  else
  {
    for (int i = 0; i < _numShips; i++)
    {
      Ship *ship = ships->back();
      ships->pop_back();
      delete ship;
      if (ships->empty())
        break;
    }
  }
}

///////////////////////////////////////////////////////////
// getNumPlanes()
///////////////////////////////////////////////////////////

int MilitaryState::getNumPlanes()
{
  return planes->size();
}

///////////////////////////////////////////////////////////
// setNumPlanes()
///////////////////////////////////////////////////////////

void MilitaryState::updateNumPlanes(int _numPlanes, bool isAddition)
{
  if (isAddition)
  {
    for (int i = 0; i < _numPlanes; i++)
      planes->push_back((Plane *)vehicleFactories->at(1)->manufactureVehicle());
    return;
  }
  // subtract
  else
  {
    for (int i = 0; i < _numPlanes; i++)
    {
      Plane *plane = planes->back();
      planes->pop_back();
      delete plane;
      if (planes->empty())
        return;
    }
  }
}

///////////////////////////////////////////////////////////
// getNumBattalions()
///////////////////////////////////////////////////////////

int MilitaryState::getNumBattalions()
{
  return battalions->size();
}

///////////////////////////////////////////////////////////
// updateNumBattalions()
///////////////////////////////////////////////////////////

void MilitaryState::updateNumBattalions(int _numBattalions, bool isAddition)
{
  if (isAddition)
  {
    for (int i = 0; i < _numBattalions; i++)
      battalions->push_back(new Battalion());
    return;
  }
  // subtract
  else
  {
    for (int i = 0; i < _numBattalions; i++)
    {
      Battalion *battalion = battalions->back();
      battalions->pop_back();
      delete battalion;
      if (battalions->empty())
        break;
    }
  }
}

///////////////////////////////////////////////////////////
// clone()
///////////////////////////////////////////////////////////
MilitaryState *MilitaryState::clone()
{
  MilitaryState *ms = new MilitaryState();
  vector<Ship *> *shipsClone = new vector<Ship *>();
  vector<Plane *> *planesClone = new vector<Plane *>();
  vector<Tank *> *tanksClone = new vector<Tank *>();
  vector<Battalion *> *battalionsClone = new vector<Battalion *>();
  vector<VehicleFactory *> *vehicleFactoriesClone = new vector<VehicleFactory *>();

  if (ships != NULL)
    for (int i = 0; i < ships->size(); i++)
      shipsClone->push_back(new Ship());
  if (planes != NULL)
    for (int i = 0; i < planes->size(); i++)
      planesClone->push_back(new Plane());
  if (tanks != NULL)
    for (int i = 0; i < tanks->size(); i++)
      tanksClone->push_back(new Tank());
  if (battalions != NULL)
    for (int i = 0; i < battalions->size(); i++)
      battalionsClone->push_back(new Battalion());
  if (vehicleFactories != NULL)
    for (int i = 0; i < vehicleFactories->size(); i++)
      vehicleFactoriesClone->push_back(vehicleFactories->at(i)->clone());

  ms->setShips(shipsClone);
  ms->setPlanes(planesClone);
  ms->setTanks(tanksClone);
  ms->setBattalions(battalionsClone);
  ms->setVehicleFactories(vehicleFactoriesClone);
  ms->setTroops(numTroops);
  return ms;
}
