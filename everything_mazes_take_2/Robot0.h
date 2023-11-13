#pragma once
class Robot0 : public BaseRobot
{

public:
	std::list<cordinates> exploredTiles;
	std::list<cordinates>::iterator currentTile;

	std::map<cordinates, std::shared_ptr<Node>> nodeMap;

	void setupNodeMap(Grid grid);

	Robot0(Grid grid);


	int floodFillGetDirection(Grid grid);

	virtual void movement(Grid grid, microTime deltaTime) override;

	virtual void draw(sf::RenderWindow* window) override;


};