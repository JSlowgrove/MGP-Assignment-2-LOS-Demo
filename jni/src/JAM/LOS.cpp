#include "LOS.h"

/**************************************************************************************************************/

/*check if two positions can see each other*/
bool JAM_LOS::lineOfSight(JAM_Vec2 a, JAM_Vec2 b, std::vector<std::vector<JAM_Node*>> map, int nodeSize)
{
	/*initialise the test area*/
	int minX, maxX, minY, maxY;
	minX = maxX = minY = maxY = 0;

	/*check for the smallest x*/
	if (a.x < b.x)
	{
		/*initialise the min tile using a and max tile using b*/
		minX = (int)(a.x / nodeSize);
		maxX = (int)((b.x + nodeSize) / nodeSize);
	}
	else
	{
		/*initialise the min tile using b and max tile using a*/
		minX = (int)(b.x / nodeSize);
		maxX = (int)((a.x + nodeSize) / nodeSize);
	}

	/*check for the smallest y*/
	if (a.y < b.y)
	{
		/*initialise the min tile using a and max tile using b*/
		minY = (int)(a.y / nodeSize);
		maxY = (int)((b.y + nodeSize) / nodeSize);
	}
	else
	{
		/*initialise the min tile using b and max tile using a*/
		minY = (int)(b.y / nodeSize);
		maxY = (int)((a.y + nodeSize) / nodeSize);
	}

	/*test only the tiles within the max and min y tiles*/
	for (int i = minY; i < maxY; i++)
	{
		/*test only the tiles within the max and min tiles on the x axis*/
		for (int j = minX; j < maxX; j++)
		{
			bool collision = false;
			/*
			A---------B
			|         |
			|         |
			|         |
			|         |
			|         |
			C---------D
			*/
			/*AB test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i * nodeSize)),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i * nodeSize)), 'x'))
			{
				/*collision*/
				collision = true;
			}
			/*AC test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i * nodeSize)),
				JAM_Vec2((float)(j * nodeSize), (float)(i + 1) * nodeSize), 'y'))
			{
				/*collision*/
				collision = true;
			}
			/*CD test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i + 1) * nodeSize),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * 32), 'x'))
			{
				/*collision*/
				collision = true;
			}
			/*BD test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * nodeSize),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * nodeSize), 'y'))
			{
				/*collision*/
				collision = true;
			}

			/*if there has been a collision*/
			if (collision)
			{
				/*if the collision is a danger*/
				if (!map[j][i]->getSafeNode())
				{
					/*the creature is out of sight*/
					return false;
				}
			}
		}
	}
	/*the creature is still in sight*/
	return true;
}

/**************************************************************************************************************/

/*check if two lines intersect*/
bool JAM_LOS::lineLineIntersectionCheck(JAM_Vec2 a, JAM_Vec2 b, JAM_Vec2 c, JAM_Vec2 d, char axis)
{
	/*y=mx+c*/
	/*work out the gradient of the line ab*/
	float m = 0.0f;
	/*check it will not divide by 0*/
	if (b.x - a.x != 0.0f)
	{
		/*work out m using m = (y1-y0)/(x1-x0)*/
		m = (b.y - a.y) / (b.x - a.x);
	}

	/*work out c using c=y-mx*/
	float c0 = a.y - (m * a.x);

	/*initialise x & y*/
	float y = 0.0f;
	float x = 0.0f;

	/*test the axis*/
	switch (axis)
	{
	/*if the axis is the x axis*/
	case 'x':
		/*work out the x using x=(y-c)/m*/
		x = (c.y - c0) / m;
		/*if the x is on the line*/
		if (x >= c.x && x <= d.x)
		{
			/*the lines intersect*/
			return true;
		}
		break;
	/*if the axis is the y axis*/
	case 'y':
		/*work out the y using y=mx+c*/
		y = (m * c.x) + c0;
		/*if the y is on the line*/
		if (y >= c.y && y <= d.y)
		{
			/*the lines intersect*/
			return true;
		}
		break;
	}

	/*the lines do not intersect*/
	return false;
}

/**************************************************************************************************************/

/*draw the tiles on the line of sight*/
void JAM_LOS::drawLineOfSight(JAM_Vec2 a, JAM_Vec2 b, std::vector<std::vector<JAM_Node*>> map, int nodeSize, SDL_Renderer* renderer)
{
	/*creates a rectangle*/
	SDL_Rect box;

	/*initialise the test area*/
	int minX, maxX, minY, maxY;
	minX = maxX = minY = maxY = 0;

	/*check for the smallest x*/
	if (a.x < b.x)
	{
		/*initialise the min tile using a and max tile using b*/
		minX = (int)(a.x / nodeSize);
		maxX = (int)((b.x + nodeSize) / nodeSize);
	}
	else
	{
		/*initialise the min tile using b and max tile using a*/
		minX = (int)(b.x / nodeSize);
		maxX = (int)((a.x + nodeSize) / nodeSize);
	}

	/*check for the smallest y*/
	if (a.y < b.y)
	{
		/*initialise the min tile using a and max tile using b*/
		minY = (int)(a.y / nodeSize);
		maxY = (int)((b.y + nodeSize) / nodeSize);
	}
	else
	{
		/*initialise the min tile using b and max tile using a*/
		minY = (int)(b.y / nodeSize);
		maxY = (int)((a.y + nodeSize) / nodeSize);
	}

	/*test only the tiles within the max and min y tiles*/
	for (int i = minY; i < maxY; i++)
	{
		/*test only the tiles within the max and min tiles on the x axis*/
		for (int j = minX; j < maxX; j++)
		{
			bool collision = false;
			/*
			A---------B
			|         |
			|         |
			|         |
			|         |
			|         |
			C---------D
			*/
			/*AB test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i * nodeSize)),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i * nodeSize)), 'x'))
			{
				/*collision*/
				collision = true;
			}
			/*AC test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i * nodeSize)),
				JAM_Vec2((float)(j * nodeSize), (float)(i + 1) * nodeSize), 'y'))
			{
				/*collision*/
				collision = true;
			}
			/*CD test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j * nodeSize), (float)(i + 1) * nodeSize),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * nodeSize), 'x'))
			{
				/*collision*/
				collision = true;
			}
			/*BD test*/
			if (lineLineIntersectionCheck(a, b, JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * nodeSize),
				JAM_Vec2((float)(j + 1) * nodeSize, (float)(i + 1) * nodeSize), 'y'))
			{
				/*collision*/
				collision = true;
			}

			/*if there has been a collision*/
			if (collision)
			{
				/*if the collision is a danger*/
				if (!map[j][i]->getSafeNode())
				{
					/*set the draw colour to magenta*/
					SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
				}
				/*if the collision is with an empty tile*/
				else
				{
					/*set the draw colour to orange*/
					SDL_SetRenderDrawColor(renderer, 0xFF, 0xA5, 0x00, 0xFF);
				}
				/*update the box for the tile*/
				box.x = j * nodeSize;
				box.y = i * nodeSize;
				box.w = box.h = nodeSize;

				/*draw the tiles outline*/
				SDL_RenderDrawRect(renderer, &box);
			}
		}
	}

	/*set the draw colour to white*/
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	/*update the box for the test area*/
	box.x = minX * nodeSize;
	box.y = minY * nodeSize;
	box.w = (maxX * nodeSize) - (minX * nodeSize);
	box.h = (maxY * nodeSize) - (minY * nodeSize);

	/*draw the test area outline*/
	SDL_RenderDrawRect(renderer, &box);
}

/**************************************************************************************************************/

/*find a new target position to go to*/
JAM_Vec2 JAM_LOS::getNewTarget(JAM_Vec2 a, std::vector<std::vector<JAM_Node*>> map, int nodeSize)
{
	/*initialise variables*/
	JAM_Vec2 b = { 0.0f, 0.0f };
	bool wall = false;
	bool generated = false;
	
	/*loop until a new position has been generated that is out of sight of the player*/
	while (!generated)
	{
		/*initialise the target vector with a random new position*/
		b = { (float)(rand() % map.size() - 1) * nodeSize, (float)(rand() % map.size() - 1) * nodeSize };

		/*wall check*/
		wall = false;
		if (!map[(int)(b.x / nodeSize)][(int)(b.y / nodeSize)]->getSafeNode())
		{
			wall = true;
		}

		/*loop while the generated position is a wall*/
		while (wall)
		{
			/*generate a random new position*/
			b = { (float)(rand() % map.size() - 1) * nodeSize, (float)(rand() % map.size() - 1) * nodeSize };

			/*wall check*/
			wall = false;
			if (!map[(int)(b.x / nodeSize)][(int)(b.y / nodeSize)]->getSafeNode())
			{
				wall = true;
			}
		}
		/*check if position is not able to be seen by the player*/
		if (!lineOfSight(a + JAM_Vec2(nodeSize * 0.5f, nodeSize * 0.5f), b + JAM_Vec2(nodeSize * 0.5f, nodeSize * 0.5f), map, nodeSize))
		{
			/*the position is generated*/
			generated = true;
		}
	}

	/*return the new position*/
	return b;
}