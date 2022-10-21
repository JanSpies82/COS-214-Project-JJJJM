#include <exception>
using namespace std;

#ifndef __Vehicle_h__
#define __Vehicle_h__
#include"Country.h"//every vehicle is going to use attack to attack each Country

 class Vehicle
{
	
	public: 
		Vehicle();
		~Vehicle();
		virtual void attack(Country* enemy)=0;//is it the same thing as destroy?
		virtual void findEnemy() = 0;
		virtual void destroyEnemy(Country* enemy) = 0;

};

#endif
