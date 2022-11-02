#include <exception>
using namespace std;

#include "BattalionObserver.h"
#include "ObserverState.h"
#include "Battalion.h"
#include "Observer.h"

void BattalionObserver::update() {
	throw "Not yet implemented";
}

void BattalionObserver::addSubject(Battalion * sub){
	subject=sub;
}

