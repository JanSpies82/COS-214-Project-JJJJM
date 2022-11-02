
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
		 * @brief add the Plane* to the vector of planes in military
		 *  
		 * @param Plane*
		 */
		void insertPlanes(Plane* plane);
		/**
		 *@brief  add the Tank* to the vector of tanks in military
		 * 
		 * 
		 *@param  Tank*
		 */
		
		void insertTanks(Tank* tanks);
		/**
		 * @brief  add the Ship* to the vector of ships in military
		 *  
		 * @param Ship*
		 */
		
		void insertShips(Ship* ship);
		/**
		 * @brief clear all the ships in the vector of ships in military
		 *  
		 */
		

		void clearShips();
		/**
		 * @brief clear all the tanks in the vector of tanks in military
		 * 
		 */

		 void clearTanks();

		 /**
		 * @brief clear all the planes in the vector of planes in military
		 *  
		 */

		 void clearPlanes();
		 /**
		 * @brief clear all the battalions in the vector of battalions in military
		 * 
		 */ 

		 void clearBattalions();
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
		*@brief retrieve the vector of battalions
		*
		* @return vector<Batalion*>*
		*/
		std::vector<Battalion*>* getBattalions();
		/**
		 *@brief retrieve the military 
		 *
		 * @return Military* 
		 */
		Military * getMilitary();
		/**
		 * @brief retrieve the vector of ships
		 * 
		 * @return vector<Ship*>*
		 */
		std::vector<Ship*>* getShips();
		/**
		 * @brief retrieve the vector of tanks
		 * 
		 * @return vector<Tank*>*
		 */ 
		std::vector<Tank*>* getTanks();
		/**
		 * @brief retrieve the vector of planes
		 * 
		 * @return vector<Plane*>*
		 */
		std::vector<Plane*>*  getPlanes();
		/**
		 *@brief sets the number of troops 
		 * 
		 *@param int
		 */
		void setNumTroops(int);
		/**
		 * @brief retrieves numTroops
		 *
		 * @return int
		 */
		 int getNumTroops(); 
		 /**
		 * @brief insert battalions in battalion vector 
		 *  
		 */
		void insertBattalions(Battalion* );
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
