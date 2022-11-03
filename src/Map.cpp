/// @author Julian Pienaar


#include "Map.h"
#include "Location.h"
#include "SimulationManager.h"
#include "Territory.h"
#include "RightNeighbour.h"
#include "TopNeighbour.h"
#include "BottomNeighbour.h"
#include "LeftNeighbour.h"
#include "LocationIterator.h"
#include "MapState.h"
#include <iostream>

using namespace std;

Map::Map()
{
    string colors[10] = {"\x1B[44m", "\x1B[40m", "\x1B[45m", "\x1B[46m", "\x1B[107m", "\x1B[106m", "\x1B[102m", "\x1B[41m", "\x1B[43m", "\x1B[105m"};

    int mapVal[27][25] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,0,0,0,0,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,6,6,6,6,0,0,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,0,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,0,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0,0,0,0,9,9,1,9,0,0,6,6,6,6,6,1,6},
        {0,0,0,0,0,0,0,0,0,0,0,9,9,9,9,9,0,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,3,0,0,0,9,9,9,9,9,0,0,6,6,6,6,6,6},
        {0,0,0,0,0,0,3,3,0,0,0,9,0,9,9,9,9,0,7,7,7,6,6,6},
        {0,0,0,0,0,0,3,3,0,0,0,0,7,0,9,0,0,7,7,7,7,7,6,6},
        {0,0,0,0,3,3,3,3,0,0,0,0,7,7,0,0,0,7,7,7,7,7,7,7},
        {0,0,0,0,3,3,0,3,3,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7},
        {0,0,0,3,0,0,3,3,3,0,7,7,7,7,7,1,7,7,7,7,7,7,7,7},
        {0,0,0,0,0,3,3,1,0,4,4,7,7,7,7,7,7,7,7,7,7,7,7,7},
        {0,0,0,0,0,0,0,0,4,4,4,7,7,7,7,7,7,7,7,7,7,7,7,7},
        {0,0,0,0,0,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7,7,7,7,7},
        {0,0,0,0,0,0,4,4,4,1,4,4,8,8,7,7,7,7,7,7,7,7,7,7},
        {0,0,0,0,0,0,0,4,4,4,4,4,8,8,8,8,7,7,7,7,7,7,7,7},
        {0,0,2,2,2,0,0,4,4,4,4,4,8,8,0,8,8,8,7,7,7,7,7,7},
        {0,0,2,2,2,2,2,2,4,4,4,0,0,8,8,0,0,8,8,7,7,7,5,5},
        {0,0,2,2,2,2,2,2,2,0,0,0,0,0,1,8,0,0,8,5,5,5,5,5},
        {0,2,2,2,1,2,2,2,0,0,0,0,8,0,0,8,8,8,0,5,0,0,5,5},
        {0,2,2,2,2,2,2,0,0,0,0,0,8,0,0,0,8,0,0,5,5,0,0,5},
        {0,0,2,2,2,2,0,0,0,0,0,0,0,0,8,8,8,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,5,5,0}
    };

    Location *arr1[24];
    Location *arr2[24];

    for (int j = 0; j < 24; j++)
    {
        arr1[j] = new Territory(j, 0, colors[mapVal[0][j]]);

        if (mapVal[0][j] == 1)
            arr1[j]->setIsCapital(true);
        if (mapVal[0][j] == 0)
            arr1[j]->setIsLand(false);

        arr2[j] = arr1[j];
    }

    for (int j = 0; j < 24; j++) // Probably Correct
    {
        if (j != 23)
            arr1[j]->add(new RightNeighbour(arr1[j + 1]));

        if (j != 0)
            arr1[j]->add(new LeftNeighbour(arr1[j - 1]));
    }

    for (int i = 1; i < 27; i++) // Check this index
    {
        for (int j = 0; j < 24; j++) // Probably Correct
        {
            arr1[j] = arr2[j];
            arr2[j] = new Territory(j, i, colors[mapVal[i][j]]);

            if (mapVal[i][j] == 1)
                arr2[j]->setIsCapital(true);
            if (mapVal[i][j] == 0)
                arr2[j]->setIsLand(false);
        }

        for (int j = 0; j < 24; j++) // Probably Correct
        {
            if (j != 23)
            {
                arr2[j]->add(new RightNeighbour(arr2[j + 1]));
            }

            if (j != 0)
            {
                arr2[j]->add(new LeftNeighbour(arr2[j - 1]));
            }

            arr1[j]->add(new BottomNeighbour(arr2[j]));
            arr2[j]->add(new TopNeighbour(arr1[j]));
        }
        if (i == 1)
            topLeft = arr1[0];
    }
}

Map::Map(Location *_cloneTopLeft)
{
    topLeft = _cloneTopLeft;
}

Map::~Map()
{

    Iterator *it = topLeft->createIterator();

    it->first();
    while (!it->isDone())
    {
        Location *l = it->getCurrent();
        it->next();
        delete l;
    }

    delete it->getCurrent();
    delete it;
}

Location *Map::getTopLeft()
{
    return topLeft;
}

Location *Map::getLocation(int _x, int _y)
{

    if (_x < 0)
        throw out_of_range("Invalid X parameter. Expected greater than or equal to 0 and less than 24. Recieved: " + _x);

    if (_y < 0)
        throw out_of_range("Invalid Y parameter. Expected greater than or equal to 0 and less than 27. Recieved: " + _x);

    Location *next = topLeft;

    for (int i = 0; i < _x; i++)
    {
        if (!next->hasRight())
            throw out_of_range("Invalid X parameter. Expected greater than or equal to 0 and less than 24. Recieved: " + _x);
        next = next->getRight();
    }

    for (int i = 0; i < _y; i++)
    {
        if (!next->hasBottom())
            throw out_of_range("Invalid Y parameter. Expected greater than or equal to 0 and less than 27. Recieved: " + _x);
        next = next->getBottom();
    }

    return next;
}

void Map::printMap()
{

    Iterator *it = topLeft->createIterator();

    while (!it->isDone())
    {

        printLocation(it->getCurrent()->getColor());
        it->next();

        if (!it->getCurrent()->hasLeft())
            std::cout << endl;
    }

    printLocation(it->getCurrent()->getColor());

    std::cout << endl;
    delete it;
}

Map::Map(Map *_oldMap)
{

    Location *arr1[24];
    Location *arr2[24];

    for (int j = 0; j < 24; j++)
    {
        arr1[j] = _oldMap->getLocation(j, 0)->clone();
        arr2[j] = arr1[j];
    }

    for (int j = 0; j < 24; j++) // Probably Correct
    {
        if (j != 23)
            arr1[j]->add(new RightNeighbour(arr1[j + 1]));

        if (j != 0)
            arr1[j]->add(new LeftNeighbour(arr1[j - 1]));
    }

    for (int i = 1; i < 27; i++) // Check this index
    {
        for (int j = 0; j < 24; j++) // Probably Correct
        {
            arr1[j] = arr2[j];
            arr2[j] = ((Territory *)_oldMap->getLocation(j, i))->clone();
        }

        for (int j = 0; j < 24; j++) // Probably Correct
        {
            if (j != 23)
            {
                arr2[j]->add(new RightNeighbour(arr2[j + 1]));
            }

            if (j != 0)
            {
                arr2[j]->add(new LeftNeighbour(arr2[j - 1]));
            }

            arr1[j]->add(new BottomNeighbour(arr2[j]));
            arr2[j]->add(new TopNeighbour(arr1[j]));
        }
        if (i == 1)
            topLeft = arr1[0];
    }
}

void Map::printLocation(string _col)
{
    string x = _col + "  \033[0m";
    // switch (_col){
    //     case '0':
    //         x="\x1B[44m  \033[0m";//sea blue
    //     break;
    //     case '1':
    //         x="\x1B[102m  \033[0m";//Land green later green used for other things
    //     break;
    //     case '2':
    //         x="\x1B[45m  \033[0m"; //Spain + Portuagal Magenta
    //     break;
    //     case '3':
    //             x="\x1B[46m  \033[0m";//UK Cyan
    //     break;
    //     case '4':
    //             x="\x1B[107m  \033[0m";//France White
    //     break;
    //     case '5':
    //             x="\x1B[106m  \033[0m";//Greece+Bulkans bright cyan
    //     break;
    //     case '6':
    //             x="\x1B[102m  \033[0m";//Easter Europe+Russia green
    //     break;
    //     case '7':
    //             x="\x1B[41m  \033[0m";//Germany Red
    //     break;
    //     case '8':
    //             x="\x1B[43m  \033[0m";//Italy Yellow
    //     break;
    //     case '9':
    //             x="\x1B[105m  \033[0m";//Scandenavia bright magenta
    //     break;
    //     default :
    //             x="\x1B[40m  \033[0m";//capitals black
    //     break;
    // }
    std::cout << x;
}

MapState *Map::getState()
{
    return new MapState(this);
}