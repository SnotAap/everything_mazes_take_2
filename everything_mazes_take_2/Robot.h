#pragma once

class Robot : public Object
{
public:
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f size;
	sf::Vector2f gridOffset;
	sf::Vector2f futurePosition;
	std::map<cordinates, bool> traversedTiles;
	cordinates gridPos;
	float tileSize;
	float speed = 0.0005f;
	//float speed = 10.0f; //dev time
	std::vector<int> accesibleTiles;
	bool moving = false;
	int movingDirection;

	

	Robot();
	Robot(Grid grid);
	~Robot();

	void updateAccesiblity(Grid grid);
	
	void setFuturePosition();
	bool moveNorth(microTime deltaTime);
	bool moveEast(microTime deltaTime);
	bool moveSouth(microTime deltaTime);
	bool moveWest(microTime deltaTime);
	bool move(microTime deltaTime);

	void instantMoveNorth();
	void instantMoveEast();
	void instantMoveSouth();
	void instantMoveWest();
	void instantMove();

	virtual void movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList);
	virtual unsigned int instantMovement(Grid& grid);

	virtual void draw(sf::RenderWindow* window) override;
};

