
#ifndef __Military_h__
#define __Military_h__

#include <vector>

class VehicleFactory;
class Plane;
class Ship;
class Tank;
class Battalion;
class Country;


class Military
{
public:
  Military();
  Military(Military*);
  ~Military();
  void attack(Country*);

};

#endif
