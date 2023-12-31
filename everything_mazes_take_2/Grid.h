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
	std::vector<std::shared_ptr<Object>> renderList;

    microTime timerTime;
	microTime timer;
	int wallRemoveItorater = 0;

	Grid(int sizeX_, int sizeY_);
	~Grid();

	void setup();
	void clear();
	void resetGrid();
	void recursiveBacktrackingMaze();
	void primsMaze();	

	bool removeWalls(microTime deltaTime);
	bool devRemoveWalls();
	void display(sf::RenderWindow* window);
};