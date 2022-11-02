using namespace std;
#include<vector>
#include<iostream>
#include "Battalion.h"
#include "Military.h"
#include"BattalionObserver.h"
#include"Country.h"
		Battalion::Battalion(){
			numBattalionDestroys=5;
			groupSize=20;
			obs=new vector<BattalionObserver*>();
		}
		Battalion::Battalion(int damage){
			numBattalionDestroys=damage;
			groupSize=20;
		}
		
		Battalion::~Battalion(){
			clearObservers();
    		delete obs;
		}

		
void Battalion::attack(Country* enemy){
	if(enemy!=NULL){
		vector<Battalion*> *fighters1=enemy->getMilitary()->getBattalions();
		if(fighters1->size()>numBattalionDestroys){
			for (int i = 0; i < numBattalionDestroys; i++)
    	   		delete fighters1->at(i);
		}else if(fighters1->size()>0){
			enemy->getMilitary()->clearBattalions();
		}
	}else{
			__throw_invalid_argument("NULLPTR PASSED IN");
	}
}
	
		
		void Battalion::setNumBattalionDestroys(int n){
			numBattalionDestroys=n;
		}
		
		
		int Battalion::getBattalionDestroyed(){
			return numBattalionDestroys;
		}

		void Battalion::attach(BattalionObserver *o){
			obs->push_back(o);
		}

		void Battalion::detach(BattalionObserver *o){
			for(int i=0;i<obs->size();i++){
				if(o==obs->at(i)){
					delete obs->at(i);
				}
			}
		}

void Battalion::clearObservers(){
    for(int i=0;i<obs->size();i++)
        delete this->obs->at(i); 
}