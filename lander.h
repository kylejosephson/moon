#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

#define START_FUEL 500

/********************************************************
* CLASS LANDER
* This class builds the lander and all its functions
*******************************************************/
class Lander
{
private:
   Point point;
   Velocity velocity;
   bool alive;
   bool landed;
   int fuel;
   bool cThrust;
   bool explosion;

public:
   Lander()
   {
      point = 0, 0;
      alive = true;
      landed = false;
      fuel = START_FUEL;
      cThrust = true;
      explosion = false;
   }
   Point getPoint() const { return point; }
   Velocity getVelocity() const { return velocity; }
   bool isAlive() const { return alive; }
   bool isLanded() const { return landed; }
   int getFuel() const { return fuel; }
   bool canThrust() const { return cThrust; }
   void setLanded(bool landed) { this->landed = landed; }
   void setAlive(bool alive) { this->alive = alive; }
   void setFuel(int fuel) { this->fuel = fuel; }
   void applyGravity(float gravity);
   void setExplosion(bool explosion);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void draw();
};

#endif

