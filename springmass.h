/** file: springmass.h
 ** brief: SpringMass simulation
 ** author: Andrea Vedaldi
 **/

#ifndef __springmass__
#define __springmass__

#include "simulation.h"

#include <cmath>
#include <vector>

#define MOON_GRAVITY 1.62
#define EARTH_GRAVITY 9.82

/* ---------------------------------------------------------------- */
// class Vector2
/* ---------------------------------------------------------------- */

class Vector2
{
public:
  double x ;
  double y ;

  Vector2() : x(0), y(0) { }
  Vector2(double _x, double _y) : x(_x), y(_y) { }
  double norm2() const { return x*x + y*y ; }
  double norm() const { return std::sqrt(norm2()) ; }
} ;

inline Vector2 operator+ (Vector2 a, Vector2 b) { return Vector2(a.x+b.x, a.y+b.y) ; }
inline Vector2 operator- (Vector2 a, Vector2 b) { return Vector2(a.x-b.x, a.y-b.y) ; }
inline Vector2 operator* (double a, Vector2 b)  { return Vector2(a*b.x, a*b.y) ; }
inline Vector2 operator* (Vector2 a, double b)  { return Vector2(a.x*b, a.y*b) ; }
inline Vector2 operator/ (Vector2 a, double b)  { return Vector2(a.x/b, a.y/b) ; }
inline double dot(Vector2 a, Vector2 b) { return a.x*b.x + a.y*b.y ; }

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

class Mass
{
public:
  Mass() ;
  Mass(Vector2 position, Vector2 velocity, double mass, double radius) ;
  void setForce(Vector2 f) ;
  void addForce(Vector2 f) ;
  Vector2 getForce() const ;
  Vector2 getPosition() const ;
  Vector2 getVelocity() const ;
  double getMass() const ;
  double getRadius() const ;
  double getEnergy(double gravity) const ;
  void step(double dt) ;

protected:
  Vector2 position ; 
  Vector2 velocity ;
  Vector2 force ;
  double mass ;
  double radius ; // Assume-se que as massas sao esferas.

  double xmin ; // Limites, i.e., dimensoes da caixa onde o sistema se encontra,
  double xmax ; // onde x sao dimensoes horizontais e
  double ymin ; // y sao dimensoes verticais.
  double ymax ;
} ;

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

class Spring
{
public:
  Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping = 0.01) ;
  Mass * getMass1() const ;
  Mass * getMass2() const ;
  Vector2 getForce() const ;
  double getLength() const ;
  double getEnergy() const ;

protected:
  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Insira atributos protegidos que permitem calcular a forca 
     e a energia de uma mola. Dica: veja o construtor acima.
     Adicione tambem 2 ponteiros para objetos do tipo Mass 
     (um para cada extremidade da mola).
   */
} ;

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

class SpringMass : public Simulation
{
public:
  SpringMass(double gravity = MOON_GRAVITY) ;
  void step(double dt) ;
  void display() ;
  double getEnergy() const ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Adicione dois metodos que permitem construir o sistema,
     - um para adicionar uma massa, que teria como entrada
       um objeto da classe Mass, e
     - outro para adicionar uma mola, que teria como entrada
       - dois indices (um para cada massa que sera 
         conectada a esta mola);
       - os outros parametros necessarios para se "construir"
         uma mola.       
   */

protected:
  double gravity ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Defina dois tipos de vetores, 
     - um para massas e 
     - outro para molas.
     Para definir vetores de tipos, use:
     typedef std::vector<NomeDaClasse> nome_do_tipo_t;
     Adicione, como atributo:
     - um vetor de massas e
     - um vetor de molas.
     Total de codigo para esta lacuna: 4 linhas
   */

} ;

#endif /* defined(__springmass__) */

