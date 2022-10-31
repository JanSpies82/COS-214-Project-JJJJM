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
		}
		Battalion::Battalion(int damage){
			numBattalionDestroys=damage;
			groupSize=20;
		}
		
		Battalion::~Battalion(){
			cout<<"Battalion executed \n";
		}

		
		void Battalion::attack(Country* enemy){
			/*if(enemy!=NULL){
				vector<Battalion*> *fighters=enemy->getMilitary()->getBattalions();
				vector<Battalion*>::iterator *it;
				*it=fighters->begin();
				int i =0;
				while(i<numBattalionDestroys){
					delete it;
					it++;
				}
			}*/
		}
	
		
		void Battalion::setNumBattalionDestroys(int n){
			numBattalionDestroys=n;
		}
		
		
		int Battalion::getBattalionDestroyed(){
			return numBattalionDestroys;
		}

		void Battalion::attach(BattalionObserver obs){

		}

		void Battalion::dettach(BattalionObserver obs){
			
		}
