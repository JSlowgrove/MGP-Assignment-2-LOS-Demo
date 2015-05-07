#pragma once

#include <math.h>
#include "Vec2.h"

/**
@brief A Namespace that contains functions for the collision detection.
@author Jamie Slowgrove
*/
namespace JAM_CollisionDetection
{
	/**
	CollisionDetection between two rectangles.
	@param positionA The position of the first rectangle.
	@param dimensionsA The dimensions of the first rectangle.
	@param positionB The position of the second rectangle.
	@param dimensionsB The dimensions of the second rectangle.
	@returns If the rectangles intersect.
	*/
	bool collisionRectRectDetection(JAM_Vec2 positionA, JAM_Vec2 dimensionsA, JAM_Vec2 positionB, JAM_Vec2 dimensionsB);

	/**
	CollisionDetection between two circles.
	@param positionA The position of the first circle.
	@param radiusA The radius of the first circle.
	@param positionB The position of the second circle.
	@param radiusB The radius of the second circle.
	@returns If the circles intersect.
	*/
	bool collisionCircleCircleDetection(JAM_Vec2 positionA, float radiusA, JAM_Vec2 positionB, float radiusB);
};