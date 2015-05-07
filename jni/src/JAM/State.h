#pragma once

#include <SDL.h>
#include <string.h>

/**Forward declaration of StateManager for the pointer to the StateManager*/
class JAM_StateManager;

/**
@brief Creates a State object.
Creates a State object to be inherited.
Reference ~ This is a modified version of my PGG Assignment 1 State class.
*/
class JAM_State
{
protected:
	/**A pointer to the state manager*/
	JAM_StateManager* stateManager;
	/**The render to display to*/
	SDL_Renderer* renderer;
	/**The width of the screen*/
	int screenWidth;
	/**The height of the screen*/
	int screenHeight;

public:
	/**
	Constructs a State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer in use.
	@param screenWidth The screen width.
	@param screenHeight The screen height.
	*/
	JAM_State(JAM_StateManager* stateManager, SDL_Renderer* renderer, int screenWidth, int screenHeight);

	/**
	A virtual destructor for the State object.
	*/
	virtual ~JAM_State();

	/**
	A pure virtual function to handle the user input for use with the State.
	@returns If false then quit State.
	*/
	virtual bool input() = 0;

	/**
	A pure virtual function to update the State to allow the State to run.
	@param dt The delta time.
	*/
	virtual void update(float deltaTime) = 0;

	/**
	A pure virtual function to draw to the screen using the renderer.
	*/
	virtual void draw() = 0;
};