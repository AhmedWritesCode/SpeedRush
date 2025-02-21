#ifndef LIVES_HPP
#define LIVES_HPP


class Lives
{
private:

//Attribuites

  int lives;

public:

//Constructor

  Lives();

//Destructor

  ~ Lives();

//Accessor

  int getLives() const;

//Other Methods

  bool reducelives();
  
};

#endif