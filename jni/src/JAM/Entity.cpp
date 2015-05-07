#include "Entity.h"

/**************************************************************************************************************/

/*Constructs an Entity object.*/
JAM_Entity::JAM_Entity(JAM_Texture* sprite, float x, float y, float width, float height)
{
	/*Initialise the variables*/
	this->sprite = sprite;
	this->position = JAM_Vec2(x, y);
	this->dimensions = JAM_Vec2(width, height);
}

/**************************************************************************************************************/

/*Destructs an Entity object.*/
JAM_Entity::~JAM_Entity()
{
}

/**************************************************************************************************************/

/*Draws the Entity to the screen.*/
void JAM_Entity::draw(SDL_Renderer* renderer)
{
	/*Push the texture to the screen*/
	sprite->pushToScreen(renderer, (int)position.x, (int)position.y, (int)dimensions.x, (int)dimensions.y);
}

/**************************************************************************************************************/

/*Sets the position of the Entity.*/
void JAM_Entity::setPosition(float x, float y)
{
	/*set the position*/
	position = JAM_Vec2(x, y);
}

/**************************************************************************************************************/

/*Sets the position of the Entity.*/
void JAM_Entity::setPosition(JAM_Vec2 position)
{
	/*set the position*/
	this->position = position;
}

/**************************************************************************************************************/

/*Sets the x position of the Entity.*/
void JAM_Entity::setX(float x)
{
	/*set the position*/
	position = JAM_Vec2(x, position.y);
}

/**************************************************************************************************************/

/*Sets the y position of the Entity.*/
void JAM_Entity::setY(float y)
{
	/*set the position*/
	position = JAM_Vec2(position.x, y);
}

/**************************************************************************************************************/

/*Sets the dimensions of the Entity*/
void JAM_Entity::setDimensions(float width, float height)
{
	/*set the dimensions*/
	dimensions = JAM_Vec2(width, height);
}

/**************************************************************************************************************/

/*Sets the dimensions of the Entity.*/
void JAM_Entity::setDimensions(JAM_Vec2 dimensions)
{
	/*set the dimensions*/
	this->dimensions = dimensions;
}

/**************************************************************************************************************/

/*Sets the width of the Entity.*/
void JAM_Entity::setWidth(float width)
{
	/*set the dimensions*/
	dimensions = JAM_Vec2(width, dimensions.y);
}

/**************************************************************************************************************/

/*Sets the height of the Entity.*/
void JAM_Entity::setHeight(float height)
{
		/*set the dimensions*/
	dimensions = JAM_Vec2(dimensions.x, height);
}

/**************************************************************************************************************/

/*Gets the position of the Entity.*/
JAM_Vec2 JAM_Entity::getPosition()
{
	/*return the position*/
	return position;
}

/**************************************************************************************************************/

/*Gets the dimensions of the Entity.*/
JAM_Vec2 JAM_Entity::getDimensions()
{
	/*return the dimensions*/
	return dimensions;
}