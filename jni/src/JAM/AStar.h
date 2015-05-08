#pragma once

#include <SDL.h>
#include <vector>
#include "Vec2.h"
#include "Node.h"

/**
@brief Creates an object for A* path finding.
@author Jamie Slowgrove
Reference ~ This is a modified version of my A* path-finding from my AI assignment.
*/
class JAM_AStar
{
private:
	/**The arrays of Nodes.*/
	std::vector<std::vector<JAM_Node*>> nodes;
	/**The open list of Nodes.*/
	std::vector<JAM_Node> openList;
	/**The closed list of Nodes.*/
	std::vector<JAM_Node> closedList;
	/**The array of Nodes for the best path.*/
	std::vector<JAM_Node> bestPath;
	/**The number of nodes.*/
	int xNodes, yNodes;
	/**The current node index.*/
	int currentX, currentY;
	/**The end node index.*/
	int endX, endY;
	/**The start node index.*/
	int startX, startY;
	/**The Dimensions of a node.*/
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
	Constructs the AStar object.
	@param xNodes The number of nodes in a row.
	@param yNodes The number of rows in the map.
	@param nodeWidth The width of a node.
	@param nodeHeight The height of a node.
	*/
	JAM_AStar(int xNodes, int yNodes, float nodeWidth, float nodeHeight);

	/**
	Destructs the AStar object.
	*/
	~JAM_AStar();

	/**
	Setter # Sets the Node at the inputed index to a danger Node.
	@param nodeXIndex The x index of the Node.
	@param nodeYIndex The y index of the Node.
	*/
	void setDangerNode(int nodeXIndex, int nodeYIndex);

	/**
	Setter # Sets the Node at the inputed index to a safe Node.
	@param nodeXIndex The x index of the Node.
	@param nodeYIndex The y index of the Node.
	*/
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
	Getter # Gets the position of the next node in the path.
	@returns The Node position.
	*/
	JAM_Vec2 getNextPathNode();

	/**
	Displays the open and closed lists.
	@param renderer A pointer to the renderer.
	*/
	void drawLists(SDL_Renderer* renderer);
};