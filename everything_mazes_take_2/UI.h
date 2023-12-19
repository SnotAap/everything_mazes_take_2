#pragma once
class UI
{
public:
	#define startState 0
	#define generateChoiseState 1
	#define generateState 2
	#define solveState 3
	#define solvingState 4
	#define solvedState 5

	bool loop = false;
	bool resumeloop = true;

	std::vector<std::shared_ptr<Button>> buttons;
	std::vector<std::shared_ptr<Button>> activeButtons;
	std::vector<std::shared_ptr<Text>> text;
	std::vector<std::shared_ptr<Text>> activeText;
	std::string mazeAlgorithmSentence = "maze generation";

	UI();
	UI(Grid grid, sf::Font font, std::vector<std::shared_ptr<Object>>& renderList_);
	~UI();

	bool LeftMousePressed = false;
	bool lastLeftMousePressed = false;

	bool mousePressed(sf::Event event);
	int checkButtonsHoverd(sf::Mouse mouse);
	int checkButtonsPressed(sf::Mouse mouse);
	void buttonAction(sf::Font font, int& state, int action, Grid& grid, std::vector<std::pair<std::shared_ptr<Robot>, bool>>& robotList, bool& solve);
	void draw(sf::RenderWindow* window);

	//_vvv_all_actions_go_here_vvv_\\



};