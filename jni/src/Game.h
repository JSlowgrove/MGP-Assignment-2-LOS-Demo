#pragma once

#include <SDL.h>
#include <vector>
#include "JAM/State.h"
#include "JAM/StateManager.h"
#include "JAM/Texture.h"
#include "JAM/Audio.h"
#include "JAM/Utilities.h"
#include "JAM/Text.h"
#include "JAM/Vec2.h"
#include "JAM/Button.h"
#include "JAM/Node.h"
#include "JAM/LOS.h"
#include "MapSquare.h"
#include "Robot.h"

/**
@brief Creates an Game object that inherits State and runs the Game.
*/
class Game : public JAM_State
{
private:
	/**The 2D array of MapSquare objects.*/
	std::vector<std::vector<MapSquare*>> mapSquares;
	/**The 2D array of nodes*/
	std::vector<std::vector<JAM_Node*>> nodes;
	/**A pointer to the background music*/
	JAM_Audio* music;
	/**The mouse position*/
	JAM_Vec2 mouse;
	/**The target index*/
	JAM_Vec2 target;
	/**The size of the squares*/
	int squareScale;
	/**The texture for the border*/
	JAM_Texture* border;
	/**The texture for the target*/
	JAM_Texture* targetTexture;
	/**The texture for the walls*/
	JAM_Texture* wall;
	/**The button to toggle placement*/
	JAM_Button* toggle;
	/**The type of object to place (1 = target, -1 = wall)*/
	int placementType;
	/**The AStar Robot*/
	Robot* robot;
	/**A boolean for if the target is visible*/
	bool visible;

	/**
	Handles the Windows Game input.
	@param incomingEvent A reference to the incoming SDL event.
	@returns If false then quit the Game State.
	*/
	bool windowsInput(SDL_Event& incomingEvent);

	/**
	Handles the Android Game input.
	@param incomingEvent A reference to the incoming SDL event.
	@returns If false then quit the Game State.
	*/
	bool androidInput(SDL_Event& incomingEvent);

public:
	/**
	Constructs a Game object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param screenWidth The screen width.
	@param screenHeight The screen height.
	*/
	Game(JAM_StateManager* stateManager, SDL_Renderer* renderer, int screenWidth, int screenHeight);

	/**
	Destructs an Game object.
	*/
	~Game();

	/**
	Handles the Game input.
	@returns If false then quit the Game State.
	*/
	bool input();

	/**
	A function to update the Game to allow the Game to run.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	A function to draw to the screen.
	*/
	void draw();
};