using namespace std;

#include "LocationIterator.h"
#include "Location.h"
#include <stdexcept>

LocationIterator::LocationIterator(Location *_location)
{
    current = _location;
    if(current->hasRight())
        nextLocation = current->getRight();
    else if(current->hasBottom())
        nextLocation = nextRow();
}

LocationIterator::~LocationIterator()
{
}

void LocationIterator::first()
{
    while (current->hasLeft())
        current = current->getLeft();

    while (current->hasTop())
        current = current->getTop();

}

void LocationIterator::next()
{
    if (!hasNext())
        throw out_of_range("No next location");

    current = nextLocation;

    if(current->hasRight())
    {
        nextLocation=current->getRight();
    }
    else if(current->hasBottom())
    {
        nextLocation=nextRow();
    }
    
}

bool LocationIterator::isDone()
{
    return !hasNext();
}

Location* LocationIterator::getCurrent()
{
    return current;
}

bool LocationIterator::hasNext()
{
    return current->hasRight() || current->hasBottom();
}

Location* LocationIterator::nextRow(){
    Location* temp=current;

    if(temp->hasBottom())
        temp=temp->getBottom();
    else
        return temp;

    while(temp->hasLeft())
        temp=temp->getLeft();

    return temp;
    
}