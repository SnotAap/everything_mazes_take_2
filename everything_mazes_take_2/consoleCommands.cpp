#pragma once
#include "Header.h"

Console::Console()
{


}

void Console::resetGrid(Grid& grid)
{
	grid.clear();
	grid.setup();
}

template<typename T>
T Console::average(std::vector<T> vector)
{
	T sum = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		sum += vector[i];
	}
	return (T)(sum / vector.size());
}

template <typename T>
T Console::min_(std::vector<T> vector)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < vector.size() - 1; i++) {
			if (vector[i] > vector[i + 1]) {
				vector[i] += vector[i + 1];
				vector[i + 1] = vector[i] - vector[i + 1];
				vector[i] -= vector[i + 1];
				swapp = true;
			}
		}
	}
	return vector.front();
}

template <typename T>
T Console::max_(std::vector<T> vector)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < vector.size() - 1; i++) {
			if (vector[i] > vector[i + 1]) {
				vector[i] += vector[i + 1];
				vector[i + 1] = vector[i] - vector[i + 1];
				vector[i] -= vector[i + 1];
				swapp = true;
			}
		}
	}
	return vector.back();
}

template <typename T>
std::vector<double> Console::percentageOf(std::vector<T> numerator, std::vector<T> Denominator)
{
	std::vector<double> percentageList;

	if (numerator.size() != Denominator.size())
		return percentageList;

	for (int i = 0; i < numerator.size(); i++)
	{
		double percentage = -10.0;
		percentage = double(((double)numerator[i] / (double)Denominator[i]) * 100.0);
		percentageList.emplace_back(percentage);
	}
	return percentageList;
}

void Console::pollCommands()
{
	std::string response;

	std::cout << "would you like to automate the program?(yes/no)" << std::endl;
	std::cin >> response;
	if (response == "yes")
	{
		commandGiven = true;
	}
	else return;
	std::cout << "please type the x dimention of the requested grid, example: 20" << std::endl;
	std::cin >> gridSizeX;
	std::cout << "please type the y dimention of the requested grid, example: 20" << std::endl;
	std::cin >> gridSizeY;
	std::cout << "whould you like a recursiveBacktracking Maze? (yes/no)" << std::endl;
	std::cin >> response;	
	if (response == "yes")
	{
		recursiveMaze = true;
	}
	response.clear();
	std::cout << "whould you like a prim's Maze? (yes/no)" << std::endl;
	std::cin >> response;
	if (response == "yes")
	{
		primsMaze = true;
	}
	response.clear();
	std::cout << "would you like the maze(s) to be solved by robot? (yes/no)" << std::endl;
	std::cin >> response;
	if (response == "yes")
	{
		robotSolve = true;
	}
	response.clear();
	std::cout << "would you like the maze(s) to be solved by robot0? (yes/no)" << std::endl;
	std::cin >> response;
	if (response == "yes")
	{
		robot0Solve = true;
	}
	response.clear();
	std::cout << "would you like the maze(s) to be solved by robot1? (yes/no)" << std::endl;
	std::cin >> response;
	if (response == "yes")
	{
		robot1Solve = true;
	}
	response.clear();
	std::cout << "how many times should this program repeat it self?" << std::endl;
	std::cin >> ittorations;

}

void Console::excecuteInstructions()
{
	if (commandGiven)
	{
		unsigned long pastTime;
		unsigned long currentTime;
		unsigned int deltaTime;
		std::vector<std::shared_ptr<Object>> renderList;
		sf::Font myfont;
		myfont.loadFromFile("..\\content\\arial.ttf");
		Grid grid(gridSizeX, gridSizeY);
		resetGrid(grid);
		
		for (unsigned int i = 0; i < ittorations; i++)
		{
			if (recursiveMaze)
			{
				resetGrid(grid);
				pastTime = timeGetTime();
				grid.recursiveBacktrackingMaze();
				currentTime = timeGetTime();
				deltaTime = (unsigned int)(currentTime - pastTime);
				deltaTimeRecursive.emplace_back(deltaTime);
				grid.devRemoveWalls();

				if (robotSolve)
				{
					Robot myRobot(grid);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobotRecursive.emplace_back(visitedTiles);
					deltaTimeRobotRecursive.emplace_back(deltaTime);
				}
				if (robot0Solve)
				{
					Robot0 myRobot0(grid);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot0.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobot0Recursive.emplace_back(visitedTiles);
					deltaTimeRobot0Recursive.emplace_back(deltaTime);
				}
				if (robot1Solve)
				{
					Robot1 myRobot1(grid, myfont, renderList);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot1.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobot1Recursive.emplace_back(visitedTiles);
					deltaTimeRobot1Recursive.emplace_back(deltaTime);
				}
				

				lengthOfPathRecursive.emplace_back(pathSolvingAStar(grid, grid.renderList).size() + 1);

			}
			if (primsMaze)
			{

				resetGrid(grid);
				pastTime = timeGetTime();
				grid.primsMaze();
				currentTime = timeGetTime();
				deltaTime = (unsigned int)(currentTime - pastTime);
				deltaTimePrims.emplace_back(deltaTime);
				grid.devRemoveWalls();

				if (robotSolve)
				{
					Robot myRobot(grid);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobotPrims.emplace_back(visitedTiles);
					deltaTimeRobotPrims.emplace_back(deltaTime);
				}
				if (robot0Solve)
				{
					Robot0 myRobot0(grid);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot0.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobot0Prims.emplace_back(visitedTiles);
					deltaTimeRobot0Prims.emplace_back(deltaTime);
				}
				if (robot1Solve)
				{
					Robot1 myRobot1(grid, myfont, renderList);
					
					pastTime = timeGetTime();
					int visitedTiles = myRobot1.instantMovement(grid);
					currentTime = timeGetTime();
					deltaTime = (unsigned int)(currentTime - pastTime);
					visitedTilesRobot1Prims.emplace_back(visitedTiles);
					deltaTimeRobot1Prims.emplace_back(deltaTime);
				}


				lengthOfPathPrims.emplace_back(pathSolvingAStar(grid, grid.renderList).size() + 1);

			}
		}
	}
	
}


void Console::returnStats()
{

	if (recursiveMaze)
	{
		std::cout << "Recursive: average length of path: " << average(lengthOfPathRecursive) << ". Minimal length of path: " << min_(lengthOfPathRecursive) << " Maximum length of path: " << max_(lengthOfPathRecursive) << std::endl;
		std::cout << "Recursive: average time of maze generation in millis: " << average(deltaTimeRecursive) << ". Minimal length of maze generation in millis: " << min_(deltaTimeRecursive) << " Maximum length of maze generation in millis: " << max_(deltaTimeRecursive) << std::endl;
			
		if(robotSolve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathRecursive, visitedTilesRobotRecursive);
			std::cout << "Recursive, Robot: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Recursive, Robot: average time of maze solving in millis: " << average(deltaTimeRobotRecursive) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobotRecursive) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobotRecursive) << std::endl;
		}				
		if(robot0Solve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathRecursive, visitedTilesRobot0Recursive);
			std::cout << "Recursive, Robot0: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Recursive, Robot0: average time of maze solving in millis: " << average(deltaTimeRobot0Recursive) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobot0Recursive) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobot0Recursive) << std::endl;
		}
		if(robot1Solve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathRecursive, visitedTilesRobot1Recursive);
			std::cout << "Recursive, Robot1: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Recursive, Robot1: average time of maze solving in millis: " << average(deltaTimeRobot1Recursive) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobot1Recursive) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobot1Recursive) << std::endl;
		}

			

		
	}

	if (primsMaze)
	{
		std::cout << "Prims: average length of path: " << average(lengthOfPathPrims) << ". Minimal length of path: " << min_(lengthOfPathPrims) << " Maximum length of path: " << max_(lengthOfPathPrims) << std::endl;
		std::cout << "Prims: average time of maze generation in millis: " << average(deltaTimePrims) << ". Minimal length of maze generation in millis: " << min_(deltaTimePrims) << " Maximum length of maze generation in millis: " << max_(deltaTimePrims) << std::endl;
	
		if(robotSolve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathPrims, visitedTilesRobotPrims);
			std::cout << "Prims, Robot: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Prims, Robot: average time of maze solving in millis: " << average(deltaTimeRobotPrims) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobotPrims) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobotPrims) << std::endl;
		}
		if(robot0Solve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathPrims, visitedTilesRobot0Prims);
			std::cout << "Prims, Robot0: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Prims, Robot0: average time of maze solving in millis: " << average(deltaTimeRobot0Prims) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobot0Prims) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobot0Prims) << std::endl;
		}
		if(robot1Solve)
		{
			std::vector<double> percentage = percentageOf(lengthOfPathPrims, visitedTilesRobot1Prims);
			std::cout << "Prims, Robot1: average percentage of correctness: " << average(percentage) << ". Minimal percentage of correctness: " << min_(percentage) << " Maximum percentage of correctness: " << max_(percentage) << std::endl;
			std::cout << "Prims, Robot1: average time of maze solving in millis: " << average(deltaTimeRobot1Prims) << ". Minimal length of maze solving in millis: " << min_(deltaTimeRobot1Prims) << " Maximum length of maze solving in millis: " << max_(deltaTimeRobot1Prims) << std::endl;
		}

	}
}