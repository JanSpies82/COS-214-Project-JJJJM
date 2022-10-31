#include "MilitaryState.h"
#include "Military.h"

MilitaryState::MilitaryState(Military * m){
	State=m;
}

MilitaryState::~MilitaryState(){

}
		
void MilitaryState::storeState(Military * m){
	State=m;
}

Military* MilitaryState:: getState(){
    return State;
}


