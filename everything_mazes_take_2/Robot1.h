#pragma once
class Robot1 : public Robot
{
public:
	std::map<cordinates, int> floodedMaze;
	std::list<std::shared_ptr<Node>> queue;
	std::vector<std::shared_ptr<Node>> toBeRemoved;
	std::vector<std::shared_ptr<Node>> toBeAdded;
	std::map<cordinates, walls> robotWallMap;
	std::map<cordinates, bool> seenTiles;
	std::map<cordinates, std::shared_ptr<Node>> nodes;
	sf::Font font;
	int depth = -1;

	Robot1(Grid& grid, sf::Font font_, std::vector<std::shared_ptr<Object>>& renderList);
	~Robot1();

	std::map<cordinates, std::shared_ptr<Node>> setupNodes(Grid& grid);
	void setupWalls(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);
	void updateWallMap(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);
	bool pathSolvingFloodFill(Grid& grid);
	int getDirection(Grid& grid);
	virtual void movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList);
	virtual void draw(sf::RenderWindow* window) override;
	
};