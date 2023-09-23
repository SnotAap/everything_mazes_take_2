#include "Header.h"

double distance(cordinates start, cordinates end)
{
	return double(sqrt((pow(end.first, 2) - pow(start.first, 2)) + (pow(end.second, 2) - pow(start.second, 2))));
}

std::vector<cordinates> pathSolvingAStar(Grid& grid)
{
	//Node *nodes = nullptr;

	std::vector<cordinates> path;
	int startPosX = grid.startAndEndCords.first.first;
	int startPosY = grid.startAndEndCords.first.second;
	int endPosX = grid.startAndEndCords.second.first;
	int endkPosY = grid.startAndEndCords.second.second;
	//


	//initialising all nodes;
	std::map<cordinates, std::shared_ptr<AStarNode>> nodes;
	//initializing nodes.
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates Cords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<AStarNode> nodePtr = std::make_shared<AStarNode>(x, y);
			nodes[Cords] = nodePtr;
		}
	}


	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates myCords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<AStarNode> NodePtr = std::make_shared<AStarNode>(x, y);
			nodes[myCords]->parent = nullptr;
			nodes[myCords]->gCost = INFINITY;
			nodes[myCords]->fCost = INFINITY;
		}
	}
	//
	std::shared_ptr<AStarNode> startNode = nodes[grid.startAndEndCords.first];
	std::shared_ptr<AStarNode> finishNode = nodes[grid.startAndEndCords.second];

	std::shared_ptr<AStarNode> currentNode;
	startNode->gCost= 0.0f;
	startNode->fCost = distance(startNode->position, finishNode->position);
	currentNode = startNode;

	std::list<std::shared_ptr<AStarNode>> listNotTestedNodes;
	listNotTestedNodes.push_back(startNode);
	//create connections between the nodes, (the neighbors)
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates myCords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<AStarNode> northNeighbor;
			std::shared_ptr<AStarNode> eastNeighbor;
			std::shared_ptr<AStarNode> southNeighbor;
			std::shared_ptr<AStarNode> westNeighbor;
			//
			if (x > 0)
			{
				cordinates prevXCords = std::pair<int, int>(std::make_pair(x - 1, y));
				westNeighbor = nodes[prevXCords];
			}
			if (y > 0)
			{
				cordinates prevYCords = std::pair<int, int>(std::make_pair(x, y - 1));
				northNeighbor = nodes[prevYCords];
			}
			if (x < grid.sizeX - 1)
			{
				cordinates nextXCords = std::pair<int, int>(std::make_pair(x + 1, y));
				eastNeighbor = nodes[nextXCords];
			}
			if (y < grid.sizeY - 1)
			{
				cordinates nextYCords = std::pair<int, int>(std::make_pair(x, y + 1));
				southNeighbor = nodes[nextYCords];
			}
			//
			std::shared_ptr<AStarNode> myneighbors[4] = { northNeighbor, eastNeighbor, southNeighbor, westNeighbor };
			for (int i = 0; i < 4; i++)
			{
				nodes[myCords]->setNeighbor(i, myneighbors[i]);
			}
		}
	}
	//
	while (!listNotTestedNodes.empty() && currentNode != finishNode)
	{
		listNotTestedNodes.sort([](const std::shared_ptr<AStarNode> lhs, const std::shared_ptr<AStarNode> rhs) {return lhs->hCost < rhs->hCost; });
		while (!listNotTestedNodes.empty() && listNotTestedNodes.front()->visited)
		{
			listNotTestedNodes.pop_front();
		}

		if (listNotTestedNodes.empty()) break;

		currentNode = listNotTestedNodes.front();
		currentNode->visited = true;

		for (auto nodeNeightbour : currentNode->neighbors)
		{
			if (nodeNeightbour != nullptr)
			{
				if (!nodeNeightbour->visited && !grid.wallMap[currentNode->position][currentNode->getSide(nodeNeightbour)]->active)
				{
					listNotTestedNodes.push_back(nodeNeightbour);
				}


				float possiblyLowerGoal = currentNode->gCost + distance(currentNode->position, nodeNeightbour->position);

				if (possiblyLowerGoal < nodeNeightbour->gCost)
				{
					nodeNeightbour->parent = currentNode;
					nodeNeightbour->gCost = possiblyLowerGoal;
					nodeNeightbour->hCost = nodeNeightbour->gCost + distance(nodeNeightbour->position, finishNode->position);
				}
			}
		}
	}

	//loop through the correct tiles.
	std::shared_ptr<AStarNode> p = finishNode;
	while (p->parent != nullptr)
	{

		grid.tileMap[p->position]->color = sf::Color::Black;
		path.emplace_back(p->position);
		p = p->parent;
	}
	
	//return the solved path

	return path;
}
