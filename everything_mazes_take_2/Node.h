#pragma once

//all node classes


class Node
{
protected:
	std::shared_ptr<Node> neighbors[4];
public:

	cordinates position;
	bool visited = false;

	Node(int xPos, int yPos);												//constructor

	int getSide(std::shared_ptr<Node> neighbor);							//getting the side of a neighbor node relelative to the current node
		
	std::shared_ptr<Node> getNeighbor(int index);							//acces a certain neighbors memory
	void setNeighbor(int index, std::shared_ptr<Node> neighbor);			//sets a neighbor of Node

};

class MazeNode : public Node
{
public:
 	bool partOfMaze = false;
	bool partOfFrontier = false;


	MazeNode(int xPos, int yPos);											//constructor							
	int getSide(std::shared_ptr<MazeNode> neighbor);						//getting the side of a neighbor node relelative MazeNode
	
	std::shared_ptr<MazeNode> getNeighbor(int index);						//acces a certain neighbors memory
	void setNeighbor(int index, std::shared_ptr<Node> neighbor);			//sets a neighbor of the current Node
};

class AStarNode : public Node
{
public:
	double gCost;				//distance to starnode.
	double fCost;				//distance to finishnode.
	double hCost;				//combinde value of gCost and fCost.
	std::shared_ptr<AStarNode> parent;
	std::shared_ptr<AStarNode> child;
	std::shared_ptr<AStarNode> neighbors[4];

	AStarNode(int xPos, int yPos);											//constructor
			
	int getSide(std::shared_ptr<AStarNode> neighbor);						//getting the side of a neighbor node relelative to AStarNode

	std::shared_ptr<AStarNode> getNeighbor(int index);						//acces a certain neighbors memory
	void setNeighbor(int index, std::shared_ptr<AStarNode> neighbor);		//sets a neighbor of the current Node
};
