#pragma once

class Grid
{
public:
	int sizeX;
	int sizeY;
	int tileSize;
	std::shared_ptr<Tile> plane;
	std::map<cordinates, std::shared_ptr<Tile>> tileMap;
	std::map<cordinates, walls> wallMap;
	std::vector <std::pair<cordinates, int>> removedWallsOrderd;
	std::pair<cordinates, cordinates> startAndEndCords;
	std::vector<std::shared_ptr<Text>> depthList;

    microTime timerTime;
	microTime timer;
	int wallRemoveItorater = 0;

	Grid(int sizeX_, int sizeY_);										//constructor

	void setup(std::vector<std::shared_ptr<Object>>& renderList);		//sets up the grid with walls and neighbors
	void recursiveBacktrackingMaze();									//generates a maze using recurivebacktracking
	void primsMaze();													//generates a maze using prims algorithm

	bool removeWalls(microTime deltaTime);								//removes to be removed walls with a set delay inbetween steps
	bool devRemoveWalls();												//instantly removes all to be removed walls
};