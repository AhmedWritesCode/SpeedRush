#include "lives.hpp"

//Constructor

Lives::Lives()
{
  lives = 3;
}

//Destructor

 Lives :: ~ Lives(){}

//Accessor

int Lives::getLives() const
{
  return lives;
}

//Other Methods

bool Lives::reducelives()
{
  if(lives>0)
    {
      lives--;
      return true;
    }
  return false;
}