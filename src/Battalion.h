
#ifndef __Battalion_h__
#define __Battalion_h__


class Battalion
{
	public:
		void attack();
		void addBattalions(Citizen *c);
		void decreaseBattalions(int deceased);
		int getBattalionDestroyed();
	private:
	int numBattalionDestroys;
		
};

#endif
