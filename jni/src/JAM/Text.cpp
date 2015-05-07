#include "Text.h"

/**************************************************************************************************************/

/*Constructs the texture with default font size and colour (10 and black)*/
JAM_Text::JAM_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer)
{
	/*initialise text*/
	this->text = text;

	/*initialise font location*/
	this->fontLocation = fontLocation;

	/*initialise font size*/
	fontSize = 10;

	/*initialise the pointer to the renderer*/
	this->renderer = renderer;

	/*initialise font and font colour*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);
	fontColour = { (Uint8)0, (Uint8)0, (Uint8)0 };

	/*create the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Constructs the texture with default font colour (black)*/
JAM_Text::JAM_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer)
{
	/*initialise text*/
	this->text = text;

	/*initialise font location*/
	this->fontLocation = fontLocation;

	/*initialise font size*/
	this->fontSize = fontSize;

	/*initialise the pointer to the renderer*/
	this->renderer = renderer;

	/*initialise font and font colour*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);
	fontColour = { (Uint8)0, (Uint8)0, (Uint8)0 };

	/*create the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Constructs the texture with default font size (10)*/
JAM_Text::JAM_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, int r, int g, int b)
{
	/*initialise text*/
	this->text = text;

	/*initialise font location*/
	this->fontLocation = fontLocation;

	/*initialise font size*/
	fontSize = 10;

	/*initialise the pointer to the renderer*/
	this->renderer = renderer;

	/*initialise font and font colour*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };
	
	/*create the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Constructs the texture*/
JAM_Text::JAM_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, int r, int g, int b)
{
	/*initialise text*/
	this->text = text;

	/*initialise font location*/
	this->fontLocation = fontLocation;

	/*initialise font size*/
	this->fontSize = fontSize;

	/*initialise the pointer to the renderer*/
	this->renderer = renderer;

	/*initialise font and font colour*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };

	/*create the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Destructs the Texture*/
JAM_Text::~JAM_Text()
{
	/*deletes the texture from memory*/
	SDL_DestroyTexture(textureData);
	/*delete font*/
	TTF_CloseFont(font);
	font = NULL;
}

/**************************************************************************************************************/

/*Creates a Text Texture using the text data*/
void JAM_Text::createTextTexture()
{
	/*Declaring the surface*/
	SDL_Surface *surface;

	/*Creating the surface from the font*/
	surface = TTF_RenderText_Solid(font, text.c_str(), fontColour);

	/*Converts the surface into texture data*/
	textureData = SDL_CreateTextureFromSurface(renderer, surface);

	/*delete the surface from memory*/
	SDL_FreeSurface(surface);

	/*get the size of the texture*/
	SDL_QueryTexture(textureData, NULL, NULL, &textureWidth, &textureHeight);
}

/**************************************************************************************************************/

/*Pushes the texture to the Renderer*/
void JAM_Text::pushToScreen(int x, int y)
{
	/*create the destination rectangle of the texture*/
	SDL_Rect destRect;
	destRect.x = x; /*destination x coordinate*/
	destRect.y = y; /*destination y coordinate*/
	destRect.w = textureWidth; /*destination width (scale along the x axis)*/
	destRect.h = textureHeight; /*destination height (scale along the y axis)*/

	/*Copy the texture to the renderer at the destination rectangle*/
	SDL_RenderCopy(renderer, textureData, NULL, &destRect);
}

/**************************************************************************************************************/

/*Sets the colour of the text*/
void JAM_Text::setColour(int r, int g, int b)
{
	/*set the font colour*/
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };

	/*recreate the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Sets the font size of the text*/
void JAM_Text::setFontSize(int fontSize)
{
	/*set the font size*/
	this->fontSize = fontSize;

	/*set the font*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	/*recreate the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Sets the font of the text*/
void JAM_Text::setFont(std::string fontLocation)
{
	/*set the font*/
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	/*recreate the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Sets the text*/
void JAM_Text::setText(std::string text)
{
	/*set the text*/
	this->text = text;

	/*recreate the text texture*/
	createTextTexture();
}

/**************************************************************************************************************/

/*Gets the dimensions of thee Text.*/
JAM_Vec2 JAM_Text::getDimensions()
{
	/*return the dimensions*/
	return JAM_Vec2((float)textureWidth, (float)textureHeight);
}
