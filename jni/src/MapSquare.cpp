#include "MapSquare.h"

/**************************************************************************************************************/

/*Constructs an MapSquare object.*/
MapSquare::MapSquare(JAM_Texture* sprite, float x, float y, float width, float height, bool danger)
	: JAM_Entity(sprite, x, y, width, height)
{
	/*initialise the variables*/
	this->danger = danger;
}

/**************************************************************************************************************/

/*Destructs an MapSquare object.*/
MapSquare::~MapSquare()
{
}

/**************************************************************************************************************/

/*Updates the MapSquare object.*/
void MapSquare::update(float dt)
{
}

/**************************************************************************************************************/

/*Set the danger boolean.*/
void MapSquare::setDanger(bool danger)
{
	/*set the variable*/
	this->danger = danger;
}

/**************************************************************************************************************/

/*Get the danger boolean.*/
bool MapSquare::getDanger()
{
	/*return the variable*/
	return danger;
}