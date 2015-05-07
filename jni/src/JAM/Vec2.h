#pragma once

/**
@brief Creates an Vec2 structure with functions
Creates an Vec2 structure with overloaded operators to create a new variable type for use as a 2D vector.
@author Jamie Slowgrove
Reference ~ This is a modified version of my AI Assignment 1 Vec2 class.
*/
struct JAM_Vec2
{
	/*position variables*/
	float x;
	float y;
	
	/**
	Constructs an Vec2
	Constructs the Vec2 setting the values to 0,0
	*/
	JAM_Vec2()
	{
		x = 0;
		y = 0;
	}

	/**
	Constructs a Vec2
	Constructs the Vec2 setting the values to the input coordinates
	@param inputX The inputed x position
	@param inputY The inputed y position
	*/
	JAM_Vec2(float inputX, float inputY)
	{
		x = inputX;
		y = inputY;
	}

	/**
	Overloads the += operator
	Overloads the += operator allowing a Vec2 variable to use +=
	@param a The input Vec2
	@returns The new vector.
	*/
	JAM_Vec2* operator += (JAM_Vec2 a)
	{
		x += a.x;
		y += a.y;
		return this;
	}

	/**
	Overloads the -= operator
	Overloads the -= operator allowing a Vec2 variable to use -=
	@param a The input Vec2
	@returns The new vector.
	*/
	JAM_Vec2* operator -= (JAM_Vec2 a)
	{
		x -= a.x;
		y -= a.y;
		return this;
	}

};

/**
Overloads the - operator
Overloads the - operator allowing a Vec2 to be inverted
@param a The input Vec2
@returns The new vector.
*/
inline JAM_Vec2 operator - (JAM_Vec2 a)
{
	JAM_Vec2 b;
	b.x = -a.x;
	b.y = -a.y;
	return b;
}

/**
Overloads the + operator
Overloads the + operator allowing Vec2's to be added to each other
@param a One of the input Vec2's
@param b One of the input Vec2's
@returns The new vector.
*/
inline JAM_Vec2 operator + (JAM_Vec2 a, JAM_Vec2 b)
{
	JAM_Vec2 c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

/**
Overloads the - operator
Overloads the - operator allowing Vec2's to be subtracted from each other
@param a One of the input Vec2's
@param b One of the input Vec2's
@returns The new vector.
*/
inline JAM_Vec2 operator - (JAM_Vec2 a, JAM_Vec2 b)
{
	JAM_Vec2 c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

/**
Overloads the / operator
Overloads the / operator allowing a Vec2 to be divided by a scalar
@param a One of the input Vec2's
@param b the scalar to divide by
@returns The new vector.
*/
inline JAM_Vec2 operator / (JAM_Vec2 a, float b)
{
	JAM_Vec2 c;
	c.x = a.x / b;
	c.y = a.y / b;
	return c;
}

/**
Overloads the * operator
Overloads the * operator allowing a Vec2 to be multiplied by a scalar
@param a One of the input Vec2's
@param b the scalar to multiply by
@returns The new vector.
*/
inline JAM_Vec2 operator * (JAM_Vec2 a, float b)
{
	JAM_Vec2 c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}