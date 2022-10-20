#include <exception>
using namespace std;

#ifndef __BattalionObserver_h__
#define __BattalionObserver_h__

#include "ObserverState.h"
#include "Battalion.h"
#include "Observer.h"

class ObserverState;
class Battalion;
// class Observer;
class BattalionObserver;

class BattalionObserver: public Observer
{
	private: ObserverState state;
	private: Battalion subject;
	public: ObserverState* observerStates;

	public: void update();
};

#endif
