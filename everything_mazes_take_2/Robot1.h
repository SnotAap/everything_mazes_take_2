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

	std::map<cordinates, std::shared_ptr<Node>> setupNodes(Grid& grid);											//a function to setup all nodes required for other functions to function
	void setupWalls(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);								//a function which sets up the wall to be used by other funcions

	Robot1(Grid& grid, sf::Font font_, std::vector<std::shared_ptr<Object>>& renderList);						//a constructor which among other things runs the setupNodes and the setupWalls functions

	void updateWallMap(Grid& grid, std::vector<std::shared_ptr<Object>>& renderList);							//a function which updates the walls depending on what te robot is able te see.
	void pathSolvingFloodFill(Grid& grid);																		//a function which floods the maze with the seen walls which enables a function to determine the optimal future position
	int getDirection(Grid& grid);																				//a function which determines the optimal direction to move
	virtual void movement(Grid& grid, microTime deltaTime, std::vector<std::shared_ptr<Object>>& renderList);	//a function which makes up the movement behaviour of the robot

	virtual void draw(sf::RenderWindow* window) override;														//a draw function so that the robot can be drawn to the screen
	
};