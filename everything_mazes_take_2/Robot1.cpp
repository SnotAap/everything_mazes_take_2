#include "Header.h"

Robot1::Robot1(Grid& grid, sf::Font font_, std::vector<std::shared_ptr<Object>>& renderList)
{
	tileSize = grid.tileMap[grid.startAndEndCords.first]->size.x;
	size = sf::Vector2f((tileSize / 1.5f), (tileSize / 1.5f));
	shape.setSize(size);
	shape.setOrigin(sf::Vector2f((size.x / 2), (size.y / 2)));
	gridOffset = sf::Vector2f((grid.tileMap[grid.startAndEndCords.first]->position.x + tileSize / 2), (grid.tileMap[grid.startAndEndCords.first]->position.y + tileSize / 2));
	position = gridOffset;
	shape.setPosition(position);
	font = font_;
	gridPos = grid.startAndEndCords.first;
	color = sf::Color::Green;
	shape.setFillColor(color);
	nodes =  setupNodes(grid);
	setupWalls(grid, renderList);
	grid.tileMap[gridPos]->color = sf::Color::Red;
	grid.tileMap[gridPos]->shape.setFillColor(grid.tileMap[gridPos]->color);
	nodes[gridPos]->visited = true;
	traversedTiles[gridPos] = true;
}

void Robot1::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

std::map<cordinates, std::shared_ptr<Node>> Robot1::setupNodes(Grid& grid)
{
	//Node *nodes = nullptr;
	//initialising all nodes;
	std::map<cordinates, std::shared_ptr<Node>> nodes;
	//initializing nodes.
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates Cords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<Node> nodePtr = std::make_shared<Node>(x, y);
			nodes[Cords] = nodePtr;

		}
	}
	//create connections between the nodes, (the neighbors)
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates myCords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<Node> northNeighbor;
			std::shared_ptr<Node> eastNeighbor;
			std::shared_ptr<Node> southNeighbor;
			std::shared_ptr<Node> westNeighbor;
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
			std::shared_ptr<Node> myneighbors[4] = { northNeighbor, eastNeighbor, southNeighbor, westNeighbor };
			for (int i = 0; i < 4; i++)
			{
				nodes[myCords]->setNeighbor(i, myneighbors[i]);
			}

		}
	}

	return nodes;
}

void Robot1::setupWalls(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList)
{
	//
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			float positionX = float((grid.plane->position.x - (grid.plane->size.x / 2) + (x * (grid.tileSize))));
			float positionY = float((grid.plane->position.y - (grid.plane->size.y / 2) + (y * (grid.tileSize))));
			//			
			cordinates myCords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<Wall> wallN = std::make_shared<Wall>(float(positionX), float(positionY), float(tileSize), float(3), 0.0f, sf::Color::Yellow);
			wallN->active = false;
			std::shared_ptr<Wall> wallE = std::make_shared<Wall>(float(positionX + tileSize), float(positionY + tileSize), float(tileSize), float(3), 270.0f, sf::Color::Yellow);
			wallE->active = false;
			std::shared_ptr<Wall> wallS = std::make_shared<Wall>(float(positionX + tileSize), float(positionY + tileSize), float(tileSize), float(3), 180.0f, sf::Color::Yellow);
			wallS->active = false;
			std::shared_ptr<Wall> wallW = std::make_shared<Wall>(float(positionX), float(positionY), float(tileSize), float(3), 90.0f, sf::Color::Yellow);
			wallW->active = false;
			//
			std::shared_ptr<Wall> myWalls[4] = { wallN, wallE, wallS, wallW };
			for (int i = 0; i < 4; i++)
			{
				robotWallMap[myCords][i] = myWalls[i];
				renderList.emplace_back(robotWallMap[myCords][i]);
			}
			//
		}
	}
	//
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates myCords = std::pair<int, int>(std::make_pair(x, y));
			//
			if (x > 0)
			{
				cordinates prevXCords = std::pair<int, int>(std::make_pair(x - 1, y));
				robotWallMap[myCords][West] = robotWallMap[prevXCords][East];
			}
			if (y > 0)
			{
				cordinates prevYCords = std::pair<int, int>(std::make_pair(x, y - 1));
				robotWallMap[myCords][North] = robotWallMap[prevYCords][South];
			}
			//
			if (x < grid.sizeX - 1)
			{
				cordinates nextXCords = std::pair<int, int>(std::make_pair(x + 1, y));
				robotWallMap[myCords][East] = robotWallMap[nextXCords][West];
			}
			if (y < grid.sizeY - 1)
			{
				cordinates nextYCords = std::pair<int, int>(std::make_pair(x, y + 1));
				robotWallMap[myCords][South] = robotWallMap[nextYCords][North];
			}

		}
	}


}

void Robot1::updateWallMap(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList)
{
	//std::shared_ptr<Wall> myWalls[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	robotWallMap[gridPos][i]->active = grid.wallMap[gridPos][i]->active;
	//}
	std::vector<cordinates> visibleTiles;
	visibleTiles.emplace_back(gridPos);
	std::vector<std::shared_ptr<Wall>[4]>myWalls;

	bool wall = false;	
	cordinates prevCords = gridPos;
	cordinates myCords;
	while (!wall) //North.
	{	
		if (prevCords.second > 0)
		{
			myCords = std::pair<int, int>(prevCords.first, prevCords.second - 1);
			if (!grid.wallMap[prevCords][nodes[prevCords]->getSide(nodes[myCords])]->active)
			{
				if (!seenTiles[myCords])
				{
					visibleTiles.emplace_back(myCords);
					prevCords = myCords;
				}
				else wall = true;
			}
			else wall = true;
		}
		else wall = true;			
	}
	wall = false;
	prevCords = gridPos;

	while (!wall) //East.
	{
		if(prevCords.first < grid.sizeX - 1)
		{
			myCords = std::pair<int, int>(prevCords.first + 1, prevCords.second);
			if (!grid.wallMap[prevCords][nodes[prevCords]->getSide(nodes[myCords])]->active)
			{
				if (!seenTiles[myCords])
				{
					visibleTiles.emplace_back(myCords);
					prevCords = myCords;
				}
				else wall = true;
			}
			else wall = true;
		}
		else wall = true;
	}
	wall = false;
	prevCords = gridPos;

	while (!wall) //South.
	{
		if (prevCords.second < grid.sizeY - 1)
		{
			myCords = std::pair<int, int>(prevCords.first, prevCords.second + 1);
			if (!grid.wallMap[prevCords][nodes[prevCords]->getSide(nodes[myCords])]->active)
			{
				if (!seenTiles[myCords])
				{
					visibleTiles.emplace_back(myCords);
					prevCords = myCords;
				}
				else wall = true;
			}
			else wall = true;
		}
		else wall = true;
	}

	wall = false;
	prevCords = gridPos;

	while (!wall) //West.
	{
		if (prevCords.first > 0)
		{
			myCords = std::pair<int, int>(prevCords.first - 1, prevCords.second);
			if (!grid.wallMap[prevCords][nodes[prevCords]->getSide(nodes[myCords])]->active)
			{
				if (!seenTiles[myCords])
				{
					visibleTiles.emplace_back(myCords);
					prevCords = myCords;
				}
				else wall = true;
			}
			else wall = true;
		}
		else wall = true;
	}
	

	for (int i = 0; i < visibleTiles.size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			robotWallMap[visibleTiles[i]][j]->active = grid.wallMap[visibleTiles[i]][j]->active;
			if (!traversedTiles[visibleTiles[i]])
			{
				grid.tileMap[visibleTiles[i]]->color = sf::Color(255, 165, 0, 255);
				grid.tileMap[visibleTiles[i]]->shape.setFillColor(sf::Color(255, 165, 0, 255));				
			}
		}
		seenTiles[visibleTiles[i]] = true;
		
	}
}

void Robot1::pathSolvingFloodFill(Grid& grid)
{
	//
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates myCords = std::pair<int, int>(x, y);
			for (int i = 0; i < 4; i++)
			{
				nodes[myCords]->visited = false;
			}

		}
	}
	queue.emplace_back(nodes[grid.startAndEndCords.second]);
	nodes[grid.startAndEndCords.second]->visited = true;
	grid.depthList.clear();
	floodedMaze.clear();
	depth = -1;
	while (floodedMaze.size() != (grid.sizeX * grid.sizeY))
	{
		depth++;

		for (int i = 0; i < toBeRemoved.size(); i++)
		{
			queue.remove(toBeRemoved[i]);
		}
		for (int i = 0; i < toBeAdded.size(); i++)
		{
			queue.emplace_back(toBeAdded[i]);
		}
		toBeRemoved.clear();
		toBeAdded.clear();

		//give a rating to each adjecent tile.
		for (std::list<std::shared_ptr<Node>>::iterator it = queue.begin(); it != queue.end(); ++it)
		{
			floodedMaze[(*it)->position] = depth;
			sf::Vector2f position = sf::Vector2f(grid.tileMap[(*it)->position]->shape.getPosition().x + (grid.tileSize / 10), grid.tileMap[(*it)->position]->shape.getPosition().y + (grid.tileSize / 10));
			//sf::Vector2f position = sf::Vector2f(grid.tileMap[(*it)->position]->shape.getPosition().x, grid.tileMap[(*it)->position]->shape.getPosition().y);
			double scale = double(grid.tileSize) / double(130.0);
			sf::Vector2f textScale = sf::Vector2f(float(scale), float(scale));
			std::shared_ptr<Text> myText = std::make_shared<Text>(std::to_string(depth), font, textScale, position);
			grid.depthList.emplace_back(myText);
			//update the queue

			for (int i = 0; i < 4; i++)
			{
				if ((*it)->getNeighbor(i) != nullptr)
				{
					if (!nodes[(*it)->getNeighbor(i)->position]->visited && !robotWallMap[nodes[(*it)->position]->position][nodes[(*it)->position]->getSide((*it)->getNeighbor(i))]->active)
					{
						toBeAdded.emplace_back(nodes[(*it)->getNeighbor(i)->position]);
						nodes[(*it)->getNeighbor(i)->position]->visited = true;

					}
				}
			}
			//remove rated tile
			toBeRemoved.emplace_back(*it);
		}

	}

}

int Robot1::getDirection(Grid& grid)
{
	std::list<std::pair<cordinates, int>> neighbors;
	for (int i = 0; i < 4; i++)
	{
		if (nodes[gridPos]->getNeighbor(i) != nullptr)
		{
			if (!robotWallMap[gridPos][nodes[gridPos]->getSide(nodes[gridPos]->getNeighbor(i))]->active)
			{
				if (traversedTiles[nodes[gridPos]->getNeighbor(i)->position])
				{
					neighbors.emplace_back(std::pair<cordinates, int>(nodes[gridPos]->getNeighbor(i)->position, floodedMaze[nodes[gridPos]->getNeighbor(i)->position] + 1));
				}
				else
				{
					neighbors.emplace_back(std::pair<cordinates, int>(nodes[gridPos]->getNeighbor(i)->position, floodedMaze[nodes[gridPos]->getNeighbor(i)->position]));
				}			

			}
		}
	}
	neighbors.sort([](const std::pair<cordinates, int> lhs, const std::pair<cordinates, int> rhs) {return lhs.second < rhs.second; });
	
	return nodes[gridPos]->getSide(nodes[neighbors.front().first]);
		
}

void Robot1::movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList)
{
	if (!moving)
	{
		updateWallMap(grid, renderList);
		pathSolvingFloodFill(grid);
		movingDirection = getDirection(grid);
		setFuturePosition();
		move(deltaTime);
		moving = true;
	}
	else
	{
		if (move(deltaTime))
		{
			moving = false;
			traversedTiles[gridPos] = true;
			grid.tileMap[gridPos]->color = sf::Color::Red;
			grid.tileMap[gridPos]->shape.setFillColor(sf::Color::Red);
		}
	}
}