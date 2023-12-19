#pragma once

class Console
{
private:

	//data variables


	std::string command;
	bool commandGiven = false;
	unsigned int gridSizeX = 0;
	unsigned int gridSizeY = 0;
	bool recursiveMaze = false;
	bool primsMaze = false;	
	bool robotSolve = false;
	bool robot0Solve = false;
	bool robot1Solve = false;
	unsigned int ittorations = 0;


	std::vector<unsigned int> lengthOfPathRecursive;
	std::vector<unsigned int> visitedTilesRobotRecursive;
	std::vector<unsigned int> visitedTilesRobot0Recursive;
	std::vector<unsigned int> visitedTilesRobot1Recursive;

	std::vector<unsigned int> lengthOfPathPrims;
	std::vector<unsigned int> visitedTilesRobotPrims;
	std::vector<unsigned int> visitedTilesRobot0Prims;
	std::vector<unsigned int> visitedTilesRobot1Prims;

	std::vector<unsigned int> deltaTimeRecursive;
	std::vector<unsigned int> deltaTimeRobotRecursive;
	std::vector<unsigned int> deltaTimeRobot0Recursive;
	std::vector<unsigned int> deltaTimeRobot1Recursive;

	std::vector<unsigned int> deltaTimePrims;
	std::vector<unsigned int> deltaTimeRobotPrims;
	std::vector<unsigned int> deltaTimeRobot0Prims;
	std::vector<unsigned int> deltaTimeRobot1Prims;
		
	std::vector<std::pair<short, Robot>> robots;

	//loop variables
	int stateTimer = 10000;
	int stateSwitch = stateTimer;

	

	unsigned int minXSize = 0; 
	unsigned int maxXSize = 0;	
	unsigned int minYSize = 0;
	unsigned int maxYSize = 0;

	bool recursiveMazeGen = false;
	bool primsMazeGen = false;

	std::vector<int> randomMazeGen;

	bool robotLoopSolve = false;
	bool robot0LoopSolve = false;
	bool robot1LoopSolve = false;

	std::vector<int> randomRobot;





	void resetGrid(Grid& grid);
	template <typename T>
	T average(std::vector<T> vector);
	template <typename T>
	T min_(std::vector<T> vector);
	template <typename T>
	T max_(std::vector<T> vector);
	template <typename T>
	std::vector<double> percentageOf(std::vector<T> numerator, std::vector<T> Denominator);


public:

	bool loopCommandGiven = false;

	Console();
	void pollDataCommands();
	bool pollLoopCommands(UI& UI);
	void excecuteDataInstructions();
	void excecuteLoopInstructions(microTime deltaTime, sf::Font font, int& state, Grid& grid, std::vector<std::pair<std::shared_ptr<Robot>, bool>>& robotList, bool& solve, UI& UI);
	void returnStats();

}; 