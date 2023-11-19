#include "Header.h"

Node::Node(int xPos, int yPos)
{
	position = std::pair<int, int>(std::make_pair(xPos, yPos));
}

Node::~Node()
{

}

int Node::getSide(std::shared_ptr<Node> neighbor)
{
	int side = -1;
	if (position.first > neighbor->position.first)
	{
		side = West;
	}
	if (position.first < neighbor->position.first)
	{
		side = East;
	}
	if (position.second < neighbor->position.second)
	{
		side = South;
	}
	if (position.second > neighbor->position.second)
	{
		side = North;
	}
	return side;
}



std::shared_ptr<Node> Node::getNeighbor(int index) 
{ 
	return neighbors[index];
}

void Node::setNeighbor(int index, std::shared_ptr<Node> neighbor)
{
	neighbors[index] = neighbor;
}

MazeNode::MazeNode(int xPos, int yPos) : Node(xPos, yPos)
{
	position = std::pair<int, int>(std::make_pair(xPos, yPos));
}

MazeNode::~MazeNode()
{

}

int MazeNode::getSide(std::shared_ptr<MazeNode> neighbor)
{
	int side = -1;
	if (position.first > neighbor->position.first)
	{
		side = West;
	}
	if (position.first < neighbor->position.first)
	{
		side = East;
	}
	if (position.second < neighbor->position.second)
	{
		side = South;
	}
	if (position.second > neighbor->position.second)
	{
		side = North;
	}
	return side;
}

std::shared_ptr<MazeNode> MazeNode::getNeighbor(int index)
{	
	return std::static_pointer_cast<MazeNode>(neighbors[index]);
}

void MazeNode::setNeighbor(int index, std::shared_ptr<Node> neighbor)
{
	neighbors[index] = neighbor;
}



AStarNode::AStarNode(int xPos, int yPos) : Node(xPos, yPos)
{
	position = std::pair<int, int>(std::make_pair(xPos, yPos));
	visited = false;
}

AStarNode::~AStarNode()
{

}

int AStarNode::getSide(std::shared_ptr<AStarNode> neighbor)
{
	int side = -1;
	if (position.first > neighbor->position.first)
	{
		side = West;
	}
	if (position.first < neighbor->position.first)
	{
		side = East;
	}
	if (position.second < neighbor->position.second)
	{
		side = South;
	}
	if (position.second > neighbor->position.second)
	{
		side = North;
	}
	return side;
}

std::shared_ptr<AStarNode> AStarNode::getNeighbor(int index)
{
	return neighbors[index];
}

void AStarNode::setNeighbor(int index, std::shared_ptr<AStarNode> neighbor)
{
	neighbors[index] = neighbor;
}