#pragma once

#include <SDL.h>
#include "Vec2.h"
#include "Texture.h"

/**
@brief Creates a Particle object.
@author Jamie Slowgrove
Reference ~ This is a modified version of my PGG Assignment 2 Particle class.
*/
class JAM_Particle
{
private:
	/**A pointer to the Texture.*/
	JAM_Texture* texture;
	/**The direction of the Particle.*/
	JAM_Vec2 direction;
	/**The Position of the Particle.*/
	JAM_Vec2 position;
	/**The scale of the Particle.*/
	float scaleValue;
	/**The movement speed of the Particle.*/
	float moveSpeed;

public:
	/**
	Constructs the Particle Object.
	@param square A pointer to the Texture.
	@param scaleValue The scale of the Particle.
	@param direction The direction of the Particle.
	@param moveSpeed The move speed of the Particle.
	@param position The position of the Particle.
	*/
	JAM_Particle(JAM_Texture* texture, float scaleValue, JAM_Vec2 direction, float moveSpeed, JAM_Vec2 position);

	/**
	Destructs the Particle Object deleting the Particle Object from memory.
	*/
	~JAM_Particle();

	/**
	A function that updates the Particle.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	Draw the Entity to the screen.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	Setter # Sets the position of the Particle.
	@param position The new position.
	*/
	void setPosition(JAM_Vec2 position);

	/**
	Setter # Sets the position of the Particle.
	@param x The X position.
	@param y The Y position.
	*/
	void setPosition(float x, float y);

	/**
	Setter # Sets the scale of the Particle.
	@param scaleValue The new scale.
	*/
	void setScale(float scaleValue);

	/**
	Move the Particle.
	@param movement The amount to move by.
	*/
	void move(JAM_Vec2 movement);

	/**
	Move the Particle along the X axis.
	@param movement The amount to move by.
	*/
	void moveX(float movement);

	/**
	Move the Particle along the Y axis.
	@param movement The amount to move by.
	*/
	void moveY(float movement);

	/**
	Setter # Sets the moveSpeed of the Particle.
	@param moveSpeed The new moveSpeed.
	*/
	void setMoveSpeed(float moveSpeed);

	/**
	Setter # Sets the direction of the Particle.
	@param direction The new direction.
	*/
	void setDirection(JAM_Vec2 direction);

	/**
	Getter # Gets the moveSpeed of the Particle.
	@returns The moveSpeed.
	*/
	float getMoveSpeed();

	/**
	Getter # Gets the position of the Particle.
	@returns The position of the Particle.
	*/
	JAM_Vec2 getPosition();

	/**
	Getter # Gets the direction of the Particle.
	@returns The direction of the Particle.
	*/
	JAM_Vec2 getDirection();

	/**
	Getter # Gets the scale of the Particle.
	@returns The scale of the Particle.
	*/
	float getScale();
};
