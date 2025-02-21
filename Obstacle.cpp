#include "Obstacle.hpp"
#include <graphics.h>
#include "Entity.hpp"

// Accessors

int Obstacle::getx()const{return x;}
int Obstacle::gety()const{return y;}
int Obstacle::getr()const{return r;}

// Collision Related Methods

bool Obstacle::getcollisionEnabled(){return collisionEnabled;}
void Obstacle::setcollisionEnabled(bool state)
{
    collisionEnabled=state;
}

// Constructor

Obstacle::Obstacle(int _x, int _y, int _r, int _speed, int _color, int _screenHeigh) : Entity (_x ,_y , _r ,_color  )
{
   
    speed = _speed;
    screenHeight = _screenHeigh;
}

// Destructor

Obstacle :: ~ Obstacle (){}
void Obstacle::draw()
{
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    readimagefile("Obstacle.jpg",x+50,y+50,x-50,y-50);
    circle(x, y, r);
    floodfill(x, y, color);
    // putimage(x+50,y+50,image, XOR_PUT)

};

//Moving Methods

void Obstacle::move()
{
    if (y + r > screenHeight)
    {
        y = 0;
    }
    else
    {
        y += speed;
    }
}