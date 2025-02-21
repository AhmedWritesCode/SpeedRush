#ifndef Car_HPP
#define Car_HPP
#include "lives.hpp"
#include "Score.hpp"
#include "Score.hpp"
#include <graphics.h>
#include "Entity.hpp"

class Car : public Entity
{
private :

    // Attributes

    int step;
    int screenWidth;

    Lives lives;
    Score score;
    
public :

    // Constructor

    Car(int _x, int _y , int _r,int _step, int _color,int _screenWidth);

    // Destructor

    ~Car ();

    // Accessors
    
    int getx()const;
    int gety()const;
    int getr()const;

    //Other Methods

    // Draw Methods

    void draw();

    // Moving Methods

    void moveLeft( int limit);
    void moveRight(int limit);

    //Collision Related Methods

    bool isAlive() const;
    bool wasHit();

    //Score Related Methods

    void scoreUpdate();
    int getScore();

    // Lives Related Methods

    int getLives() const;


};

#endif