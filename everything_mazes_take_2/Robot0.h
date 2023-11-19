#pragma on
class Robot0 : public Robot
{

public:
	std::list<cordinates> exploredTiles;
	std::list<cordinates>::iterator currentTile;

	std::map<cordinates, std::shared_ptr<Node>> nodeMap;


	void setupNodeMap(Grid grid);										//a function to setup the nodes required for the other functions to function

	Robot0(Grid grid);													//a constructor which among other things runs the setupNodeMap function
										
	int recursiveBacktrackingGetDirection(Grid grid);					//a function which determines the future direction of travel
	virtual void movement(Grid& grid, microTime deltaTime) override;	//a function which makes up the moving behaviour of the robot

	virtual void draw(sf::RenderWindow* window) override;				//a draw function which enables the robot to be drawn to the screen


};