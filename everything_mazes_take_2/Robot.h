#pragma once

class BaseRobot : public Object
{
public:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f size;
	sf::Vector2f gridOffset;
	sf::Vector2f futurePosition;
	cordinates gridPos;
	float tileSize;
	float speed = 0.001f;
	std::vector<int> accesibleTiles;
	bool moving = false;
	int movingDirection;

	BaseRobot();
	BaseRobot(Grid grid);

	void updateAccesiblity(Grid grid);
	
	void setFuturePosition();
	bool moveNorth(microTime deltaTime);
	bool moveEast(microTime deltaTime);
	bool moveSouth(microTime deltaTime);
	bool moveWest(microTime deltaTime);
	bool move(microTime deltaTime);

	virtual void movement(Grid grid, microTime deltaTime);

	virtual void draw(sf::RenderWindow* window) override;
};

