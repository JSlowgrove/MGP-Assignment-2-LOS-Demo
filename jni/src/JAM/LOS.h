#pragma once

#include <SDL.h>
#include <time.h>
#include <vector>
#include "Vec2.h"
#include "Node.h"

/**
@brief A Namespace that contains functions for the Line Of Sight.
@author Jamie Slowgrove
Reference ~ This is a modified version of my LOS from my AI assignment.
*/
namespace JAM_LOS
{
	/**
	Check if two positions can see each other.
	@param a Position a.
	@param b Position b.
	@param map A 2D vector of nodes. 
	@param nodeSize The size of the node.
	@return If the position can see each other.
	*/
	bool lineOfSight(JAM_Vec2 a, JAM_Vec2 b, std::vector<std::vector<JAM_Node*>> map, int nodeSize);

	/**
	Check if two lines intersect.
	@param a Position a. (line 1)
	@param b Position b. (line 1)
	@param v Position c. (line 2)
	@param d Position d. (line 2)
	@param axis Axis that the second line being tested is on.
	@return If the lines intersect.
	*/
	bool lineLineIntersectionCheck(JAM_Vec2 a, JAM_Vec2 b, JAM_Vec2 c, JAM_Vec2 d, char axis);

	/**
	Check if two positions can see each other and draw the tested tiles.
	@param a Position a.
	@param b Position b.
	@param map A 2D vector of nodes.
	@param nodeSize The size of the node.
	@param renderer A pointer to the renderer.
	*/
	void drawLineOfSight(JAM_Vec2 a, JAM_Vec2 b, std::vector<std::vector<JAM_Node*>> map, int nodeSize, SDL_Renderer* renderer);

	/**
	Find a new target position to go to.
	@param a Position a.
	@param map A 2D vector of nodes.
	@param nodeSize The size of the node.
	@return The new target position.
	*/
	JAM_Vec2 getNewTarget(JAM_Vec2 a, std::vector<std::vector<JAM_Node*>> map, int nodeSize);
}