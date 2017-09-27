/** file: test-ball.cpp
 ** brief: Tests the bouncing ball simulation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"
#include <iostream>

int main(int argc, char** argv)
{
  Ball ball;  

  const double dt = 1.0/100 ;
  for (int i = 0 ; i < 100 ; ++i) {
    ball.step(dt) ;
    ball.display() ;
    std::cout << "Velocidade x:"<< ball.getVelocityVx()<<std::endl;
    std::cout << "Velocidade y:"<< ball.getVelocityVy()<<std::endl;
  }
  Ball ball1 ;


  ball1.setPosition(1.0,0.5);
  
  std::cout<<"Ball1 getPositionX: "<<ball1.getPositionX()<<std::endl ;
  std::cout<<"Ball1 getPositionY: "<<ball1.getPositionY()<<std::endl ;
  
  //usando o construtor que inicializa o objeto ball com posição pre-definida
  Ball ball2(0.1, 0.6);
  
  std::cout<<"Ball2 getPositionX: "<<ball2.getPositionX()<<std::endl ;
  std::cout<<"Ball2 getPositionY: "<<ball2.getPositionY()<<std::endl ;
  return 0 ;
}
