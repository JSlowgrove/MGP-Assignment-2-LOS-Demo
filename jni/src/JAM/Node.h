#pragma once

/**
@brief Creates a Node object for use with path finding.
Reference ~ This is a modified version of my nodes from my AI assignment.
*/
class JAM_Node
{
private:
	/**The index of the parent node.*/
	int parentNodeXIndex;
	int parentNodeYIndex;
	/**The index of the node.*/
	int nodeXIndex;
	int nodeYIndex;
	/**Boolean values to if they are a specific node.*/
	bool startNode;
	bool endNode;
	/**If the node safe to walk on.*/
	bool safe;
	/**The cost to move to the node.*/
	int cost;
	/**The f score of the node.*/
	int fScore;
	/**Boolean values for if the node is on a list.*/
	bool listed;

public:
	/**
	Constructs a Node object.
	@param nodeXIndex The Node x index.
	@param nodeYIndex The Node y index.
	*/
	JAM_Node(int nodeXIndex, int nodeYIndex);

	/**
	Destructs a Game object.
	*/
	~JAM_Node();

	/**
	Setter # Set the parentNode index.
	@param parentNodeXIndex The X index of the parentNode.
	@param parentNodeYIndex The Y index of the parentNode.
	*/
	void setParentIndex(int parentNodeXIndex, int parentNodeYIndex);

	/**
	Getter # Get the parentNode X index.
	@return The X index of the parentNode.
	*/
	int getParentXIndex();

	/**
	Getter # Get the parentNode Y index.
	@return The Y index of the parentNode.
	*/
	int getParentYIndex();

	/**
	Setter # Set the node.
	@param startNode The setting of the node.
	*/
	void setStartNode(bool startNode);

	/**
	Getter # Get If the node is a startNode.
	@return If the node is a startNode.
	*/
	bool getStartNode();

	/**
	Setter # Set the node.
	@param bool The setting of the node.
	*/
	void setEndNode(bool endNode);

	/**
	Getter # Get If the node is an endNode.
	@return If the node is an endNode.
	*/
	bool getEndNode();

	/**
	Setter # Set the node.
	@param safe The setting of the node.
	*/
	void setSafeNode(bool safe);

	/**
	Getter # Get If the node is safe.
	@return If the node is safe.
	*/
	bool getSafeNode();

	/**
	Setter # Set the cost.
	@param cost The cost to move to the node.
	*/
	void setCostNode(int cost);

	/**
	Getter # Get the cost.
	@return The cost to move to the node.
	*/
	int getCostNode();

	/**
	Setter # Set the fScore.
	@param fScore The fScore to of the node.
	*/
	void setFScoreNode(int fScore);

	/**
	Getter # Get the fScore.
	@return The fScore to of the node.
	*/
	int getFScoreNode();

	/**
	Getter # Get the x index.
	@return The x index of the node.
	*/
	int getXIndex();

	/**
	Getter # Get the y index.
	@return The y index of the node.
	*/
	int getYIndex();

	/**
	Setter # Set the value of listed.
	@param listed If the node is listed.
	*/
	void setListed(bool listed);

	/**
	Getter # Get the value of listed.
	@return If the node is listed.
	*/
	bool getListed();
};