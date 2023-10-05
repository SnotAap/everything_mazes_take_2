#pragma once
class UI
{
public:
	std::vector<std::shared_ptr<Button>> buttons;
	std::shared_ptr<std::vector<std::shared_ptr<Object>>> renderList;
	UI(std::vector<std::shared_ptr<Object>>& renderList_);
	bool LeftMousePressed = false;
	bool LeftMousebuffer = false;

	int checkButtonsHoverd(sf::Mouse mouse);
	int checkButtonsPressed(sf::Mouse mouse);
	void buttonAction(int action);
	void draw(sf::RenderWindow* window);

	//_vvv_all_actions_go_here_vvv_\\



};