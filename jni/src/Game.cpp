#include "Game.h"

/**************************************************************************************************************/

/*Constructs the game object*/
Game::Game(JAM_StateManager * stateManager, SDL_Renderer* renderer, int screenWidth, int screenHeight)
	: JAM_State(stateManager, renderer, screenWidth, screenHeight)
{
	/*initialise the square size*/
	squareScale = (int)JAM_Utilities::scaleNumber(32.0f, screenHeight);

	/*The textures for the map objects*/
	border = new JAM_Texture(renderer, 255, 255, 0);
	targetTexture = new JAM_Texture(renderer, 0, 0, 255);
	wall = new JAM_Texture(renderer, 255, 0, 255);

	/*initialise the robot*/
	robot = new Robot(new JAM_Texture(renderer, 0, 255, 255), 
		(float)(squareScale * (int)((screenWidth / squareScale)*0.5f)),
		(float)(squareScale * (int)((screenHeight / squareScale)*0.5f)),
		(float)squareScale, (float)squareScale);

	/*initialise the button*/
	toggle = new JAM_Button(wall, 0.0f, 0.0f, "Toggle block", "font/Underdog_tt_hinted.ttf", (int)JAM_Utilities::scaleNumber(15.0f, screenHeight),
		0, 0, 0, renderer, JAM_Utilities::scaleNumber(1.0f, screenHeight), squareScale * 4.0f, (float)squareScale);

	/*initialises the type of object to place*/
	placementType = 1;
	
	/*initialise the mapSquares*/
	for (int x = 0; x < (int)(screenWidth / squareScale); x++)
	{
		mapSquares.resize(x + 1);
		nodes.resize(x + 1);
		for (int y = 0; y < (int)(screenHeight / squareScale); y++)
		{
			/*if a border map square */
			if (y == 0 || y == (int)(screenHeight / squareScale) - 1 || x == 0 || x == (int)(screenWidth / squareScale) - 1)
			{
				/*add a new danger mapSquare [x][y]*/
				mapSquares[x].push_back(new MapSquare(border, (float)(x * squareScale), (float)(y * squareScale),
					(float)squareScale, (float)squareScale, true));
				nodes[x].push_back(new JAM_Node(x, y));
				nodes[x][y]->setSafeNode(false);
			}
			else
			{
				/*if not a border map square add a new safe mapSquare [x][y]*/
				mapSquares[x].push_back(new MapSquare(targetTexture, (float)(x * squareScale), (float)(y * squareScale),
					(float)squareScale, (float)squareScale, false));
				nodes[x].push_back(new JAM_Node(x, y));
				nodes[x][y]->setSafeNode(true);
			}
		}
	}

	/*initialise the music*/
	music = new JAM_Audio("aud/Cut Trance.ogg", true);

	/*initialise the mouse*/
	mouse = JAM_Vec2(0.0f, 0.0f);

	/*initialise the target*/
	target = JAM_Vec2(1.0f, 1.0f);

	/*initalise visible*/
	visible = true;
}

/**************************************************************************************************************/

/*Destructs the game object*/
Game::~Game()
{
	/*stop music*/
	music->stopAudio();
	/*delete audio pointers*/
	delete music;
	/*delete pointers*/
	for (unsigned int x = 0; x < mapSquares[0].size(); x++)
	{
		for (unsigned int y = 0; y < mapSquares.size(); y++)
		{
			delete mapSquares[y][x];
		}
	}
}

/**************************************************************************************************************/

/*handles inputs*/
bool Game::input()
{
	/*Check for user input*/
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		/*if the button input is true*/
		if (toggle->input(incomingEvent))
		{
			/*change the placement type*/
			placementType = -placementType;
		}

		/*get the mouse input*/
		mouse.x = ((float)incomingEvent.motion.x);
		mouse.y = ((float)incomingEvent.motion.y);

		switch (incomingEvent.type)
		{
		case SDL_QUIT: /*If player closes the window, end the game loop*/

			SDL_Log("Exiting Main Loop");
			return false;
			break;

		case SDL_MOUSEBUTTONDOWN: /*If the mouse is pressed*/

			/*if the left mouse button set a new target*/
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{
				/*if not a border map square */
				if ((int)mouse.y / squareScale != 0 && (int)mouse.y / squareScale != (int)(screenHeight / squareScale) - 1
					&& (int)mouse.x / squareScale != 0 && (int)mouse.x / squareScale != (int)(screenWidth / squareScale) - 1)
				{

					/*test if targets are being placed*/
					if (placementType == 1)
					{
						/*reset the previous target*/
						delete mapSquares[(int)target.x][(int)target.y];
						mapSquares[(int)target.x][(int)target.y]
							= new MapSquare(targetTexture, (float)target.x * squareScale, (float)target.y * squareScale,
							(float)squareScale, (float)squareScale, false);
						nodes[(int)mouse.x / squareScale][(int)mouse.y / squareScale]->setSafeNode(true);

						/*set the new target*/
						target = JAM_Vec2((float)((int)mouse.x / squareScale), (float)((int)mouse.y / squareScale));

						/*set the new target*/
						delete mapSquares[(int)target.x][(int)target.y];
						mapSquares[(int)target.x][(int)target.y]
							= new MapSquare(targetTexture, (float)target.x * squareScale, (float)target.y * squareScale,
							(float)squareScale, (float)squareScale, false);

						/*test for line of sight*/
						visible = JAM_LOS::lineOfSight(robot->getPosition(), target * (float)squareScale, nodes, squareScale);
					}

					/*test if walls are being placed*/
					if (placementType == -1)
					{
						/*test if it is already a danger square*/
						if (mapSquares[(int)mouse.x / squareScale][(int)mouse.y / squareScale]->getDanger())
						{
							/*reset the square*/
							delete mapSquares[(int)mouse.x / squareScale][(int)mouse.y / squareScale];
							mapSquares[(int)mouse.x / squareScale][(int)mouse.y / squareScale]
								= new MapSquare(
								targetTexture,
								(float)((int)mouse.x / squareScale) * squareScale,
								(float)((int)mouse.y / squareScale) * squareScale,
								(float)squareScale,
								(float)squareScale,
								false);
							nodes[(int)mouse.x / squareScale][(int)mouse.y / squareScale]->setSafeNode(true);
						}
						else
						{
							/*set the square as a danger square*/
							delete mapSquares[(int)mouse.x / squareScale][(int)mouse.y / squareScale];
							mapSquares[(int)mouse.x / squareScale][(int)mouse.y / squareScale]
								= new MapSquare(
								wall,
								(float)((int)mouse.x / squareScale) * squareScale,
								(float)((int)mouse.y / squareScale) * squareScale,
								(float)squareScale,
								(float)squareScale,
								true);
							nodes[(int)mouse.x / squareScale][(int)mouse.y / squareScale]->setSafeNode(false);
						}
						/*test for line of sight*/
						visible = JAM_LOS::lineOfSight(robot->getPosition(), target * (float)squareScale, nodes, squareScale);
					}
				}
			}
		}


#ifdef __ANDROID__

		/*handle the android inputs*/
		return androidInput(incomingEvent);

#elif _WIN32	

		/*handle the windows inputs*/
		return windowsInput(incomingEvent);

#endif

	}
	return true;
}

/**************************************************************************************************************/

/*handles windows inputs*/
bool Game::windowsInput(SDL_Event& incomingEvent)
{
	switch (incomingEvent.type)
	{
	case SDL_KEYDOWN:

		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE: /*If Escape is pressed, end the game loop*/

			SDL_Log("Exiting Main Loop");
			return false;
			break;

		}
		break;
	}
	return true;
}

/**************************************************************************************************************/

/*handles android inputs*/
bool Game::androidInput(SDL_Event& incomingEvent)
{
	switch (incomingEvent.type)
	{
	case SDL_KEYDOWN:

		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_AC_BACK: /*If Back is pressed on the phone, end the game loop*/

			SDL_Log("Exiting Main Loop");
			return false;
			break;
		}
		break;
	}
	return true;
}

/**************************************************************************************************************/

/*updates the game*/
void Game::update(float dt)
{
	/*keep the music playing*/
	music->startAudio();
}

/**************************************************************************************************************/

/*draws the game*/
void Game::draw()
{
	/*set draw colour to red*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x00);

	/*creates a rectangle*/
	SDL_Rect box;

	/*loop through all of the tiles*/
	for (unsigned int x = 0; x < mapSquares.size(); x++)
	{
		for (unsigned int y = 0; y < mapSquares[0].size(); y++)
		{
			/*draw the walls*/
			if (mapSquares[x][y]->getDanger())
			{
				mapSquares[x][y]->draw(renderer);
			}

			/*update the box for the tile*/
			box.x = x * (int)mapSquares[x][y]->getDimensions().x;
			box.y = y * (int)mapSquares[x][y]->getDimensions().y;
			box.w = (int)mapSquares[x][y]->getDimensions().x;
			box.h = (int)mapSquares[x][y]->getDimensions().y;

			/*draw the tiles outline*/
			SDL_RenderDrawRect(renderer, &box);
		}
	}

	/*draw the button*/
	toggle->draw(renderer);
	toggle->drawText(renderer);
	
	/*draw the target*/
	mapSquares[(int)target.x][(int)target.y]->draw(renderer);

	/*draw the robot*/
	robot->draw(renderer);

	/*if visible*/
	if (visible)
	{
		/*draw the line of sight*/
		JAM_LOS::drawLineOfSight(robot->getPosition(), target * (float)squareScale, nodes, squareScale, renderer);
	}
}