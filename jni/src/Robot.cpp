#include "Robot.h"

/**************************************************************************************************************/

/*Constructs an Robot object.*/
Robot::Robot(JAM_Texture* sprite, float x, float y, float width, float height)
	: JAM_Entity(sprite, x, y, width, height)
{
}

/**************************************************************************************************************/

/*Destructs a Robot object.*/
Robot::~Robot()
{
}

/**************************************************************************************************************/

/*Updates the Robot object.*/
void Robot::update(float dt)
{
}