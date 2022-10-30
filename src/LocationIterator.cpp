using namespace std;

#include "LocationIterator.h"
#include "Location.h"
#include <stdexcept>

LocationIterator::LocationIterator(Location *_location)
{
    current = _location;
    movRight = true;
    if (hasNext())
    {
        if (movRight)
        {
            if (current->hasRight())
                nextLocation = current->getRight();
            else
                nextLocation = current->getBottom();
        }
        else
        {
            if (current->hasLeft())
                nextLocation = current->getLeft();
            else
                nextLocation = current->getBottom();
        }
    }
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

    current = nextLocation;

    if (hasNext())
    {
        if (movRight)
        {
            if (current->hasRight())
                nextLocation = current->getRight();
            else
            {
                nextLocation = current->getBottom();
                movRight = false;
            }
        }
        else
        {
            if (current->hasLeft())
                nextLocation = current->getLeft();
            else
            {
                nextLocation = current->getBottom();
                movRight = true;
            }
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