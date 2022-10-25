
#ifndef __Military_h__
#define __Military_h__

<<<<<<< HEAD

=======
// #include "Battalion.h"
// #include "Plane.h"
// #include "Ship.h"
// #include "Tank.h"
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
#include <vector>

class VehicleFactory;
class Plane;
class Ship;
class Tank;
class Battalion;
<<<<<<< HEAD
class Country;
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d


class Military
{
	public:
		/**
<<<<<<< HEAD
		 * @brief construct military objects
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		Military();

		/**
<<<<<<< HEAD
		 * @brief destruct military objects
		 **/
		~Military();
		/**
		 * @brief converts Citizens into battalions
		 * @param Citizen object- should be the population
		 **/
		void addBattalions(Citizen *_citizen);

		/**
		 * @brief retrieve the number of battablions
		 * 
		 * @return int
=======
		 **/
		~Military();

		/**
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		int getNumBattalions();

		/**
<<<<<<< HEAD
		 * @brief retrieve the number of tanks
		 * 
		 * @return int 
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		int getNumTanks();

		/**
<<<<<<< HEAD
		 * @brief retrieve  number of planes
		 * 
		 * @return int
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		int getNumPlanes();

		/**
<<<<<<< HEAD
		 * @brief retrieve number of ships
		 * 
		 * @return int
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		int getNumShips();

		/**
<<<<<<< HEAD
		 * @brief retrieve total number of Vehicles
		 * 
		 * @return int
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		 **/
		int getNumVehicles();

		/**
<<<<<<< HEAD
		 * @brief atttack function
		 * 
		 **/
		void attack(Country* enemy);//a bit tricky but sum the up the damage of the entire army well that might be an option
=======
		 **/
		void attack();//a bit tricky but sum the up the damage of the entire army well that might be an option
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		
	private: 
		std::vector<Battalion*>* battalions;
		std::vector<Ship*>* ships;
		std::vector<Tank*>* tanks;
		//Country* countries;
		std::vector<Plane*>* planes;
		std::vector<VehicleFactory*>* vehicleFactories;
		// Battalion* battalions;
};

#endif
