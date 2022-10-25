
#ifndef __Battalion_h__
#define __Battalion_h__

class Country;
class Citizen;

class Battalion
{
	public:
		/**
		 * @brief construct a Battalion object
		 * */
		Battalion();

		/**
		 * @brief destroys a Battallion object
		 **/
		~Battalion();

		/**
		 * @brief attack method towards the enemy Country
		 * @param Country*- Country reference object
		 **/
		void attack(Country* enemy);

<<<<<<< HEAD
		
=======
		/**
		 * @brief converts Citizens into battalions
		 * @param Citizen object- should be the population
		 **/
		void addBattalions(Citizen *_citizen);

>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		/**
		 * @brief sets number of deceased battalions in battle
		 **/
		void decreaseBattalions(int deceased);

		/**
		 * @brief sets the number Battalions an attack of a battallion kills.
		 * @param int of the number of Battalions
		 **/
		void setNumBattalionDestroys(int);
		
		/**
		 * @brief retrieve number of battallions the battablion can destroy
		 * @return int - number of Battalions
		 **/
		int getBattalionDestroyed();
	private:
	int numBattalionDestroys;
<<<<<<< HEAD
	int groupSize;
=======
>>>>>>> 9b5003816acc0289ff0b93f9fa23c9d166f3902d
		
};

#endif
