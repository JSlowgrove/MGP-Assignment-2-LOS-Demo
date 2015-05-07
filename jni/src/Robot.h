#pragma once

#include "JAM/Entity.h"

/**
@brief Creates a Robot object that inherits Entity.
*/
class Robot : public JAM_Entity
{
private:
public:
	/**
	Constructs a Robot object.
	@param sprite A pointer to the objects Texture.
	@param x The x position of the Robot.
	@param y The y position of the Robot.
	@param width The width of the Robot.
	@param height The height of the Robot.
	*/
	Robot(JAM_Texture* sprite, float x, float y, float width, float height);

	/**
	Destructs a Robot object.
	*/
	~Robot();

	/**
	A function that updates the Robot.
	@param dt The delta time.
	*/
	void update(float dt);
};