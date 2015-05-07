#include "Particle.h"

/**************************************************************************************************************/

/*Constructs a Particle Object.*/
JAM_Particle::JAM_Particle(JAM_Texture* texture, float scaleValue, JAM_Vec2 direction, float moveSpeed, JAM_Vec2 position)
{
	/*initialise the variables*/
	this->texture = texture;
	this->scaleValue = scaleValue;
	this->direction = direction;
	this->moveSpeed =  moveSpeed;
	this->position = position;
}

/**************************************************************************************************************/

/*Destructs a Particle Object.*/
JAM_Particle::~JAM_Particle()
{
}

/**************************************************************************************************************/

/*update the ground*/
void JAM_Particle::update(float dt)
{
	/*update the position of the particle*/
	move(direction * moveSpeed * dt);
}

/**************************************************************************************************************/

/*Draw the Entity to the screen.*/
void JAM_Particle::draw(SDL_Renderer* renderer)
{
	/*draw the texture to the screen*/
	texture->pushToScreen(renderer, (int)position.x, (int)position.y, (int)scaleValue, (int)scaleValue);
}

/**************************************************************************************************************/

/*Sets the position of the Entity.*/
void JAM_Particle::setPosition(JAM_Vec2 position)
{
	/*set the position*/
	this->position = position;
}

/**************************************************************************************************************/

/*Sets the position of the Entity.*/
void JAM_Particle::setPosition(float x, float y)
{
	/*set the x position*/
	position.x = x;
	/*set the y position*/
	position.y = y;
}

/**************************************************************************************************************/

/*Sets the scale of the Entity.*/
void JAM_Particle::setScale(float scaleValue)
{
	/*set the scale*/
	this->scaleValue = scaleValue;
}

/**************************************************************************************************************/

/*Move the Entity.*/
void JAM_Particle::move(JAM_Vec2 movement)
{
	/*update the position*/
	position += movement;
}

/**************************************************************************************************************/

/*Move the Entity along the X axis.*/
void JAM_Particle::moveX(float movement)
{
	/*update the position*/
	position.x += movement;
}

/**************************************************************************************************************/

/*Move the Entity along the Y axis.*/
void JAM_Particle::moveY(float movement)
{
	/*update the position*/
	position.y += movement;
}

/**************************************************************************************************************/

/*Update the movement speed to the new moveSpeed.*/
void JAM_Particle::setMoveSpeed(float moveSpeed)
{
	/*set the move speed*/
	this->moveSpeed = moveSpeed;
}

/**************************************************************************************************************/

/*Set the direction.*/
void JAM_Particle::setDirection(JAM_Vec2 direction)
{
	/*update the direction*/
	this->direction = direction;
}

/**************************************************************************************************************/

/*get the movement speed.*/
float JAM_Particle::getMoveSpeed()
{
	/*return the move speed*/
	return moveSpeed;
}

/**************************************************************************************************************/

/*Get the position.*/
JAM_Vec2 JAM_Particle::getPosition()
{
	/*return the position*/
	return position;
}

/**************************************************************************************************************/

/*Get the direction.*/
JAM_Vec2 JAM_Particle::getDirection()
{
	/*return the direction*/
	return direction;
}

/**************************************************************************************************************/

/*Get the scale.*/
float JAM_Particle::getScale()
{
	/*return the scale*/
	return scaleValue;
}