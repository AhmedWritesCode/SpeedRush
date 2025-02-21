
#ifndef Score_HPP
#define Score_HPP
#include <chrono>

class Score {

private:

  // Attributes

  int score;
  std::chrono::time_point<std::chrono::system_clock> start;

public:

  // Constructor 
  
  Score();

  // Deconstructor

  ~ Score();

  // Accessor
  int getScore();

  // Other Methods

  void update();

};

#endif
