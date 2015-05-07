#include "Audio.h"

/**************************************************************************************************************/

/*Constructs the audio object*/
JAM_Audio::JAM_Audio(std::string file, bool music)
{
	/*if a music file*/
	if (music)
	{
		/*Load music from file*/
		audio = Mix_LoadMUS(file.c_str());
		/*check if successful load*/
		if (audio == NULL)
		{
			/*initialise the message*/
			std::string message = "Failed to load " + file + ", Error is: " + Mix_GetError();
			/*if not print out what failed to load and the error*/
			SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, message.c_str());
		}
		/*set sound to null*/
		sound = NULL;
	}
	/*if a sound effect file*/
	else
	{
		/*Load sound from file*/
		sound = Mix_LoadWAV(file.c_str());
		/*check if successful load*/
		if (sound == NULL)
		{
			/*initialise the message*/
			std::string message = "Failed to load " + file + ", Error is: " + Mix_GetError();
			/*if not print out what failed to load and the error*/
			SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, message.c_str());
		}
		/*set sound to null*/
		audio = NULL;
	}
}

/**************************************************************************************************************/

/*destructs the audio object*/
JAM_Audio::~JAM_Audio()
{
	/*free the audio*/
	Mix_FreeMusic(audio);
	audio = NULL;
	/*free the sound effect*/
	Mix_FreeChunk(sound);
	sound = NULL;
	/*delete the pointer*/
	delete sound;
}

/**************************************************************************************************************/

/*start the music playing*/
void JAM_Audio::startAudio()
{
	/*If there is no audio playing*/
	if (Mix_PlayingMusic() == 0)
	{
		/*Play the audio*/
		Mix_PlayMusic(audio, -1);
	}
}

/**************************************************************************************************************/

/*plays the sound effect*/
void JAM_Audio::playEffect()
{
	/*Play the sound*/
	Mix_PlayChannel(-1, sound, 0);
}

/**************************************************************************************************************/

/*stop the music playing*/
void JAM_Audio::stopAudio()
{
	/*stops the music*/
	Mix_HaltMusic();
}