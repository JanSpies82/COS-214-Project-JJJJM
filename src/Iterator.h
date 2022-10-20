#include <exception>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

class Iterator;

__abstract class Iterator
{

	public: virtual void first() = 0;

	public: virtual void next() = 0;

	public: virtual void isDone() = 0;

	public: virtual void current() = 0;
};

#endif
