#include "Button.h"

/**************************************************************************************************************/

/*Constructs an Button object.*/
JAM_Button::JAM_Button(JAM_Texture* sprite, float x, float y, float width, float height)
	: JAM_Entity(sprite, x, y, width, height)
{
	/*initialise the text*/
	text = NULL;

	/*initialise the border*/
	border = 0.0f;
}

/**************************************************************************************************************/

/*Constructs an Button object.*/
JAM_Button::JAM_Button(JAM_Texture* sprite, float x, float y, std::string message, std::string fontLocation,
	int fontSize, int r, int g, int b, SDL_Renderer* renderer, float border, float minWidth, float minHeight)
	: JAM_Entity(sprite, x, y, minWidth, minHeight)
{
	/*initialise the text*/
	text = new JAM_Text(message, fontLocation, fontSize, renderer, r, g, b);

	/*initialise the variables*/
	this->border = border;

	/*a variable for the new button size*/
	JAM_Vec2 size = getDimensions();

	/*make sure that the box wraps the text along the x*/
	if (text->getDimensions().x + border > getDimensions().x)
	{
		size.x = text->getDimensions().x + border;
	}

	/*make sure that the box wraps the text along the y*/
	if (text->getDimensions().y + border > getDimensions().y)
	{
		size.y = text->getDimensions().y + border;
	}
	
	/*set the dimensions of the button*/
	setDimensions(size);
}

/**************************************************************************************************************/

/*Destructs an Button object.*/
JAM_Button::~JAM_Button()
{
	/*delete pointers*/
	delete text;
}

/**************************************************************************************************************/

/*Updates the Button.*/
void JAM_Button::update(float dt)
{
}

/**************************************************************************************************************/

/*Handles the input for the button.*/
bool JAM_Button::input(SDL_Event& incomingEvent)
{
	/*a vec2 for testing the touch position*/
	JAM_Vec2 touchPosition;

	/*get the touch position*/
	touchPosition.x = ((float)incomingEvent.motion.x);
	touchPosition.y = ((float)incomingEvent.motion.y);

	/*a ternary operator checking if the touch position is above the button*/
	bool overButton = (touchPosition.x > getPosition().x && touchPosition.x < getPosition().x + getDimensions().x
		&& touchPosition.y > getPosition().y && touchPosition.y < getPosition().y + getDimensions().y) ? 1 : 0;

	switch (incomingEvent.type)
	{
	case SDL_MOUSEBUTTONDOWN: /*If pressed*/

		/*if the left mouse button*/
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			/*if the position is above the button*/
			if (overButton)
			{
				/*the button is pressed*/
				return true;
			}
		}
		break;
	}

	/*the button was not pressed*/
	return false;
}

/**************************************************************************************************************/

/*Draws the Button text to the screen.*/
void JAM_Button::drawText(SDL_Renderer* renderer)
{
	/*Push the text to the screen*/
	text->pushToScreen(
		(int)(getPosition().x + (getDimensions().x * 0.5f) - (text->getDimensions().x * 0.5f)),
		(int)(getPosition().y + (getDimensions().y * 0.5f) - (text->getDimensions().y * 0.5f))
		);
}