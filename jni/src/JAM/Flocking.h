#pragma once

#include <SDL.h>
#include <time.h>
#include <vector>
#include "Texture.h"
#include "Particle.h"
#include "Vec2.h"
#include "Utilities.h"

/**
@brief Creates a Flocking object.
Reference ~ This code is based upon Pseudo code from https://www.macs.hw.ac.uk/~dwcorne/Teaching/Boids%20Pseudocode.htm
*/
class JAM_Flocking
{
private:
	/**A texture of a white square*/
	JAM_Texture * whiteSquare;
	/**A vector of Particle boids*/
	std::vector<JAM_Particle*> boids;
	/**What to do with the rule (1 == possitve, 0 = neutral, -1 == negative)*/
	int applyRule1, applyRule2, applyRule3;
	int xBoundary; 
	int yBoundary;
	/**The max velocity*/
	float maxVel;
	/**The screen height*/
	int screenHeight;

	/**
	Applies Boid Rule 1.
	@param index The index of the Boid to test.
	@returns The resultant velocity of the rule.
	*/
	JAM_Vec2 rule1(int index);

	/**
	Applies Boid Rule 2.
	@param index The index of the Boid to test.
	@returns The resultant velocity of the rule.
	*/
	JAM_Vec2 rule2(int index);

	/**
	Applies Boid Rule 3.
	@param index The index of the Boid to test.
	@returns The resultant velocity of the rule.
	*/
	JAM_Vec2 rule3(int index);

	/**
	Applies Boid rough boundaries.
	@param index The index of the Boid to test.
	@returns The resultant velocity of the boundary.
	*/
	JAM_Vec2 roughBoundaries(int index);

	/**
	Limits the Boid velocity.
	@param index The index of the Boid to test.
	*/
	void limitVelocity(int index);

public:
	/**
	Constructs a Flocking object.
	@param numberOfBoids The number of boids.
	@param texture A pointer to the texture for the boids.
	@param xBoundary The rough x boundary of the boids.
	@param yBoundary The rough y boundary of the boids.
	@param maxVel The maximum velocity of the boids.
	@param screenHeight The screen height.
	*/
	JAM_Flocking(int numberOfBoids, JAM_Texture* texture, int xBoundary, int yBoundary, float maxVel, int screenHeight);

	/**
	Destructs an Flocking object.
	*/
	~JAM_Flocking();

	/**
	A function that updates the Flocking
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	Draws the Flocking.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	Setter # Set applyRule1.
	@param applyRule1 What to do with the rule (1 == possitve, 0 = neutral, -1 == negative)
	*/
	void setRule1(int applyRule1);

	/**
	Setter # Set applyRule2.
	@param applyRule2 What to do with the rule (1 == possitve, 0 = neutral, -1 == negative)
	*/
	void setRule2(int applyRule2);

	/**
	Setter # Set applyRule3.
	@param applyRule3 What to do with the rule (1 == possitve, 0 = neutral, -1 == negative)
	*/
	void setRule3(int applyRule3);
};