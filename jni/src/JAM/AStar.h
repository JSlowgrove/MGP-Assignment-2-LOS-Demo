#pragma once

#include <SDL.h>
#include <vector>
#include "Vec2.h"
#include "Node.h"

/**
@brief Creates an object for A* path finding.
Reference ~ This is a modified version of my A* path-finding from my AI assignment.
*/
class JAM_AStar
{
private:
	/**The arrays of Nodes.*/
	std::vector<std::vector<JAM_Node*>> nodes;
	std::vector<JAM_Node> openList;
	std::vector<JAM_Node> closedList;
	std::vector<JAM_Node> bestPath;
	/**The number of nodes.*/
	int xNodes;
	int yNodes;
	/**The current node index.*/
	int currentX;
	int currentY;
	/**The end node index.*/
	int endX;
	int endY;
	/**The start node index.*/
	int startX;
	int startY;
	/**The Dimensions of a node*/
	JAM_Vec2 nodeDimensions;

	/**
	Check the surrounding nodes.
	@param parentX The parent node x index value.
	@param parentY The parent node y index value.
	*/
	void checkNodes(int parentX, int parentY);

	/**
	Test the node for the open list setup.
	@param parentX The parent x index value.
	@param parentY The parent y index value.
	@param testX The test x index value.
	@param testY The test y index value.
	@param cost The cost to add to the node.
	*/
	void nodeTest(int parentX, int parentY, int testX, int testY, int cost);

	/**
	Find the next node.
	*/
	void findNextNode();

	/**
	Find the best path.
	*/
	void findBestPath();

public:
	/**
	Constructs an AStar object.
	@param xNodes The number of nodes in a row.
	@param yNodes The number of rows in the map.
	@param nodeWidth The width of a node.
	@param nodeHeight The height of a node.
	*/
	JAM_AStar(int xNodes, int yNodes, float nodeWidth, float nodeHeight);

	/**
	Destructs an AStar object.
	*/
	~JAM_AStar();

	void setDangerNode(int nodeXIndex, int nodeYIndex);

	void setSafeNode(int nodeXIndex, int nodeYIndex);

	/**
	Finds a new path to follow.
	@param startX The start x index value.
	@param startY The start y index value.
	@param endX The end x index value.
	@param endY The end y index value.
	*/
	void findNewPath(int startX, int startY, int endX, int endY);

	/**
	Returns the position of the next node in the path.
	@returns The Node position.
	*/
	JAM_Vec2 getNextPathNode();

	/**
	Displays the open and closed lists.
	@param renderer A pointer to the renderer.
	*/
	void drawLists(SDL_Renderer* renderer);
};