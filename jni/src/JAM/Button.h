#pragma once

#include <string>
#include "Entity.h"
#include "Text.h"

/**
@brief Creates an Button object that inherits Entity.
*/
class JAM_Button : public JAM_Entity
{
private:
	/**The text of the button*/
	JAM_Text* text;
	/**The size of the border from the button and the text*/
	float border;

public:
	/**
	Constructs a Button object.
	@param sprite A pointer to the objects Texture.
	@param x The x position of the Button.
	@param y The y position of the Button.
	@param width The width of the Button.
	@param height The height of the Button.
	*/
	JAM_Button(JAM_Texture* sprite, float x, float y, float width, float height);

	/**
	Constructs a Button object.
	@param sprite A pointer to the objects Texture.
	@param x The x position of the Button.
	@param y The y position of the Button.
	@param message The text of the Button.
	@param fontLocation The location of the font.
	@param r The blue of the Button font colour.
	@param g The blue of the Button font colour.
	@param b The blue of the Button font colour.
	@param renderer A pointer to the renderer.
	@param border The size of the border of the Button.
	@param minWidth The minimum size of the width.
	@param minHeight the minimum size of the height.
	*/
	JAM_Button(JAM_Texture* sprite, float x, float y, std::string message, std::string fontLocation,
		int fontSize, int r, int g, int b, SDL_Renderer* renderer, float border, float minWidth, float minHeight);

	/**
	Destructs a Button object.
	*/
	~JAM_Button();

	/**
	A function that updates the Button.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	A function that updates the Button.
	@param incomingEvent A reference to the incoming event.
	@returns If the button is pressed.
	*/
	bool input(SDL_Event& incomingEvent);

	/**
	Draws the Button text to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void drawText(SDL_Renderer* renderer);
};