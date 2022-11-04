/// @author Jake Mahloko


#ifndef __BattalionObserver_h__
#define __BattalionObserver_h__

#include "ObserverState.h"
#include "Battalion.h"
#include "Observer.h"
#include <exception>

class BattalionObserver: public Observer
{
	public:
		/**
		 * @brief notify observer about the changes in the subject
		 **/
		void update();
		
	private: 
		ObserverState state;
		Battalion subject;
		ObserverState* observerStates;
	
};

#endif
