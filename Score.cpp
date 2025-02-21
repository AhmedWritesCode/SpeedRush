#include "Score.hpp"
#include <iostream>
#include <graphics.h>
#include <chrono>

// Constructor 


Score::Score()
{
  score=0;
  start = std::chrono::system_clock::now();
}

// Deconstructor

Score :: ~ Score(){}

// Accessor

int Score::getScore(){

  return score;}   


// Other Methods
void Score::update()
{
  //assigns the current time to the current variable, capturing the current point in time.
  std::chrono::time_point<std::chrono::system_clock> current = std::chrono::system_clock::now();
  //assigns the calculated duration to the elapsed_seconds variable.
  std::chrono::duration<double> elapsed_seconds = current - start;
  //assigns the converted int value to the score variable, updating the score.
  score = (int)elapsed_seconds.count();
}


    //In summary, these lines of code calculate the elapsed time 
    // between the start time point and the current time point, 
    // represented as a chrono::duration. The duration is then 
    // converted to seconds and stored as an int value in the score 
    // variable, allowing it to be used for score calculations.