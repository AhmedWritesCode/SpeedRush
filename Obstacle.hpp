#ifndef Obstacle_HPP
#define Obstacle_HPP
#include <graphics.h>
#include "Entity.hpp"

class Obstacle : public Entity
{
protected:

// Attributes
    
    int speed;

    int screenHeight;

    bool collisionEnabled=true;
    
public:

// Constructor

    Obstacle(int _x, int _y, int _size, int _speed, int _color, int screenWidth);

// Destructor

    ~Obstacle();

// Other Methods
    
// Draw Methods

    void draw();

// Moving Methods

    void move();

// Accessors

    int getx()const;
    int gety()const;
    int getr()const;

// Collision Related Methods
    
    bool getcollisionEnabled();
    void setcollisionEnabled(bool state);
};

#endif