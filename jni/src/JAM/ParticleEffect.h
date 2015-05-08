#pragma once

#include <SDL.h>
#include <vector>
#include <time.h>
#include <string>
#include "Particle.h"
#include "Vec2.h"
#include "Utilities.h"

/**A definition for the max number of particles.*/
#define MAX_NUMBER_OF_PARTICLES 100

/**
@brief Creates a ParticleEffect object that handles Particle objects.
@author Jamie Slowgrove
Reference ~ This is a modified version of my PGG Assignment 2 Particle Effect class.
*/
class JAM_ParticleEffect
{
private:
	/**A vector of Particle objects.*/
	std::vector<JAM_Particle*> particles;
	/**A pointer to the Texture of the particles.*/
	JAM_Texture* texture;
	/**The move speed of the particles.*/
	float moveSpeed;
	/**The position of the Particle emitter.*/
	JAM_Vec2 emitter;
	/**A boolean for if the ParticleEffect should emit.*/
	bool emit;
	/**The screen height.*/
	int screenHeight;

	/**
	Creates the new Particle objects.
	*/
	void makeNewParticles();

public:
	/**
	Constructs the ParticleEffect Object.
	@param objectName The file name of the texture that the Particle will use.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param renderer A pointer to the renderer.
	@param screenHeight The screen height.
	*/
	JAM_ParticleEffect(std::string fileName, JAM_Vec2 emitter, bool emit, SDL_Renderer* renderer, int screenHeight);

	/**
	Constructs the ParticleEffect Object.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param renderer A pointer to the renderer.
	@param r The red value (0-255).
	@param g The green value (0-255).
	@param b The blue value (0-255).
	@param screenHeight The screen height.
	*/
	JAM_ParticleEffect(JAM_Vec2 emitter, bool emit, SDL_Renderer* renderer, int r, int g, int b, int screenHeight);

	/**
	Destructs the ParticleEffect Object deleting the Particle Object from memory.
	*/
	~JAM_ParticleEffect();

	/**
	A function that updates the ParticleEffect
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	Draws the ParticleEffect.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	Setter # The position of the emitter.
	@param emitter The new position of the emitter.
	*/
	void setEmitter(JAM_Vec2 emitter);

	/**
	Setter # The value of the emit boolean.
	@param emit The new value of the emit boolean.
	*/
	void setEmitting(bool emit);
};
