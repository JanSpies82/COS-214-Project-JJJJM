using namespace std;

#include "LocationIterator.h"
#include "Location.h"
#include <stdexcept>

LocationIterator::LocationIterator(Location *_location)
{
    current = _location;
    movRight = true;
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

    movRight = true;
}

void LocationIterator::next()
{
    if (!hasNext())
        throw out_of_range("No next location");

    if (movRight)
    {
        if (current->hasRight())
            current = current->getRight();
        else
        {
            current = current->getBottom();
            movRight = false;
        }
    }
    else
    {
        if (current->hasLeft())
            current = current->getLeft();
        else
        {
            current = current->getBottom();
            movRight = true;
        }
    }
}

bool LocationIterator::isDone()
{
    return !hasNext();
}

Location *LocationIterator::getCurrent()
{
    return current;
}

bool LocationIterator::hasNext()
{
    if (movRight)
        return current->hasRight() || current->hasBottom();
    return current->hasLeft() || current->hasBottom();
}