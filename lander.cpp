/*********************************************************
* LANDER
* This program has the methods to the Lander.h file and
* the Lander class.These methods could not be inline
* in the class.
***********************************************************/

#include "point.h"
#include "lander.h"
#include "velocity.h"
#include "uiDraw.h"

/*********************************************************
* APPLY GRAVITY
* This method will apply gravity to the game at .3 per
* frame
*********************************************************/
void Lander::applyGravity(float gravity)
{
   if (isAlive() && !isLanded())
   {
      velocity.setDy(velocity.getDy() - gravity);
   }

}

/*********************************************************
* APPLY THRUST LEFT
* This method will move the lander to thr right when
* the left arrow is pressed.
*********************************************************/
void Lander::applyThrustLeft()
{
   if (isAlive() && !isLanded() && canThrust())
   {
      velocity.setDx(velocity.getDx() + 0.1);
      setFuel(getFuel() - 1);
   }

}

/***********************************************************
* APPLY THRUST RIGHT
* This mehod will move the lander to the left when
* The right arrow is pressed.
***********************************************************/
void Lander::applyThrustRight()
{
   if (isAlive() && !isLanded() && canThrust())
   {
      velocity.setDx(velocity.getDx() - 0.1);
      setFuel(getFuel() - 1);
   }

}

/**********************************************************
* APPLY THRUST BOTTOM
* This method will move the lander up when the down
* arrow key is pressed.
*********************************************************/
void Lander::applyThrustBottom()
{
   if (isAlive() && !isLanded() && canThrust())
   {
      velocity.setDy(velocity.getDy() + 0.3);
      setFuel(getFuel() - 1);
   }

}

/*********************************************************
* ADVANCE
* This method will make the lander advance one turn in
* the game.
***********************************************************/
void Lander::advance()
{
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
}

/***********************************************************
* DRAW
* This method will draw call the draw method so the
* lander can be drawn on the screen.
************************************************************/
void Lander::draw()
{
   if (isAlive())
   {
      drawLander(point);
   }
}

/************************************************************
* EXPLOSION
* This meathod make an explosion after the lander has crashed.
************************************************************/
void Lander::setExplosion(bool explosion)
{
   if (!isAlive() && explosion)
   {
      makeExplosion(point);
   }
}

