#include <exception>
using namespace std;

#ifndef __Tank__h__
#define __Tank__h__

#include "Vehicle.h"



class Tank_: public Vehicle
{

	public: 
		Tank_();
		~Tank();
		void attack(Country* enemy);
		void findEnemy();
		void destroyEnemy(Country* enemy);
		void setNumBattalionDestroys(int);
		void setNumTankDetroys(int);
		int getBattalionDestroyed();
		int getTankDestroyed();
	private: 
		int numBattalionDestroys;
		int numTankDetroys;

};

#endif
