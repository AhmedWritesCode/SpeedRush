#include "Car.hpp"
#include "Obstacle.hpp"
#include <conio.h>
#include <graphics.h>
#include "Entity.hpp"

//Constructor

Car::Car(int _x, int _y, int _r ,int _step, int _color,int screenWidth) : Entity (_x ,_y , _r ,_color )
{
    step = _step;
}

//Deconstructor

Car :: ~ Car (){}

// Accessors

int Car::getx()const{return x;}
int Car::gety()const{return y;}
int Car::getr()const{return r;}

//Other Methods

//Draw Method

void Car::draw ()
{
    setcolor(color);
    setfillstyle(SOLID_FILL,color);
    circle(x,y,r);
    floodfill(x,y,color);
}

// Moving Methods

void Car::moveLeft(int limit)
{
    x-=step;
    if(x<=limit)
    {
        x=limit;
    }
    
}
void Car::moveRight(int limit)
{
    x+=step;
    if(x>=limit)
    {
        x=limit;
    }
}

// Collision Related Methods

bool Car::isAlive() const
{
    return lives.getLives()>0;
}
bool Car::wasHit()
{
    return lives.reducelives();
}

// Score Related Methods

void Car::scoreUpdate()
{
    return score.update();
}
int Car::getScore()
{
    return score.getScore();
}

// Lives Related Methods

int Car :: getLives() const{

    return lives.getLives();
}