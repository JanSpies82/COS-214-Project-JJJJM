#include <exception>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

class Iterator;

class Iterator
{

	public: 
		virtual void topLeft() = 0;	
		virtual void right() = 0;		
		virtual void left() = 0;		
		virtual void down() = 0;		
		virtual void up() = 0;		
		virtual void isDone() = 0;		
		virtual void current() = 0;
};

#endif
