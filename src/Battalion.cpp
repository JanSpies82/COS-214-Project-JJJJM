/// @author Jake Mahloko

#include "Battalion.h"

using namespace std;

Battalion::Battalion()
{
	numBattalionDestroys=5;
	groupSize=20;
}

Battalion::Battalion(int damage)
{
	numBattalionDestroys=damage;
	groupSize=20;
}

Battalion::~Battalion(){}


void Battalion::attack(Country* enemy){}

void Battalion::setNumBattalionDestroys(int n)
{
	numBattalionDestroys=n;
}

int Battalion::getBattalionDestroyed()
{
	return numBattalionDestroys;
}