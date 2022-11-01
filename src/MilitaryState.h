/// @author Jake Mahloko

#ifndef __MilitaryState_h__
#define __MilitaryState_h__
#include <vector>
#include <exception>

class Plane;
class Ship;
class Tank;
class Battalion;
class VehicleFactory;

class MilitaryState
{
public:
  /**
   * @brief construct a MilitaryState Object
   **/
  MilitaryState();

  ~MilitaryState();

  /**
   * @brief getter for the numTroops attribute
   * @return the number of troops of the military
   */
  int getNumTroops();

  /**
   * @brief setter for the numTroops attribute
  */
  void setNumTroops(int numTroops);

  /**
   * @brief getter for the numTanks attribute
   * @return the number of tanks of the military
  */
  int getNumTanks();

  /**
   * @brief setter for the numTanks attribute
   * @param numTanks the new number of tanks
  */
  void setNumTanks(int numTanks);

  /**
   * @brief getter for the number of planes of a country's military
   * @return the number of planes of the military
  */
  int getNumPlanes();

  /**
   * @brief setter for the numPlanes attribute
   * @param numPlanes the new number of planes
  */
  void setNumPlanes(int numPlanes);

  /**
   * @brief getter for the number of ships of a country's military
   * @return the number of ships of the military
  */
  int getNumShips();

  /**
   * @brief setter for the numShips attribute
   * @param numShips the new number of ships
  */
  void setNumShips(int numShips);
  
  Military* getState(); 
  void setNumBattalions();
  int getNumBatalions();		

private:
	std::vector<Battalion*>* battalions;
  std::vector<Ship*>* ships;
  std::vector<Tank*>* tanks;
  std::vector<Plane*>* planes;
  std::vector<VehicleFactory*>* vehicleFactories;
};

#endif
