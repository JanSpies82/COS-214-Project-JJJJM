/// @author Jake Mahloko

#ifndef __MilitaryState_h__
#define __MilitaryState_h__
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>

class Plane;
class Ship;
class Tank;
class Battalion;
class VehicleFactory;

class MilitaryState
{

public:

  /**
   * @brief Default constructor
   */
  MilitaryState();

  /**
   * @brief Default destructor
   */
  ~MilitaryState();

  /**
   * @brief setter for the ships in this military
  */
  void setShips(std::vector<Ship*>* _ships);

  /**
   * @brief setter for the planes in this military
  */
  void setPlanes(std::vector<Plane*>* _planes);

  /**
   * @brief setter for the tanks in this military
  */
  void setTanks(std::vector<Tank*>* _tanks);

  /**
   * @brief Setter for the battalions
  */
  void setBattalions(std::vector<Battalion*>* _battalions);

  /**
   * @brief setter for the VehicleFactories object
  */
  void setVehicleFactories(std::vector<VehicleFactory*>* _vehicleFactories);

  /**
   * @brief getter number of troops (integer)
   * 
   * @return number of troops in this military (integer)
  */
  int getNumTroops();

  /**
   * @brief updates the number of troops in this military
   */
  void updateNumTroops(int _numTroops, bool isAddition);

  /**
   * @brief getter for the number of tanks in this military
   * 
   * @return the number of tanks in this military
  */
  int getNumTanks();

  /**
   * @brief updates the number of tanks through addition or subtraction
   * 
   * @param _numTanks the number of tanks to add or subtract
   * 
   * @param isAddition true if the number of tanks is to be added, false if it is to be subtracted
   */
  void updateNumTanks(int _numTanks, bool isAddition);

  /**
   * @brief getter for the number of ships in this military
   * 
   * @return the number of ships in this military (integer)
  */
  int getNumShips();

  /**
   * @brief updates the number of ships through addition or subtraction
   * 
   * @param _numShips the number of ships to add or subtract
   * 
   * @param isAddition true if the number of ships is to be added, false if it is to be subtracted
  */
  void updateNumShips(int _numShips, bool isAddition);
  
  /**
   * @brief getter for the number of planes in this military
   * 
   * @return number of planes in this military (integer)
  */
  int getNumPlanes();

  /**
   * @brief Get the number of Vehicle Factories object
  */
  void updateNumPlanes(int _numPlanes, bool isAddition);

  /**
   * @brief Get the number of battalion objects in this military
  */
  int getNumBattalions();

  /**
   * @brief updates the number of battalions through addition or subtraction
   * 
   * @param _numBattalions the number of battalions to add or subtract
   * 
   * @param isAddition true if the number of battalions is to be added, false if it is to be subtracted
   */
  void updateNumBattalions(int _numBattalions, bool isAddition);

  /**
   * @brief Create a deep copy of this object
   * 
   * @return MilitaryState* 
   */
  MilitaryState* clone();

private:
  int numTroops;
  std::vector<Tank*>* tanks;
  std::vector<Ship*>* ships;
  std::vector<Plane*>* planes;
  std::vector<Battalion*>* battalions;
  std::vector<VehicleFactory*>* vehicleFactories;
};

#endif
