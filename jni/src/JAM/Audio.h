#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

/**
@brief Creates a Audio object to handle the SDL_Mixer.
@author Jamie Slowgrove
Reference ~ This is a modified version of my AI Assignment 1 Audio class.
*/
class JAM_Audio
{
private:
	/**Variable for if it's a Music audio type*/
	Mix_Music* audio;
	/**Variable for if it's a Sound effect type*/
	Mix_Chunk* sound;

public:
	/**
	Constructs an Audio object.
	@param file The file to be loaded.
	@param music True for music file. False for sound file.
	*/
	JAM_Audio(std::string file, bool music);

	/**
	Destructs a Audio object.
	*/
	~JAM_Audio();

	/**
	Starts the Audio playing, also checks if not playing and starts again.
	*/
	void startAudio();

	/**
	Plays the sound effect.
	*/
	void playEffect();

	/**
	Stops the Audio playing.
	*/
	void stopAudio();
};