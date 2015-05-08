#pragma once

#include <SDL.h>
#include <string.h>
#include "Texture.h"
#include "Button.h"

/**
@brief Creates an ArrowPad object.
@author Jamie Slowgrove
*/
class JAM_ArrowPad
{
private:
	/**An up Button.*/
	JAM_Button* up;
	/**An down Button.*/
	JAM_Button* down;
	/**An left Button.*/
	JAM_Button* left;
	/**An right Button.*/
	JAM_Button* right;
	/**The commands for the user.*/
	bool upCmd, downCmd, leftCmd, rightCmd;

public:
	/**
	Constructs the Button object.
	@param x The x position of the Button.
	@param y The y position of the Button.
	@param width The width of the Button.
	@param height The height of the Button.
	@param renderer A pointer to the SDL Renderer.
	*/
	JAM_ArrowPad(float x, float y, float width, float height, SDL_Renderer* renderer);

	/**
	Destructs the ArrowPad object.
	*/
	~JAM_ArrowPad();

	/**
	A function that updates the ArrowPad.
	@param incomingEvent A reference to the incoming event.
	*/
	void input(SDL_Event& incomingEvent);

	/**
	Draws the ArrowPad to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	Getter # Gets the value of the up command.
	@returns The value of the up command.
	*/
	bool getUp();

	/**
	Getter # Gets the value of the down command.
	@returns The value of the down command.
	*/
	bool getDown();

	/**
	Getter # Gets the value of the left command.
	@returns The value of the left command.
	*/
	bool getLeft();

	/**
	Getter # Gets the value of the right command.
	@returns The value of the right command.
	*/
	bool getRight();
};