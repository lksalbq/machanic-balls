/** file: test-srpingmass.cpp
 ** brief: Tests the spring mass simulation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

int main(int argc, char** argv)
{
  SpringMass springmass ;

  const double mass = 0.05 ;
  const double radius = 0.02 ;
  const double naturalLength = 0.95 ;
  const double stiffness = 0.5;
  const double damping = 0.6;

  Mass m1(Vector2(-.9,0.4), Vector2(4,2), mass, radius) ;
  Mass m2(Vector2(+.5,-0.1), Vector2(2.35,3), mass, radius) ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     1. Adicione as duas massas instanciadas acima (2 linhas).
     2. Adicione uma mola com as duas massas (indexadas por 0 e 1),
        e com o parametro de comprimento em repouso inicializado acima.
	(1 linha).
   */

  springmass.addMass(&m1);
  springmass.addMass(&m2);
  springmass.addSpring(&m1,&m2,naturalLength,stiffness,damping);

  const double dt = 1.0/30 ;
  for (int i = 0 ; i < 100 ; ++i) {
    springmass.step(dt) ;
    springmass.display() ;
  }

  return 0 ;
}
