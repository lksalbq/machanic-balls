/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

Mass::Mass()
: position(), velocity(), force(), mass(1), radius(1)
{ }

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
: position(position), velocity(velocity), force(), mass(mass), radius(radius),
xmin(-1),xmax(1),ymin(-1),ymax(1)
{ }

void Mass::setForce(Vector2 f)
{
  force = f ;
}

void Mass::addForce(Vector2 f)
{
  force = force + f ;
}

Vector2 Mass::getForce() const
{
  return force ;
}

Vector2 Mass::getPosition() const
{
  return position ;
}

Vector2 Mass::getVelocity() const
{
  return velocity ;
}

double Mass::getRadius() const
{
  return radius ;
}

double Mass::getMass() const
{
  return mass ;
}

double Mass::getEnergy(double gravity) const
{
  double energy = 0 ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Este metodo calcula a energia esta massa, indepentente
     de outras massas ou molas do sistema, ou seja, 
     energia potencial + energia cinetica, onde:
     E_cinetica = (massa * |velocidate|^2)/2
     E_potencial = mass * gravidade * altura.
     Note que o calculo da altura deve levar o raio
     da bola em conta, pois as coordenadas da bola sao dadas
     com relacao a seu centro, e nao ao ponto de impacto com 
     o solo.
   */

  return energy ;
}

void Mass::step(double dt)
{
  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Este eh o metodo mais complexo, ele atualiza 
     - a posicao e 
     - a velocidade desta massa 
     usando a 
     - forca que eh aplicada `a massa (armazenada em
       atributo protegido) e 
     - a fracao de tempo (dt).
     Isso eh feito atravez da aplicacao de equacoes 
     basicas de mecanica. 
     1. Calcule a aceleracao:
        F = m*a  ->  a = m/F
     2. Atualize a posicao:
        S = S0 + V*dt + (a*dt^2)/2 
     3. Atualize a velocidade:
        V = V0 + a*dt
     Note que nos passos 2 e 3, eh necessario tratar
     de colisoes com as paredes da caixa. Para isso,
     eh melhor separar os calculos de componentes
     x e y da velocidade e da posicao.
   */
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2),
naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{ }

Mass * Spring::getMass1() const
{
  return mass1 ;
}

Mass * Spring::getMass2() const
{
  return mass2 ;
}

Vector2 Spring::getForce() const
{
  Vector2 F ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Este metodo calcula a forca desta mola usando as equacoes
     para oscilador harmonico amortecido 
     https://en.wikipedia.org/wiki/Harmonic_oscillator#Damped_harmonic_oscillator
     ou seja:
     F = -K*x - c*v, onde:
       K: coeficiente elastico da mola (stiffness),
       x: o vetor que leva da posicao atual da mola ate 
          a posicao de repouso.
       c: coeficiente de amortecimento (damping)
       v: vetor de velocidade da mola.

     Procedimento:
     1. Calcule o vetor u da distancia entre as 
        duas extremidades da mola. 
	Dica: use subtracao de Vector2, i.e., operator-()
     2. Calcule o comprimento atual da mola. 
        Dica: use o metodo norm().
     3. Calcule o vetor unitario da direcao da mola, i.e.
        o resultado de (1) dividido pelo resultado de (2).
     4. Calcule o vetor da velocidade de alongamento entre 
        as duas massas, i.e., o produto interno (dot()) entre
	v2-v1 e o vetor unitario da direcao da mola 
	(resultado de 3).
     5. O modulo da forca eh entao calculado por:
          (comprimento_da_mola_em_repouso - comprimento_atual)*stiffness + 
          velocidada_de_alongamento * damping 
     6. O vetor da forca eh entao calculado pelo resultado
        de (5) multiplicado pelo vetor de direcao da mola (3).	
   */

  return F ;
}

double Spring::getLength() const
{
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  return u.norm() ;
}

double Spring::getEnergy() const {
  double length = getLength() ;
  double dl = length - naturalLength;
  return 0.5 * stiffness * dl * dl ;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
  os<<"("
  <<m.getPosition().x<<","
  <<m.getPosition().y<<")" ;
  return os ;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
  return os<<"$"<<s.getLength() ;
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

SpringMass::SpringMass(double gravity)
: gravity(gravity)
{ }

void SpringMass::display()
{

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Implemente usando dois loops:
     1. imprima todas as massas
     2. imprima todas as molas
     Note que voce pode ousar o operador << diretamente
     para massas e molas, pois eles foram definidos acima.
     Posteriormente, imprima a energia total do sistema.     
   */
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     A energia total do sistema eh
     a soma das energias de todas as massas 
     + a soma das energias de todas as molas.
   */

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ; // Vetor da gravidade, i.e.,
  // aceleracao apontando para baixo.
  
  /* INCOMPLETE: TYPE YOUR CODE HERE 
     1. para cada massa,
        atualize sua forca usando m*g, i.e.
	masses[i].setForce(g * masses[i].getMass()) 
     2. para cada mola, obtenha a forca da mola e 
        adicione-a a cada massa ligada a esta mola, i.e.,
	springs[i].getMass1()->addForce(-1 * force) ;
	springs[i].getMass2()->addForce(+1 * force) ;     
     3. Atualize a posicao e velocidade de todas as massas,
        i.e., execute o metodo step() delas.
   */
}


/* INCOMPLETE: TYPE YOUR CODE HERE 

   Neste ponto, insira os metodos que estao faltando:
   um para adicionar uma massa e outro para adicionar uma mola
   no sistema.
   Para adicionar elementos numa estrutura do tipo vector,
   use o metodo push_back().
   O metodo de adicionar massa pode retornar o numero total
   de massas, i.e., return (int)masses.size() -1;
   O metodo de adicionar mola deve usar referencias 
   aos indices do vector de massas para cada extremidade 
   e o construtor de mola.
 */


