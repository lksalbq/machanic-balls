/** file: test-ball.cpp
 ** brief: Tests the bouncing ball simulation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

int main(int argc, char** argv)
{
  Ball ball ;
  const double dt = 1.0/100 ;
  for (int i = 0 ; i < 10000 ; ++i) {
    ball.step(dt) ;
    ball.display() ;
  }
  return 0 ;
}
