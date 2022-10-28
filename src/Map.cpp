#include <exception>
using namespace std;

#include "Map.h"
#include "Location.h"
#include "SimulationManager.h"
#include "Territory.h"
#include "RightNeighbour.h"
#include "TopNeighbour.h"
#include "BottomNeighbour.h"
#include "LeftNeighbour.h"

Location* Map::getLocation(int x, int y) {//Need to add exception handling
    Location* next=topLeft;
	for (int i = 0; i < x; i++)
    {
        next=next->getRight();
    }

	for (int i = 0; i < y; i++)
    {
        next=next->getBottom();
    }
    
    return next;
}

Map::Map(){
    Location* arr1[23];
    Location* arr2[23];

    for (int j = 0; j < 23; j++)
    {
        arr1[j] = new Territory(j,0);
        arr2[j]=NULL;
    }

    for (int i = 0; i < 26; i++)
    {
        if(i!=0){
            for (int j = 0; j < 23; j++)
            {
                arr1[j]=arr2[j];
            }
            
            
        }

        for (int j = 0; j < 23; j++)
        {
            arr2[j] = new Territory(j,i);
        }
        
        for (int k = 0; k < 22; k++)
        {
            arr1[k] = new RightNeighbour(arr1[k], arr1[k+1]);
            arr2[k] = new RightNeighbour(arr2[k], arr2[k+1]);
            arr1[k] = new BottomNeighbour(arr1[k], arr2[k]);
            arr2[k] = new TopNeighbour(arr2[k], arr1[k]);
        }

        for (int k = 1; k < 23; k++)
        {
            arr1[k] = new LeftNeighbour(arr1[k], arr1[k-1]);
            arr2[k] = new LeftNeighbour(arr2[k], arr2[k-1]);

            if(k==23){
                arr1[k] = new BottomNeighbour(arr1[k], arr2[k]);
                arr2[k] = new TopNeighbour(arr2[k], arr1[k]);
            }
        }
        if(i==0)
            topLeft = arr1[0];
    }
    
}
    Map::~Map(){
        
    }


