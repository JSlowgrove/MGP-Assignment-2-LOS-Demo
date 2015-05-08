#pragma once

#include "JAM/Entity.h"

/**
@brief Creates a MapSquare object that inherits Entity.
@author Jamie Slowgrove
*/
class MapSquare : public JAM_Entity
{
private:
	/**A Boolean for if the square is dangerous.*/
	bool danger;

public:
	/**
	Constructs the MapSquare object.
	@param sprite A pointer to the objects Texture.
	@param x The x position of the MapSquare.
	@param y The y position of the MapSquare.
	@param width The width of the MapSquare.
	@param height The height of the MapSquare.
	@param danger A Boolean for if the square is dangerous.
	*/
	MapSquare(JAM_Texture* sprite, float x, float y, float width, float height, bool danger);

	/**
	Destructs the MapSquare object.
	*/
	~MapSquare();

	/**
	A function that updates the MapSquare.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	Setter # Set the danger boolean.
	@param danger If the MapSquare is dangerous.
	*/
	void setDanger(bool danger);

	/**
	Getter # Get the danger boolean.
	@returns If the MapSquare is dangerous.
	*/
	bool getDanger();
};