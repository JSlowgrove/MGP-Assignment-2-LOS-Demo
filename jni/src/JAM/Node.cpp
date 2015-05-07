#include "Node.h"

/**************************************************************************************************************/

/*Constructs the node object*/
JAM_Node::JAM_Node(int nodeXIndex, int nodeYIndex)
{
	/*initialise the booleans*/
	startNode = false;
	endNode = false;
	listed = false;
	safe = true;

	/*initialise the variables*/
	this->nodeXIndex = nodeXIndex;
	this->nodeYIndex = nodeYIndex;
	parentNodeXIndex = 0;
	parentNodeYIndex = 0;
	cost = 0;
	fScore = 0;
}


/**************************************************************************************************************/

/*Destructs the node object*/
JAM_Node::~JAM_Node()
{
}

/**************************************************************************************************************/

/*set the parent node index*/
void JAM_Node::setParentIndex(int parentNodeXIndex, int parentNodeYIndex)
{
	/*set the variables to the input*/
	this->parentNodeXIndex = parentNodeXIndex;
	this->parentNodeYIndex = parentNodeYIndex;
}

/**************************************************************************************************************/

/*get the parent node x index*/
int JAM_Node::getParentXIndex()
{
	/*return the x parent node index*/
	return parentNodeXIndex;
}

/**************************************************************************************************************/

/*get the parent node y index*/
int JAM_Node::getParentYIndex()
{
	/*return the y parent node index*/
	return parentNodeYIndex;
}

/**************************************************************************************************************/

/*set the startNode*/
void JAM_Node::setStartNode(bool startNode)
{
	/*set the node*/
	this->startNode = startNode;
}

/**************************************************************************************************************/

/*get if the node is a startNode*/
bool JAM_Node::getStartNode()
{
	/*return startNode*/
	return startNode;
}

/**************************************************************************************************************/

/*set the endNode*/
void JAM_Node::setEndNode(bool endNode)
{
	/*set the node*/
	this->endNode = endNode;
}

/**************************************************************************************************************/

/*get if the node is an endNode*/
bool JAM_Node::getEndNode()
{
	/*return endNode*/
	return endNode;
}

/**************************************************************************************************************/

/*set the safe*/
void JAM_Node::setSafeNode(bool safe)
{
	/*set the node*/
	this->safe = safe;
}

/**************************************************************************************************************/

/*get if the node is an safe*/
bool JAM_Node::getSafeNode()
{
	/*return safeNode*/
	return safe;
}

/**************************************************************************************************************/

/*set the cost*/
void JAM_Node::setCostNode(int cost)
{
	/*set the node cost*/
	this->cost = cost;
}

/**************************************************************************************************************/

/*get the cost*/
int JAM_Node::getCostNode()
{
	/*return the node cost*/
	return cost;
}

/**************************************************************************************************************/

/*set the fScore*/
void JAM_Node::setFScoreNode(int fScore)
{
	/*set the node fScore*/
	this->fScore = fScore;
}

/**************************************************************************************************************/

/*get the fScore*/
int JAM_Node::getFScoreNode()
{
	/*return the node fScore*/
	return fScore;
}

/**************************************************************************************************************/

/*get the x index*/
int JAM_Node::getXIndex()
{
	/*return the node x index*/
	return nodeXIndex;
}

/**************************************************************************************************************/

/*get the y index*/
int JAM_Node::getYIndex()
{
	/*return the node y index*/
	return nodeYIndex;
}

/**************************************************************************************************************/

/*set the listed*/
void JAM_Node::setListed(bool listed)
{
	/*set the node*/
	this->listed = listed;
}

/**************************************************************************************************************/

/*get if the node is listed*/
bool JAM_Node::getListed()
{
	/*return listed*/
	return listed;
}