#include "Header.h"


Robot0::Robot0(Grid grid)
{
	tileSize = grid.tileMap[grid.startAndEndCords.first]->size.x;
	size = sf::Vector2f((tileSize / 1.5f), (tileSize / 1.5f));
	shape.setSize(size);
	shape.setOrigin(sf::Vector2f((size.x / 2), (size.y / 2)));
	gridOffset = sf::Vector2f((grid.tileMap[grid.startAndEndCords.first]->position.x + tileSize / 2), (grid.tileMap[grid.startAndEndCords.first]->position.y + tileSize / 2));
	position = gridOffset;
	shape.setPosition(position);
	gridPos = grid.startAndEndCords.first;
	color = sf::Color::Yellow;
	shape.setFillColor(color);

	setupNodeMap(grid);
	exploredTiles.emplace_back(gridPos);
	currentTile = exploredTiles.begin();
	nodeMap[gridPos]->visited = true;
	grid.tileMap[gridPos]->color = sf::Color::Red;
	grid.tileMap[gridPos]->shape.setFillColor(grid.tileMap[gridPos]->color);
}

Robot0::~Robot0()
{

}

void Robot0::setupNodeMap(Grid grid)
{
	for (int x = 0; x < grid.sizeX; x++)
	{
		for (int y = 0; y < grid.sizeY; y++)
		{
			cordinates Cords = std::pair<int, int>(std::make_pair(x, y));
			std::shared_ptr<Node> mazeNodePtr = std::make_shared<Node>(x, y);
			nodeMap[Cords] = mazeNodePtr;
		}
	}
	//setting up neighbors.
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
				westNeighbor = nodeMap[prevXCords];
			}
			if (y > 0)
			{
				cordinates prevYCords = std::pair<int, int>(std::make_pair(x, y - 1));
				northNeighbor = nodeMap[prevYCords];
			}
			if (x < grid.sizeX - 1)
			{
				cordinates nextXCords = std::pair<int, int>(std::make_pair(x + 1, y));
				eastNeighbor = nodeMap[nextXCords];
			}
			if (y < grid.sizeY - 1)
			{
				cordinates nextYCords = std::pair<int, int>(std::make_pair(x, y + 1));
				southNeighbor = nodeMap[nextYCords];
			}
			//
			std::shared_ptr<Node> myneighbors[4] = { northNeighbor, eastNeighbor, southNeighbor, westNeighbor };
			for (int i = 0; i < 4; i++)
			{
				//nodeMap[myCords]->neighbors[i] = myneighbors[i];
				nodeMap[myCords]->setNeighbor(i, myneighbors[i]);
			}
		}
	}
}

int Robot0::depthFirstGetDirection(Grid grid)
{
	movingDirection = -1;
	while (movingDirection < 0)
	{
		std::vector<int> possibleDirections;
		std::vector<cordinates> possibleMoves;
		//
		for (int i = 0; i < accesibleTiles.size(); i++)
		{
			if (nodeMap[*currentTile]->getNeighbor(accesibleTiles[i]) != nullptr)
			{
				if (nodeMap[*currentTile]->getNeighbor(accesibleTiles[i])->visited == false)
				{
		
						possibleMoves.emplace_back(nodeMap[*currentTile]->getNeighbor(accesibleTiles[i])->position);
						possibleDirections.emplace_back(accesibleTiles[i]);
				}
			}
		}


		if (possibleMoves.size() > 0)
		{
			int move = rand() % possibleDirections.size();
			cordinates nextPath = possibleMoves[move];
			//
			movingDirection = possibleDirections[move];
			nodeMap[nextPath]->visited = true;
			grid.tileMap[nextPath]->color = sf::Color::Red;
			grid.tileMap[nextPath]->shape.setFillColor(grid.tileMap[nextPath]->color);
			if (*currentTile == exploredTiles.back())
			{
				exploredTiles.emplace_back(nextPath);
				currentTile++;
			}
			else
			{
				currentTile++;
				exploredTiles.insert(currentTile, nextPath);
				currentTile--;
			}
		}
		else
		{
			if (currentTile != exploredTiles.begin())
			{
				std::list<cordinates>::iterator lastTile = currentTile;
				currentTile--;
				//movingDirection = nodeMap[*currentTile]->getSide(nodeMap[*lastTile]);
				movingDirection = nodeMap[*lastTile]->getSide(nodeMap[*currentTile]);

			}
			else break;
		}

	}
	return movingDirection;
}

void Robot0::movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList)
{
	if (!moving)
	{
		updateAccesiblity(grid);
		movingDirection = depthFirstGetDirection(grid);
		setFuturePosition();
		move(deltaTime);
		moving = true;
	}
	else
	{
		if (move(deltaTime))
		{
			moving = false;
		}
	}
}

int Robot0::instantMovement(Grid& grid)
{
	unsigned int tilesVisited = 0;
	while (gridPos != grid.startAndEndCords.second)
	{
		updateAccesiblity(grid);
		movingDirection = depthFirstGetDirection(grid);
		setFuturePosition();
		instantMove();
		//std::cout << gridPos.first << ", " << gridPos.second << std::endl;
		tilesVisited++;
	}
	return tilesVisited;
}


void Robot0::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}