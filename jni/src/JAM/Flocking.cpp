#include "Flocking.h"
#include <cmath>

/**************************************************************************************************************/

/*Constructs the flocking object*/
JAM_Flocking::JAM_Flocking(int numberOfBoids, JAM_Texture* texture, int xBoundary, int yBoundary, float maxVel, int screenHeight)
{
	/*initialize random seed*/
	srand((unsigned int)time(NULL));

	/*initialise the size of the screen height*/
	this->screenHeight = screenHeight;

	/*initialise a the number of Boid objects*/
	for (int i = 0; i < numberOfBoids; i++)
	{
		/*creates a Boid at a random position on the screen*/
		boids.push_back(new JAM_Particle(texture, JAM_Utilities::scaleNumber(4.0f, screenHeight), JAM_Vec2(0.0f, 0.0f), maxVel, 
			JAM_Vec2((float)(rand() % xBoundary), (float)(rand() % yBoundary))));
	}

	/*initialise the boundaries*/
	this->xBoundary = xBoundary;
	this->yBoundary = yBoundary;

	/*initialise all of the rules to be on*/
	applyRule1 = applyRule2 = applyRule3 = 1;

	/*initialise the max velocity*/
	this->maxVel = maxVel;
}

/**************************************************************************************************************/

/*Destructs the flocking object*/
JAM_Flocking::~JAM_Flocking()
{
	/*delete pointers*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		delete boids[i];
	}
}

/**************************************************************************************************************/

/*updates the flocking*/
void JAM_Flocking::update(float dt)
{
	/*initialise the resultant velocities*/
	JAM_Vec2 v1 = JAM_Vec2( 0.0f, 0.0f );
	JAM_Vec2 v2 = JAM_Vec2( 0.0f, 0.0f );
	JAM_Vec2 v3 = JAM_Vec2( 0.0f, 0.0f );
	JAM_Vec2 v4 = JAM_Vec2( 0.0f, 0.0f );

	/*The speed increase of the boids*/
	float speed = 25.0f;

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*test rule 1 and apply activity*/
		v1 = (rule1(i) * (float)applyRule1);
		/*test rule 2 and apply activity*/
		v2 = (rule2(i) * (float)applyRule2);
		/*test rule 3 and apply activity*/
		v3 = (rule3(i) * (float)applyRule3);

		/*apply boundaries*/
		v4 = roughBoundaries(i);

		/*update the Boid velocity*/
		boids[i]->setDirection(boids[i]->getDirection() + v1 + v2 + v3 + v4);
		/*limit the velocity of the Boid*/
		limitVelocity(i);
		/*update the Boid position*/
		boids[i]->setPosition(boids[i]->getPosition() + (boids[i]->getDirection() * dt) * speed);
	}
}

/**************************************************************************************************************/

/*draws the game*/
void JAM_Flocking::draw(SDL_Renderer* renderer)
{
	/*display the Boid objects*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*display the Boid*/
		boids[i]->draw(renderer);
	}
}

/**************************************************************************************************************/

/*applies Boid rule 1 (cohesion)*/
JAM_Vec2 JAM_Flocking::rule1(int boidIndex)
{
	/*initialise the new velocity*/
	JAM_Vec2 vel = JAM_Vec2(0.0f, 0.0f);
	/*initialise the center of mass*/
	JAM_Vec2 cOfM = JAM_Vec2(0.0f, 0.0f);

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*if the Boid to be tested is not the inputed Boid*/
		if (i != (unsigned int)boidIndex)
		{
			/*update the center of mass*/
			cOfM = boids[i]->getPosition() + cOfM;
		}
	}

	/*divide the center of mass by the number of Boid objects tested*/
	cOfM = cOfM / (float)(boids.size() - 1);

	/*set the new velocity to the amount to move towards the Boid (1% of the distance in this case)*/
	vel = (cOfM - boids[boidIndex]->getPosition()) / 100;

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 2 (speration)*/
JAM_Vec2 JAM_Flocking::rule2(int boidIndex)
{
	/*the new velocity*/
	JAM_Vec2 vel = JAM_Vec2(0.0f, 0.0f);

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*if the Boid to be tested is not the inputed Boid*/
		if (i != (unsigned int)boidIndex)
		{
			/*if the Boid is closer than 10 pixels to another Boid on the x axis (using absolute values)*/
			if (std::abs(boids[boidIndex]->getPosition().x - boids[i]->getPosition().x) < 10)
			{
				vel.x = vel.x - (boids[i]->getPosition().x - boids[boidIndex]->getPosition().x);
			}

			/*if the Boid is closer than 10 pixels to another Boid on the y axis (using absolute values)*/
			if (std::abs(boids[boidIndex]->getPosition().y - boids[i]->getPosition().y) < 10)
			{
				vel.y = vel.y - (boids[i]->getPosition().y - boids[boidIndex]->getPosition().y);
			}
		}
	}

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rule 3 (alignment)*/
JAM_Vec2 JAM_Flocking::rule3(int boidIndex)
{
	/*initialise the new velocity*/
	JAM_Vec2 vel = JAM_Vec2(0.0f, 0.0f);

	/*test each Boid*/
	for (unsigned int i = 0; i < boids.size(); i++)
	{
		/*if the Boid to be tested is not the inputed Boid*/
		if (i != (unsigned int)boidIndex)
		{
			/*add all of the Boid velocities together*/
			vel = vel + boids[i]->getDirection();
		}
	}

	/*get the average velocity*/
	vel = vel / (float)(boids.size() - 1);

	/*set it to about an eighth of the Boid velocity*/
	vel = (vel - boids[boidIndex]->getDirection()) / 8;

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*applies Boid rough boundaries*/
JAM_Vec2 JAM_Flocking::roughBoundaries(int boidIndex)
{
	/*initialise the new velocity*/
	JAM_Vec2 vel = JAM_Vec2(0.0f, 0.0f);

	/*check if the Boid is off the right of the screen*/
	if (boids[boidIndex]->getPosition().x > xBoundary)
	{
		/*set a negative x velocity*/
		vel.x = -10.0f;
	}
	/*check if the Boid is off the right of the screen*/
	else if (boids[boidIndex]->getPosition().x < 0)
	{
		/*set a positive x velocity*/
		vel.x = 10.0f;
	}

	/*check if the Boid is off the bottom of the screen*/
	if (boids[boidIndex]->getPosition().y > yBoundary)
	{
		/*set a negative y velocity*/
		vel.y = -10.0f;
	}
	/*check if the Boid is off the top of the screen*/
	else if (boids[boidIndex]->getPosition().y < 0)
	{
		/*set a positive y velocity*/
		vel.y = 10.0f;
	}

	/*return the new velocity*/
	return vel;
}

/**************************************************************************************************************/

/*limit the velocity of the Boid*/
void JAM_Flocking::limitVelocity(int boidIndex)
{
	/*test if the absolute of the x velocity is greater than the max velocity*/
	if (std::abs(boids[boidIndex]->getDirection().x) > maxVel)
	{
		/*work out if negative or positive*/
		float sign = boids[boidIndex]->getDirection().x / std::abs(boids[boidIndex]->getDirection().x);
		/*set the x velocity to the max velocity*/
		boids[boidIndex]->setDirection(JAM_Vec2(maxVel * sign, boids[boidIndex]->getDirection().y));
	}

	/*test if the absolute of the y velocity is greater than the max velocity*/
	if (std::abs(boids[boidIndex]->getDirection().y) > maxVel)
	{
		/*work out if negative or positive*/
		float sign = boids[boidIndex]->getDirection().y / std::abs(boids[boidIndex]->getDirection().y);
		/*set the y velocity to the max velocity*/
		boids[boidIndex]->setDirection(JAM_Vec2(boids[boidIndex]->getDirection().x, maxVel * sign));
	}
}

/**************************************************************************************************************/

/*Set applyRule1.*/
void JAM_Flocking::setRule1(int applyRule1)
{
	/*set the rule*/
	this->applyRule1 = applyRule1;
}

/**************************************************************************************************************/

/*Set applyRule2.*/
void JAM_Flocking::setRule2(int applyRule2)
{
	/*set the rule*/
	this->applyRule2 = applyRule2;
}

/**************************************************************************************************************/

/*Set applyRule3.*/
void JAM_Flocking::setRule3(int applyRule3)
{
	/*set the rule*/
	this->applyRule3 = applyRule3;
}