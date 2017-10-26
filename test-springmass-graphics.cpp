/** file: test-springmass-graphics.cpp
 ** brief: Tests the spring mass simulation with graphics
 ** author: Andrea Vedaldi
 **/

#include "graphics.h"
#include "springmass.h"

#include <iostream>
#include <sstream>
#include <iomanip>

/* ---------------------------------------------------------------- */
class SpringMassDrawable : public SpringMass, public Drawable
/* ---------------------------------------------------------------- */
{
private:
  Figure figure ;
  std::vector<Mass>::iterator massIterator;
  std::vector<Spring>::iterator springIterator;
public:
  SpringMassDrawable()
  : figure("SpringMass")
  {
    figure.addDrawable(this) ;
  }

  void draw() {
  	  
      for(massIterator = massVector.begin();massIterator != massVector.end();massIterator++) {
        figure.drawCircle(massIterator->getPosition().x,massIterator->getPosition().y,massIterator->getRadius());
        figure.drawLine(massVector[0].getPosition().x,massVector[0].getPosition().y,massVector[1].getPosition().x,massVector[1].getPosition().y,0.1);
      }
      
  }

  void display() {
    figure.update() ;
  }
} ;


int main(int argc, char** argv)
{
  glutInit(&argc,argv) ;

  SpringMassDrawable springmass;

  const double mass = 0.05 ;
  const double radius = 0.03 ;
  const double naturalLength = 0.95 ;
  const double stiffness = 0.5;
  const double damping = 0.2;

  Mass m1(Vector2(-.9,0.7), Vector2(2,1.1), mass, radius) ;
  Mass m2(Vector2(+.5,-0.3), Vector2(0.35,3), mass, radius) ;

  springmass.addMass(&m1);
  springmass.addMass(&m2);
  springmass.addSpring(&m1,&m2,naturalLength,stiffness,damping);

  run(&springmass, 1/120.0) ;
}
