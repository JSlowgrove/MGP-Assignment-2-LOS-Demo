#include "State.h"

/**************************************************************************************************************/

/*Constructs the state object*/
JAM_State::JAM_State(JAM_StateManager * stateManager, SDL_Renderer* renderer, int screenWidth, int screenHeight)
{
	/*sets the pointer to the state manager*/
	this->stateManager = stateManager;
	/*sets the pointer to the renderer*/
	this->renderer = renderer;
	/*load the screen dimensions*/
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

}

/**************************************************************************************************************/

/*Destructs the state object*/
JAM_State::~JAM_State()
{
}