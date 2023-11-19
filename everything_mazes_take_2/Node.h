#pragma once

class Node
{
protected:
	std::shared_ptr<Node> neighbors[4];
public:

	cordinates position;
	bool visited = false;

	Node(int xPos, int yPos);
	~Node();

	int getSide(std::shared_ptr<Node> neighbor);

	std::shared_ptr<Node> getNeighbor(int index);
	void setNeighbor(int index, std::shared_ptr<Node> neighbor);

};

class MazeNode : public Node
{
public:
 	bool partOfMaze = false;
	bool partOfFrontier = false;


	MazeNode(int xPos, int yPos);
	~MazeNode();
	int getSide(std::shared_ptr<MazeNode> neighbor);
	
	std::shared_ptr<MazeNode> getNeighbor(int index);
	void setNeighbor(int index, std::shared_ptr<Node> neighbor);
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

	AStarNode(int xPos, int yPos);
	~AStarNode();

	int getSide(std::shared_ptr<AStarNode> neighbor);

	std::shared_ptr<AStarNode> getNeighbor(int index);
	void setNeighbor(int index, std::shared_ptr<AStarNode> neighbor);
};
