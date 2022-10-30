#include <exception>
#include <iostream>
#include <cstring>

using namespace std;

#include "Map.h"
#include "Location.h"
#include "SimulationManager.h"
#include "Territory.h"
#include "RightNeighbour.h"
#include "TopNeighbour.h"
#include "BottomNeighbour.h"
#include "LeftNeighbour.h"
#include "LocationIterator.h"

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
        string mapVal[27]={
        "000000000000000099000066",
        "000000000000000996666666",
        "000000000000009996666666",
        "000000000000009966660066",
        "000000000000099966666666",
        "000000000000099906666666",
        "000000000000999906666666",
        "000000000009999006666666",
        "000000000009999906666666",
        "000000030009999900666666",
        "000000330009099990777666",
        "000000330000709007777766",
        "000033330000770007777777",
        "000033033000777777777777",
        "000300333077777777777777",
        "000003330447777777777777",
        "000000004447777777777777",
        "000004444444777777777777",
        "000000444444887777777777",
        "000000044444888877777777",
        "002220044444880888777777",
        "002222224440088008877755",
        "002222222000008800855555",
        "022222220000800888050055",
        "022222200000800080055005",
        "002222000000008880005000",
        "000000000000000800000550",
    };

    Location* arr1[24];
    Location* arr2[24];

    for (int j = 0; j < 24; j++)
    {
        arr1[j] = new Territory(j,0, mapVal[0][j]);
    }

    for (int i = 0; i < 26; i++)
    {
        if(i!=0){
            for (int j = 0; j < 24; j++)
            {
                arr1[j]=arr2[j];
            }
        }

        for (int j = 0; j < 24; j++)
        {
            arr2[j] = new Territory(j,i, mapVal[i][j]);
        }
        
        for (int k = 0; k < 23; k++)
        {
            arr1[k]->add(new RightNeighbour(arr1[k+1]));
            arr2[k]->add(new RightNeighbour(arr2[k+1]));
            arr1[k]->add(new BottomNeighbour(arr2[k]));
            arr2[k]->add(new TopNeighbour(arr1[k]));
        }

        for (int k = 1; k < 24; k++)
        {
            arr1[k]->add(new LeftNeighbour(arr1[k-1]));
            arr2[k]->add(new LeftNeighbour(arr2[k-1]));

            if(k==24){
                arr1[k]->add(new BottomNeighbour(arr2[k]));
                arr2[k]->add(new TopNeighbour(arr1[k]));
            }
        }
        if(i==0)
            topLeft = arr1[0];
    }
    
}

Map::~Map(){
    Location* curr=topLeft;
    Location* next;
    Location* nextRow;
    for (int i = 0; i < 26; i++)//Check index later
    {
        nextRow=curr->getBottom();
        for (int j = 0; j < 23; j++)//Check index later
        {
            next=curr->getRight();
            delete curr;
            curr=next;
        }
        curr=nextRow;

    }
    // Iterator* it = topLeft->createIterator();
    // it->first();
    // while(!it->isDone()){
    //     Location *l = it->getCurrent();
    //     it->next();
    //     delete l;
    // }
    // delete it;
    
}

Location* Map::getTopLeft(){
    return topLeft;
}

void Map::printMap(){
    Location* curr=topLeft;
    Location* nextRow=topLeft;
    int j=0;
    while(curr->hasBottom()){
        if(nextRow->hasBottom())
            nextRow=nextRow->getBottom();
        while(curr->hasRight()){
            char c=curr->getColour();
            string x="";
            switch (c){
                case '0':
                        x="\x1B[44m  \033[0m";//sea blue
                break;
                case '1':
                    x="\x1B[102m  \033[0m";//Land green later green used for other things
                break;
                case '2':
                    x="\x1B[45m  \033[0m"; //Spain + Portuagal Magenta
                break;
                case '3':
                        x="\x1B[46m  \033[0m";//UK Cyan
                break;
                case '4':
                        x="\x1B[107m  \033[0m";//France White
                break;
                case '5':
                        x="\x1B[106m  \033[0m";//Greece+Bulkans bright cyan
                break;
                case '6':
                        x="\x1B[102m  \033[0m";//Easter Europe+Russia green
                break;
                case '7':
                        x="\x1B[41m  \033[0m";//Germany Red
                break;
                case '8':
                        x="\x1B[43m  \033[0m";//Italy Yellow
                break;
                case '9':
                        x="\x1B[105m  \033[0m";//Scandenavia bright magenta
                break;
            }

            int n=x.length();
            char char_array[n + 1];
            std::strcpy(char_array, x.c_str());
            std::printf(char_array);
            curr=curr->getRight();
        }
        std::printf("\n");
        curr=nextRow;
    }
}

Map* Map::clone(){
    Location* arr1[24];
    Location* arr2[24];

    for (int j = 0; j < 24; j++)
    {
        arr1[j] = ((Territory*)this->getLocation(j,0))->clone();
    }

    for (int i = 0; i < 26; i++)
    {
        if(i!=0){
            for (int j = 0; j < 24; j++)
            {
                arr1[j]=arr2[j];
            }
        }

        for (int j = 0; j < 24; j++)
        {
            arr2[j] =((Territory*)this->getLocation(j,i))->clone();
        }
        
        for (int k = 0; k < 23; k++)
        {
            arr1[k]->add(new RightNeighbour(arr1[k+1]));
            arr2[k]->add(new RightNeighbour(arr2[k+1]));
            arr1[k]->add(new BottomNeighbour(arr2[k]));
            arr2[k]->add(new TopNeighbour(arr1[k]));
        }

        for (int k = 1; k < 24; k++)
        {
            arr1[k]->add(new LeftNeighbour(arr1[k-1]));
            arr2[k]->add(new LeftNeighbour(arr2[k-1]));

            if(k==24){
                arr1[k]->add(new BottomNeighbour(arr2[k]));
                arr2[k]->add(new TopNeighbour(arr1[k]));
            }
        }
        if(i==0)
            topLeft = arr1[0];
    }    
}
