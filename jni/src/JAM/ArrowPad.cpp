#include "ArrowPad.h"

/**************************************************************************************************************/

/*Constructs an ArrowPad object.*/
JAM_ArrowPad::JAM_ArrowPad(float x, float y, float width, float height, SDL_Renderer* renderer)
{
	/*initialise the buttons*/
	up = new JAM_Button(new JAM_Texture("img/upArrow.png", renderer), 
		x + (width * 0.25f),
		y, 
		width * 0.5f, height * 0.25f);
	down = new JAM_Button(new JAM_Texture("img/downArrow.png", renderer), 
		x + (width * 0.25f),
		y + (height * 0.75f),
		width * 0.5f, height * 0.25f);
	left = new JAM_Button(new JAM_Texture("img/leftArrow.png", renderer), 
		x, 
		y + (height * 0.25f),
		width * 0.25f, height * 0.5f);
	right = new JAM_Button(new JAM_Texture("img/rightArrow.png", renderer), 
		x + (width * 0.75f),
		y + (height * 0.25f),
		width * 0.25f, height * 0.5f);
}

/**************************************************************************************************************/

/*Destructs an ArrowPad object.*/
JAM_ArrowPad::~JAM_ArrowPad()
{
	/*delete pointers*/
	delete up;
	delete down;
	delete left;
	delete right;
}

/**************************************************************************************************************/

/*Handles the input for the ArrowPad.*/
void JAM_ArrowPad::input(SDL_Event& incomingEvent)
{
	/*do the input for all arrows*/
	upCmd = up->input(incomingEvent);
	downCmd = down->input(incomingEvent);
	rightCmd = right->input(incomingEvent);
	leftCmd = left->input(incomingEvent);
}

/**************************************************************************************************************/

/*Draws the ArrowPad to the screen.*/
void JAM_ArrowPad::draw(SDL_Renderer* renderer)
{
	/*draw the buttons*/
	up->draw(renderer);
	down->draw(renderer);
	left->draw(renderer);
	right->draw(renderer);
}

/**************************************************************************************************************/

/*Gets the value of the up command.*/
bool JAM_ArrowPad::getUp()
{
	/*return the up command*/
	return upCmd;
}

/**************************************************************************************************************/

/*Gets the value of the down command.*/
bool JAM_ArrowPad::getDown()
{
	/*return the down command*/
	return downCmd;
}

/**************************************************************************************************************/

/*Gets the value of the left command.*/
bool JAM_ArrowPad::getLeft()
{
	/*return the left command*/
	return leftCmd;
}

/**************************************************************************************************************/

/*Gets the value of the right command.*/
bool JAM_ArrowPad::getRight()
{
	/*return the right command*/
	return rightCmd;
}