#include "Header.h"

bool gridRenderd = false;

UI::UI()
{

}

UI::~UI()
{

}

UI::UI(Grid grid, sf::Font font, std::vector<std::shared_ptr<Object>>& renderList)
{
	//make all the buttons here!
	std::shared_ptr<Button> gridGenerateButton = std::make_shared<Button>(1700.0f, 100.0f, 1.0f, "generate grid");
	buttons.emplace_back(gridGenerateButton);
	//
	std::shared_ptr<Button> gridSizeXButton = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "sizeX: " + std::to_string(grid.sizeX));
	buttons.emplace_back(gridSizeXButton);
	std::shared_ptr<Button> gridSizeXPlus5Button = std::make_shared<Button>(1800.0f, 150.0f, 1.0f, "+5");
	buttons.emplace_back(gridSizeXPlus5Button);
	std::shared_ptr<Button> gridSizeXPlus1Button = std::make_shared<Button>(1850.0f, 150.0f, 1.0f, "+1");
	buttons.emplace_back(gridSizeXPlus1Button);
	std::shared_ptr<Button> gridSizeXMinus5Button = std::make_shared<Button>(1600.0f, 150.0f, 1.0f, "-5");
	buttons.emplace_back(gridSizeXMinus5Button);
	std::shared_ptr<Button> gridSizeXMinus1Button = std::make_shared<Button>(1550.0f, 150.0f, 1.0f, "-1");
	buttons.emplace_back(gridSizeXMinus1Button);
	//
	std::shared_ptr<Button> gridSizeYButton = std::make_shared<Button>(1700.0f, 200.0f, 1.0f, "sizeY: " + std::to_string(grid.sizeY));
	buttons.emplace_back(gridSizeYButton);
	std::shared_ptr<Button> gridSizeYPlus5Button = std::make_shared<Button>(1800.0f, 200.0f, 1.0f, "+5");
	buttons.emplace_back(gridSizeYPlus5Button);
	std::shared_ptr<Button> gridSizeYPlus1Button = std::make_shared<Button>(1850.0f, 200.0f, 1.0f, "+1");
	buttons.emplace_back(gridSizeYPlus1Button);
	std::shared_ptr<Button> gridSizeYMinus5Button = std::make_shared<Button>(1600.0f, 200.0f, 1.0f, "-5");
	buttons.emplace_back(gridSizeYMinus5Button);
	std::shared_ptr<Button> gridSizeYMinus1Button = std::make_shared<Button>(1550.0f, 200.0f, 1.0f, "-1");
	buttons.emplace_back(gridSizeYMinus1Button);
	//
	std::shared_ptr<Button> recursiveMazeGenerateButton = std::make_shared<Button>(1700.0f, 100.0f, 1.0f, "generate recursiveMaze");
	buttons.emplace_back(recursiveMazeGenerateButton);
	std::shared_ptr<Button> PrimsMazeGenerateButton = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "generate primsMaze");
	buttons.emplace_back(PrimsMazeGenerateButton);
	std::shared_ptr<Button> instanteGenerateButton = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "instant Generate");
	buttons.emplace_back(instanteGenerateButton);
	std::shared_ptr<Button> abortMazeGenerateButton = std::make_shared<Button>(1700.0f, 200.0f, 1.0f, "stop Generating");
	buttons.emplace_back(abortMazeGenerateButton);
	std::shared_ptr<Button> solveRobot = std::make_shared<Button>(1700.0f, 100.0f, 1.0f, "Robot solve");
	buttons.emplace_back(solveRobot);
	std::shared_ptr<Button> solveRobot0 = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "Robot0 solve");
	buttons.emplace_back(solveRobot0);
	std::shared_ptr<Button> solveRobot1 = std::make_shared<Button>(1700.0f, 200.0f, 1.0f, "Robot1 solve");
	buttons.emplace_back(solveRobot1);
	std::shared_ptr<Button> solveButton = std::make_shared<Button>(1700.0f, 250.0f, 1.0f, "solve");
	buttons.emplace_back(solveButton);
	std::shared_ptr<Button> abortSolvingButton = std::make_shared<Button>(1700.0f, 100.0f, 1.0f, "stop solving");
	buttons.emplace_back(abortSolvingButton);
	std::shared_ptr<Button> solveAStar = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "solve A*");
	buttons.emplace_back(solveAStar);
	std::shared_ptr<Button> backButton = std::make_shared<Button>(1750.0f, 50.0f, 1.0f, "back");
	buttons.emplace_back(backButton);
	std::shared_ptr<Button> resumeButton = std::make_shared<Button>(1750.0f, 300.0f, 1.0f, "resume loop");
	buttons.emplace_back(resumeButton);
	
	std::shared_ptr<Button> gridSelectionButton = std::make_shared<Button>(885.0f, 18.0f, 1.0f, "grid selection", true);								//23
	buttons.emplace_back(gridSelectionButton);
	std::shared_ptr<Button> mazeSelectionButton = std::make_shared<Button>(885.0f, 18.0f, 1.0f, "maze generation selection", true);								//24
	buttons.emplace_back(mazeSelectionButton);
	std::shared_ptr<Button> mazeGenerationButton = std::make_shared<Button>(885.0f, 18.0f, 1.0f, mazeAlgorithmSentence, true);	//25
	buttons.emplace_back(mazeGenerationButton);
	std::shared_ptr<Button> robotButton = std::make_shared<Button>(885.0f, 18.0f, 1.0f, "choice of virtual robot", true);							//26
	buttons.emplace_back(robotButton);	
	std::shared_ptr<Button> robotSolvingButton = std::make_shared<Button>(885.0f, 18.0f, 1.0f, "solving with virtual robot", true);							//27
	buttons.emplace_back(robotSolvingButton);
	
	
	
	//don't forget to write the button action in the associated function (void buttonAction(int action)).
}
//void UI::ButtonManager(int state)
//{
//	switch (state)
//	{
//	case startState:
//		activeButtons.clear();
//		activeButtons.emplace_back(buttons[0]);
//		break;
//	case generateChoiseState:
//		activeButtons.clear();
//		activeButtons.emplace_back(buttons[1]);
//		activeButtons.emplace_back(buttons[2]);
//		break;
//	case generateState:
//		activeButtons.clear();
//		activeButtons.emplace_back(buttons[3]);
//		break;
//	case solveState:
//		activeButtons.clear();
//		activeButtons.emplace_back(buttons[4]);
//		break;
//	}
//}


bool UI::mousePressed(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left) 
		{
			LeftMousePressed = true;
		}
		else
		{
			LeftMousePressed = false;
			lastLeftMousePressed = false;
		}
	}
	else
	{
		LeftMousePressed = false;
		lastLeftMousePressed = false;
	}
	return LeftMousePressed;
}

int UI::checkButtonsHoverd(sf::Mouse mouse)
{
	for (int i = 0; i < activeButtons.size(); i++)
	{
		//box collision.
		if (mouse.getPosition().x >= activeButtons[i]->position.x - (activeButtons[i]->size.x / 2) && mouse.getPosition().x <= (activeButtons[i]->position.x + (activeButtons[i]->size.x / 2)))
		{
			if (mouse.getPosition().y >= activeButtons[i]->position.y && mouse.getPosition().y <= (activeButtons[i]->position.y + activeButtons[i]->size.y))
			{
				activeButtons[i]->text.setFillColor(sf::Color(128, 128, 128, 255));
				return i;
			}
			else
			{
				activeButtons[i]->text.setFillColor(sf::Color::Black);
			}
		}
		else
		{
			activeButtons[i]->text.setFillColor(sf::Color::Black);
		}
	}
	
	return -1;
}
// work in progress



int UI::checkButtonsPressed(sf::Mouse mouse)
{	
	for (int i = 0; i < activeButtons.size(); i++)
	{
		//box collision.
		if (mouse.getPosition().x >= activeButtons[i]->position.x - (activeButtons[i]->size.x / 2) && mouse.getPosition().x <= (activeButtons[i]->position.x + (activeButtons[i]->size.x / 2)))
		{
			if (mouse.getPosition().y >= activeButtons[i]->position.y && mouse.getPosition().y <= (activeButtons[i]->position.y + activeButtons[i]->size.y))
			{
				if (LeftMousePressed && !lastLeftMousePressed)
				{
					for (int j = 0; j < buttons.size(); j++)
					{
						if (activeButtons[i] == buttons[j])
						{
							loop = false;
							return j;

						}
					}
				}						
			}			
		}		
	}
	return -1;
}

void UI::buttonAction(sf::Font font, int& state, int action, Grid& grid, std::vector<std::pair<std::shared_ptr<Robot>, bool>>& robotList, bool& solve)
{	
	switch (action)
	{
	case 0:
		//grid.resetGrid();
		grid.clear();
		grid.setup();
		grid.removedWallsOrderd.clear();
		grid.wallRemoveItorater = 0;
		buttons[0]->IsPressed = false;
		state++;
		break;
	case 1: 

		break;
	case 2:
		
		grid.sizeX += 5;
		buttons[1]->sentence = "sizeX: " + std::to_string(grid.sizeX);
		buttons[1]->text.setString(buttons[1]->sentence);
		break;
	case 3:
		grid.sizeX++;
		buttons[1]->sentence = "sizeX: " + std::to_string(grid.sizeX);
		buttons[1]->text.setString(buttons[1]->sentence);
		break;
	case 4:
		if (grid.sizeX > 5)
		{
			grid.sizeX -= 5;
			buttons[1]->sentence = "sizeX: " + std::to_string(grid.sizeX);
			buttons[1]->text.setString(buttons[1]->sentence);
		}
		break;
	case 5:
		if (grid.sizeX > 1)
		{
			grid.sizeX--;
			buttons[1]->sentence = "sizeX: " + std::to_string(grid.sizeX);
			buttons[1]->text.setString(buttons[1]->sentence);
		}
		break;
	case 6:

		break;
	case 7:
		grid.sizeY += 5;
		buttons[6]->sentence = "sizeY: " + std::to_string(grid.sizeY);
		buttons[6]->text.setString(buttons[6]->sentence);
		break;
	case 8:
		grid.sizeY++;
		buttons[6]->sentence = "sizeY: " + std::to_string(grid.sizeY);
		buttons[6]->text.setString(buttons[6]->sentence);
		break;
	case 9:
		if (grid.sizeY > 5)
		{
			grid.sizeY -= 5;
			buttons[6]->sentence = "sizeY: " + std::to_string(grid.sizeY);
			buttons[6]->text.setString(buttons[6]->sentence);
		}

		break;
	case 10:
		if (grid.sizeY > 1)
		{
			grid.sizeY--;
			buttons[6]->sentence = "sizeY: " + std::to_string(grid.sizeY);
			buttons[6]->text.setString(buttons[6]->sentence);
		}

		break;
	case 11:
		//grid.resetGrid();
		grid.recursiveBacktrackingMaze();
		mazeAlgorithmSentence = "maze generation using recursive backtracking algorithm";
		buttons[25]->sentence = mazeAlgorithmSentence;
		buttons[25]->text.setString(buttons[25]->sentence);
		buttons[action]->IsPressed = false;
		state++;
		break;
	case 12:
		//grid.resetGrid();
		grid.primsMaze();
		mazeAlgorithmSentence = "maze generation using Prims algorithm";
		buttons[25]->sentence = mazeAlgorithmSentence;
		buttons[25]->text.setString(buttons[25]->sentence);
		buttons[action]->IsPressed = false;
		state++;
		break;
	case 13:
		grid.devRemoveWalls();
		grid.removedWallsOrderd.clear();
		grid.wallRemoveItorater = 0;
		state++;


		break;
	case 14:
		grid.removedWallsOrderd.clear();
		grid.wallRemoveItorater = 0;
		state--;

		break;
	case 15:
	{
		std::shared_ptr<Robot> robot = std::make_shared<Robot>(grid);
		std::pair<std::shared_ptr<Robot>, bool> robotPair = std::pair<std::shared_ptr<Robot>, bool>(std::make_pair(robot, false));
		robotList.emplace_back(robotPair);
		robotList[robotList.size() - 1].second = true;
		
		break;
	}

	case 16:
	{
		std::shared_ptr<Robot> robot0 = std::make_shared<Robot0>(grid);
		std::pair<std::shared_ptr<Robot>, bool> robot0Pair = std::pair<std::shared_ptr<Robot>, bool>(std::make_pair(robot0, false));
		robotList.emplace_back(robot0Pair);
		robotList[robotList.size() - 1].second = true;
		break;
	}

	case 17:
	{
		
		std::shared_ptr<Robot> robot1 = std::make_shared<Robot1>(grid, font, grid.renderList);
		std::pair<std::shared_ptr<Robot>, bool> robot1Pair = std::pair<std::shared_ptr<Robot>, bool>(std::make_pair(robot1, false));
		robotList.emplace_back(robot1Pair);
		robotList[robotList.size() - 1].second = true;
		break;
	}
	case 18:
		state++;
		break;
	case 19:
	{
		for (int i = 0; i < robotList.size(); i++)
		{
			robotList[i].first = NULL;
		}
		robotList.clear();
		grid.depthList.clear();
		state = 0;
		break;
	}
	case 20:
		pathSolvingAStar(grid, grid.renderList);

		break;
	case 21:
		state--;
		break;
	case 22:
		loop = true;
		resumeloop = true;
		break;

	}



	
}



void UI::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		window->draw(buttons[i]->shape);
	}
}