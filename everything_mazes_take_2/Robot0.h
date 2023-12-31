#pragma once
class Robot0 : public Robot
{

public:
	std::list<cordinates> exploredTiles;
	std::list<cordinates>::iterator currentTile;

	std::map<cordinates, std::shared_ptr<Node>> nodeMap;

	void setupNodeMap(Grid grid);

	Robot0(Grid grid);
	~Robot0();

	int depthFirstGetDirection(Grid grid);

	virtual void movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList) override;
	virtual unsigned int instantMovement(Grid& grid) override;
	virtual void draw(sf::RenderWindow* window) override;


};