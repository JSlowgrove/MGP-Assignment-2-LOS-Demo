#include "ParticleEffect.h"

/**************************************************************************************************************/

/*Constructs a ParticleEffect Object.*/
JAM_ParticleEffect::JAM_ParticleEffect(std::string fileName, JAM_Vec2 emitter, bool emit, SDL_Renderer* renderer, int screenHeight)
{
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*store the variables*/
	this->emitter = emitter;
	this->screenHeight = screenHeight;

	/*initialise the move speed*/
	moveSpeed = JAM_Utilities::scaleNumber(1.0f, screenHeight);

	/*set the value of emit*/
	this->emit = emit;

	/*initialise the texture*/
	texture = new JAM_Texture(fileName, renderer);

	/*generate the new particles*/
	makeNewParticles();
}

/**************************************************************************************************************/

/*Constructs a ParticleEffect Object.*/
JAM_ParticleEffect::JAM_ParticleEffect(JAM_Vec2 emitter, bool emit, SDL_Renderer* renderer, int r, int g, int b)
{
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*store the variables*/
	this->emitter = emitter;

	/*initialise the move speed*/
	moveSpeed = JAM_Utilities::scaleNumber(1.0f, screenHeight);

	/*set the value of emit*/
	this->emit = emit;

	/*initialise the texture*/
	texture = new JAM_Texture(renderer, r, g, b);

	/*generate the new particles*/
	makeNewParticles();
}

/**************************************************************************************************************/

/*Destructs a ParticleEffect Object.*/
JAM_ParticleEffect::~JAM_ParticleEffect()
{
	/*delete pointers*/
	for (auto particle : particles)
	{
		delete particle;
	}
}

/**************************************************************************************************************/

/*update the ParticleEffect*/
void JAM_ParticleEffect::update(float dt)
{
	/*generate the new particles*/
	makeNewParticles();

	/*update the particles*/
	for (auto particle : particles)
	{
		particle->update(dt);
	}

	/*if the particle should emit*/
	if (emit)
	{
		/*while the number of particles is greater than the max number of particles.*/
		while (particles.size() > MAX_NUMBER_OF_PARTICLES)
		{
			/*delete pointer*/
			delete particles[0];
			/*erase the oldest particle*/
			particles.erase(particles.begin());
		}
	}
	else
	{
		/*make sure there is at least 1 particle left*/
		if (particles.size() > 0)
		{
			/*delete pointer*/
			delete particles[0];
			/*erase the oldest particle*/
			particles.erase(particles.begin());
		}
	}
}

/**************************************************************************************************************/

/*draw the particle effects*/
void JAM_ParticleEffect::draw(SDL_Renderer* renderer)
{
	/*loop through all of the particles*/
	for (auto particle : particles)
	{
		/*draw the particle*/
		particle->draw(renderer);
	}
}

/**************************************************************************************************************/

/*creates the new particles*/
void JAM_ParticleEffect::makeNewParticles()
{
	/*if the particle should emit*/
	if (emit)
	{
		/*get the number of particles to initialise between 0 and 4 (before scaling)*/
		int numberOfParticles = (rand() % (int)JAM_Utilities::scaleNumber(5.0f, screenHeight));

		/*loop for all of the particles to create*/
		for (int i = 0; i < numberOfParticles; i++)
		{
			/*get the scale of the particle, between 1 and 5 (before scaling)*/
			float scaleValue = (float)((rand() % (int)JAM_Utilities::scaleNumber(4.0f, screenHeight)) + 1);

			/*get the direction of the particle between -15f and 15f (before scaling)*/
			JAM_Vec2 direction;
			direction.x = (float)((rand() % (int)JAM_Utilities::scaleNumber(30.0f, screenHeight)) + 1);
			direction.y = (float)((rand() % (int)JAM_Utilities::scaleNumber(30.0f, screenHeight)) + 1);
			direction.x -= JAM_Utilities::scaleNumber(30.0f, screenHeight) * 0.5f;
			direction.y -= JAM_Utilities::scaleNumber(30.0f, screenHeight) * 0.5f;

			/*push a new particle to the vector*/
			particles.push_back(new JAM_Particle(texture, scaleValue, direction, moveSpeed, emitter));
		}
	}
}

/**************************************************************************************************************/

/*Sets the emitter position.*/
void JAM_ParticleEffect::setEmitter(JAM_Vec2 emitter)
{
	/*set the emitter*/
	this->emitter = emitter;
}

/**************************************************************************************************************/

/*Sets the emit boolean.*/
void JAM_ParticleEffect::setEmitting(bool emit)
{
	/*set the value of emit*/
	this->emit = emit;
}