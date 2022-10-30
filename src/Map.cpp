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
        arr2[j] = arr1[j];
    }

    for (int j = 0; j < 24; j++)//Probably Correct
    {
        if(j!=23)
            arr1[j]->add(new RightNeighbour(arr1[j+1]));

        if(j!=0)
            arr1[j]->add(new LeftNeighbour(arr1[j-1]));
    }

    for (int i = 1; i < 27; i++)//Check this index
    {
        for (int j = 0; j < 24; j++)//Probably Correct
        {
            arr1[j]=arr2[j];
            arr2[j] = new Territory(j,i, mapVal[i][j]);
        }

        for (int j = 0; j < 24; j++)//Probably Correct
        {
            if(j!=23)
            {
                arr2[j]->add(new RightNeighbour(arr2[j+1]));
            }

            if(j!=0)
            {
                arr2[j]->add(new LeftNeighbour(arr2[j-1]));
            }

            arr1[j]->add(new BottomNeighbour(arr2[j]));
            arr2[j]->add(new TopNeighbour(arr1[j]));
        }
        if(i==1)
            topLeft=arr1[0];

    }
}

Map::Map(Location* _cloneTopLeft){
    topLeft=_cloneTopLeft;
}

Map::~Map(){

    Iterator* it = topLeft->createIterator();

    it->first();
    while(!it->isDone()){
        Location* l=it->getCurrent();
        it->next();
        delete l;
    }

    delete it->getCurrent();
    delete it;  
}

Location* Map::getTopLeft(){
    return topLeft;
}

Location* Map::getLocation(int _x, int _y) {

    if(_x<0)
        throw out_of_range("Invalid X parameter. Expected greater than or equal to 0 and less than 24. Recieved: "+_x);

    if(_y<0)
        throw out_of_range("Invalid Y parameter. Expected greater than or equal to 0 and less than 27. Recieved: "+_x);

    Location* next=topLeft;

	for (int i = 0; i < _x; i++)
    {
        if(!next->hasRight())
            throw out_of_range("Invalid X parameter. Expected greater than or equal to 0 and less than 24. Recieved: "+_x);
            next=next->getRight();
    }

	for (int i = 0; i < _y; i++)
    {
        if(!next->hasBottom())
            throw out_of_range("Invalid Y parameter. Expected greater than or equal to 0 and less than 27. Recieved: "+_x);
        next=next->getBottom();
    }
    
    return next;
}

void Map::printMap(){

    Iterator* it = topLeft->createIterator();

    while(!it->isDone()){

        printLocation(it->getCurrent()->getColour());
        it->next();            

        if(!it->getCurrent()->hasLeft())
            std::cout<<endl;
    }

    printLocation(it->getCurrent()->getColour());

    std::cout<<endl;
    delete it;
}

Map::Map(Map* _oldMap){

    Location* arr1[24];
    Location* arr2[24];

    for (int j = 0; j < 24; j++)
    {
        arr1[j] = ((Territory*)_oldMap->getLocation(j,0))->clone();
        arr2[j] = arr1[j];
    }

    for (int j = 0; j < 24; j++)//Probably Correct
    {
        if(j!=23)
            arr1[j]->add(new RightNeighbour(arr1[j+1]));

        if(j!=0)
            arr1[j]->add(new LeftNeighbour(arr1[j-1]));
    }

    for (int i = 1; i < 27; i++)//Check this index
    {
        for (int j = 0; j < 24; j++)//Probably Correct
        {
            arr1[j]=arr2[j];
            arr2[j] = ((Territory*)_oldMap->getLocation(j,i))->clone();
        }

        for (int j = 0; j < 24; j++)//Probably Correct
        {
            if(j!=23)
            {
                arr2[j]->add(new RightNeighbour(arr2[j+1]));
            }

            if(j!=0)
            {
                arr2[j]->add(new LeftNeighbour(arr2[j-1]));
            }

            arr1[j]->add(new BottomNeighbour(arr2[j]));
            arr2[j]->add(new TopNeighbour(arr1[j]));
        }
        if(i==1)
            topLeft=arr1[0];

    }

}

void Map::printLocation(char _col){
     string x="";
        switch (_col){
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
        std::cout<<x;
}