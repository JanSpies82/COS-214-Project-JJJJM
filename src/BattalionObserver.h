#include <exception>
using namespace std;

#ifndef __BattalionObserver_h__
#define __BattalionObserver_h__

#include "ObserverState.h"
#include "Battalion.h"
#include "Observer.h"

class BattalionObserver: public Observer
{
	public:
		/**
		 * @brief notify observer about the changes in the subject
		 **/
		void update();
		/**
		 *@brief add subject to the observer
		 * 
		 * @param Battalion*
		 */ 
		void addSubject(Battalion*);
		
	private: 
		ObserverState* state;
		Battalion* subject;
		ObserverState* observerStates;
	
};

#endif
