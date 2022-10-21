#include <exception>
using namespace std;

#ifndef __Plane_h__
#define __Plane_h__

#include "Vehicle.h"

class Plane: public Vehicle
{

	public: 
		Plane();
		~Plane();
		void attack(Country* enemy);
		void findEnemy();
		void destroyEnemy(Country * enemy);
		void setNumBattalionDestroys(int);
		void setNumTankDetroys(int);
		void setNumPlanesDestroys(int);
		int getTankDestroyed();
		int getBattalionDestroyed();
		int getPlanesDestroyed();
	public:
		int numBattalionDestroys;
		int numTankDetroys;
		int numPlanesDestroys;
};

#endif
