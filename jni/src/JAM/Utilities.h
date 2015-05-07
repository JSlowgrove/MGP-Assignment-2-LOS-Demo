#pragma once

#include "Vec2.h"

/**A definition of PI*/
#define PI 3.141596f

/**
@brief A namespace to contain utility functions.
@author Jamie Slowgrove
*/
namespace JAM_Utilities
{
	/**
	Getter # Gets the value for PI.
	@returns The value for PI.
	*/
	float getPI();

	/**
	Converts the degree to a radian.
	@param angle The angle to convert.
	@returns The converted radian.
	*/
	float convertDegreeToRadian(float angle);

	/**
	Converts the radian to a degree.
	@param angle The angle to convert.
	@returns The converted degree.
	*/
	float convertRadianToDegree(float angle);

	/**
	Scale the vector using the screen height.
	@param vector The original vector.
	@param screenHeight The screen height.
	@returns The scaled vector.
	*/
	JAM_Vec2 scaleVector(JAM_Vec2 vector, int screenHeight);

	/**
	Scale the number using the screen height.
	@param number The original number.
	@param screenHeight The screen height.
	@returns The scaled number.
	*/
	float scaleNumber(float number, int screenHeight);
}