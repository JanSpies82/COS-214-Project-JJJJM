
#ifndef __Military_h__
#define __Military_h__

#include <vector>

class VehicleFactory;
class Plane;
class Ship;
class Tank;
class Battalion;
class Country;


class Military
{
	public:
		/**
		 * @brief construct military objects
		 */
		Military();

		Military(Military*);
		/**
		 * @brief destruct military objects
		 */
		~Military();
		/**
		 * @brief converts Citizens into battalions
		 * @param Citizen object- should be the population
		 */
		void addBattalions();
		/**
		 * @brief sets number of deceased battalions in battle
		 **/
		void decreaseBattalions(int deceased);
		/**
		 * 
		 *  
		 */
		void insertPlanes(Plane* plane);
		/**
		 * 
		 *  
		 */
		
		void insertTanks(Tank* tanks);
		/**
		 * 
		 *  
		 */
		
		void insertShips(Ship* ship);
		/**
		 * 
		 *  
		 */
		

		void clearShips();
		/**
		 * 
		 * 
		 * 
		 */

		 void clearTanks();

		 /**
		 * 
		 * 
		 * 
		 */

		 void clearPlanes();
		 /**
		 * 
		 * 
		 * 
		 */

		 void clearBatalions();
		/**
		 * @brief retrieve the number of battablions
		 * 
		 * @return int
		 */
		int getNumBattalions();

		/**

		 * @brief retrieve the number of tanks
		 * 
		 * @return int 
		 */
		int getNumTanks();

		/**
		 * @brief retrieve  number of planes
		 * 
		 * @return int
		 */
		int getNumPlanes();

		/**
		 * @brief retrieve number of ships
		 * 
		 * @return int
		 */
		int getNumShips();

		/**
		 * @brief retrieve total number of Vehicles
		 * 
		 * @return int
		 */
		int getNumVehicles();

		/**

		 * @brief atttack function
		 * 
		 */
		void attack(Country* enemy);//a bit tricky but sum the up the damage of the entire army well that might be an option
		/**
		*@brief retrieve the 
		*
		* @return Batalion*
		*/
		std::vector<Battalion*>* getBatallions();
		/**
		 * 
		 * 
		 * 
		 */
		Military * getMilitary();
		/**
		 * 
		 * 
		 * 
		 */
		std::vector<Ship*>* getShips();
		/**
		 * 
		 * 
		 * 
		 */ 
		std::vector<Tank*>* getTanks();
		/**
		 * 
		 * 
		 * 
		 */
		std::vector<Plane*>*  getPlanes();
		/**
		 * 
		 * 
		 */
		void setNumTroops(int);
		/**
		 * 
		 * 
		 */
		 int getNumTroops(); 
		 /**
		 * 
		 *  
		 */
		void insertBatalions(Battalion* );
	private: 
		std::vector<Battalion*>* battalions;
		std::vector<Ship*>* ships;
		std::vector<Tank*>* tanks;
		int numTroops;
		//Country* countries;
		std::vector<Plane*>* planes;
		std::vector<VehicleFactory*>* vehicleFactories;
		
};

#endif
