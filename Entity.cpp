#include "Entity.hpp"

// Constructor

Entity :: Entity(int _x, int _y , int _r, int _color)
{
     x = _x;
     y = _y;
     r = _r;
     color = _color;
}

// Deconstructor

Entity :: ~ Entity () {}