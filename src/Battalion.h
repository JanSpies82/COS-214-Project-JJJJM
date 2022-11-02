
#ifndef __Battalion_h__
#define __Battalion_h__
#include<vector>
class Country;
class Citizen;
class BattalionObserver;

class Battalion
{
	public:
		/**
		 * @brief construct a Battalion object
		 * */
		Battalion();
		/**
		 * @brief construct a Battalion object
		 * @param int value
		 * */
		Battalion(int);
		/**
		 * @brief destroys a Battallion object
		 **/
		virtual ~Battalion();

		/**
		 * @brief attack method towards the enemy Country
		 * @param Country*- Country reference object
		 **/
		void attack(Country* enemy);
	
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
		/**
		 * @brief function attaches the observer to subject(battalion)
		 * 
		 * @param BattalionObserver *
		 * */
		void attach(BattalionObserver *obs);
		/**
		 * @brief detach function remove an observer from the vector of observers
		 * 
		 *@param BattalionObserver* 
		 */ 
		void detach(BattalionObserver *obs);
		/**
		 * @brief deletes all the observers in the obs vector
		 * 
		 */
		void clearObservers();
	private:
	int numBattalionDestroys;
	int groupSize;
	std::vector<BattalionObserver*> * obs;
		
};

#endif
