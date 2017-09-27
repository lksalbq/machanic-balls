/** file: ball.cpp
 ** brief: Ball class - implementation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

#include <iostream>

Ball::Ball()
: r(0.1), x(0), y(0), vx(0.3), vy(-0.1), g(9.8), m(1),
xmin(-1), xmax(1), ymin(-1), ymax(1)
{ }

//construtor que seta a posicao x,y
Ball::Ball(double x, double y)
{
  this->setPosition(x,y);
}

//construtor que seta a posicao x,y e velocidade vx,vy
Ball::Ball(double x, double y,double vx, double vy)
{
  this->setPosition(x,y);
  this->setVelocity(vx,vy);
}

//metodo que seta a posicao x,y
void Ball::setPosition(double x, double y)
{
  this->x = x;
  this->y = y;
}

//metodo que seta a posicao x
void Ball::setPositionX(double x)
{
  this->x = x;
}

//metodo que seta a posicao y
void Ball::setPositionY(double y)
{
  this->y = y;
}
//metodo que seta a velocidade vx,vy
void Ball::setVelocity(double vx, double vy)
{
  this->vx = vx;
  this->vy = vy;
}

//metodo que seta a velocidade vx
void Ball::setVelocityVx(double vx)
{
  this->vx = vx;
}

//metodo que seta a velocidade vy
void Ball::setVelocityVy(double vy)
{
  this->vy = vy;
}

//metodo que retorna a posicao x
double Ball::getPositionX()
{
  return this->x;
}

//metodo que retorna a posicao y
double Ball::getPositionY()
{
  return this->y;
}

//metodo qu e retorna a velocidade vx
double Ball::getVelocityVx()
{
  return this->vx;
}

//metodo que retorna a velocidade vy
double Ball::getVelocityVy()
{
  return this->vy;
}

//step
void Ball::step(double dt)
{
  double xp = x + vx * dt ;
  double yp = y + vy * dt - 0.5 * g * dt * dt ;
  if (xmin + r <= xp && xp <= xmax - r) {
    x = xp ;
  } else {
    vx = -vx ;
  }
  if (ymin + r <= yp && yp <= ymax - r) {
    y = yp ;
    vy = vy - g * dt ;
  } else {
    vy = -vy ;
  }
}

void Ball::display()
{
  std::cout<<x<<" "<<y<<std::endl ;
}
