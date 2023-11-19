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
	//float speed = 0.001f;
	float speed = 10.0f; //dev time
	std::vector<int> accesibleTiles;
	bool moving = false;
	int movingDirection;

	Robot();														//a default constructor
	Robot(Grid grid);												//a functional constructor	

	void updateAccesiblity(Grid grid);								//a function which checks wich tiles are accessible for the robot
	
	void setFuturePosition();										//set the position to which te robot will move
	bool moveNorth(microTime deltaTime);							//a function which makes a step North every time it get executed
	bool moveEast(microTime deltaTime);								//a function which makes a step East every time it get executed
	bool moveSouth(microTime deltaTime);							//a function which makes a step South every time it get executed
	bool moveWest(microTime deltaTime);								//a function which makes a step West every time it get executed
	bool move(microTime deltaTime);									//runs the above 4 move functions depending on the direction required to move to the set position

	virtual void movement(Grid& grid, microTime deltaTime);			//combines all the above mentioned functions to depict the behaviour of the robot

	virtual void draw(sf::RenderWindow* window) override;			//a draw function so that the robot can be drawn to the screen
};

