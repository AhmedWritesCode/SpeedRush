#ifndef ENTITY_H
#define ENTITY_H

// Constructor

class Entity {

    protected:

    // Attributes

    int x;
    int y;
    int r;
    int color;

    public:

    // Constructor

    Entity(int _x, int _y , int _r, int _color);

    // Deconstructor

    ~ Entity();
    
};

#endif