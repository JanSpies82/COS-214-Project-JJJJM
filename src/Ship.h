#include <exception>
using namespace std;

#ifndef __Ship_h__
#define __Ship_h__

#include "Vehicle.h"



class Ship: public Vehicle
{

	public: 
		Ship();
		~Ship();
		void attack(Country* enemy);
		void findEnemy();
		void destroyEnemy(Country* enemy);
		void setNumBattalionDestroys(int);
		void setNumShipDestroys(int);
		int getBattalionDestroyed();
		int getShipDestroyed();
	private:
		int numBattalionDestroys;
		int numShipDestroys;
};

#endif
