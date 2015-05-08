#pragma once

#include "Texture.h"
#include "Vec2.h"

/**
@brief Creates an Entity object.
@author Jamie Slowgrove
*/
class JAM_Entity
{
private:
	/**A pointer to the objects Texture.*/
	JAM_Texture* sprite;
	/**The position of the Entity.*/
	JAM_Vec2 position;
	/**The dimensions of the Entity.*/
	JAM_Vec2 dimensions;

public:
	/**
	Constructs the Entity object.
	@param sprite A pointer to the objects Texture.
	@param x The x position of the Entity.
	@param y The y position of the Entity.
	@param width The width of the Entity.
	@param height The height of the Entity.
	*/
	JAM_Entity(JAM_Texture* sprite, float x, float y, float width, float height);

	/**
	Destructs the Entity object.
	*/
	~JAM_Entity();

	/**
	A pure virtual function that updates the Entity.
	@param dt The delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	Draws the Entity to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	Setter # Sets the position of the Entity.
	@param x The new x position of the Entity.
	@param y The new y position of the Entity.
	*/
	void setPosition(float x, float y);

	/**
	Setter # Sets the position of the Entity.
	@param position The new position of the Entity.
	*/
	void setPosition(JAM_Vec2 position);

	/**
	Setter # Sets the x position of the Entity.
	@param x The x position of the Entity.
	*/
	void setX(float x);

	/**
	Setter # Sets the y position of the Entity.
	@param y The y position of the Entity.
	*/
	void setY(float y);

	/**
	Setter # Sets the dimensions of the Entity.
	@param width The new width of the Entity.
	@param height The new height of the Entity.
	*/
	void setDimensions(float width, float height);

	/**
	Setter # Sets the dimensions of the Entity.
	@param dimensions The new dimensions of the Entity.
	*/
	void setDimensions(JAM_Vec2 dimensions);

	/**
	Setter # Sets the width of the Entity.
	@param width The new width of the Entity.
	*/
	void setWidth(float width);

	/**
	Setter # Sets the height of the Entity.
	@param height The new height of the Entity.
	*/
	void setHeight(float height);

	/**
	Getter # Gets the position of the Entity.
	@returns The position of the Entity.
	*/
	JAM_Vec2 getPosition();

	/**
	Getter # Gets the dimensions of the Entity.
	@returns The dimensions of the Entity.
	*/
	JAM_Vec2 getDimensions();
};