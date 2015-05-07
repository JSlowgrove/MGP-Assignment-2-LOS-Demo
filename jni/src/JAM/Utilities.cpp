#include "Utilities.h"

/*A namespace to contain utility functions.*/
namespace JAM_Utilities
{
	/*Get the value for PI*/
	float getPI()
	{
		/*return the value for PI*/
		return PI;
	}

	/**************************************************************************************************************/

	/*Converts the degree to a radian.*/
	float convertDegreeToRadian(float angle)
	{
		/*return the radian*/
		return (angle * PI / 180.0f);
	}

	/**************************************************************************************************************/

	/*Converts the radian to a degree.*/
	float convertRadianToDegree(float angle)
	{
		/*return the angle*/
		return (angle * 180.0f / PI);
	}

	/**************************************************************************************************************/

	/*Scale the vector using the screen height.*/
	JAM_Vec2 scaleVector(JAM_Vec2 vector, int screenHeight)
	{
		/*A variable for the new Vector*/
		JAM_Vec2 newVector;
		
		/*A variable for the percentage difference*/
		float percentageDifference = (float)screenHeight - 480.0f;
		percentageDifference = (percentageDifference / 480.0f) * 100.0f;

		/*A variable for one percent of the original size of the width*/
		float onePercent = vector.x / 100.0f;

		/*get the difference*/
		float difference = onePercent * percentageDifference;

		/*get the new x value of the vector*/
		newVector.x = vector.x + difference;

		/*A variable for one percent of the original size of the height*/
		onePercent = vector.y / 100.0f;

		/*get the difference*/
		difference = onePercent * percentageDifference;

		/*get the new y value of the vector*/
		newVector.y = vector.y + difference;

		/*return the new vector*/
		return newVector;
	}

	/**************************************************************************************************************/

	/*Scale the number using the screen height.*/
	float scaleNumber(float number, int screenHeight)
	{
		/*A variable for the new number*/
		float newNumber;

		/*A variable for the percentage difference*/
		float percentageDifference = (float)screenHeight - 480.0f;
		percentageDifference = (percentageDifference / 480.0f) * 100.0f;

		/*A variable for one percent of the original size*/
		float onePercent = number / 100.0f;

		/*get the difference*/
		float difference = onePercent * percentageDifference;

		/*get the new value of the number*/
		newNumber = number + difference;

		/*return the new number*/
		return newNumber;
	}
}