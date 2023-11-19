#pragma once
class UI
{
public:
	std::vector<std::shared_ptr<Button>> buttons;
	std::shared_ptr<std::vector<std::shared_ptr<Object>>> renderList;

	UI(std::vector<std::shared_ptr<Object>>& renderList_);
	~UI();
	bool LeftMousePressed = false;
	bool LeftMousebuffer = false;

	int checkButtonsHoverd(sf::Mouse mouse);
	int checkButtonsPressed(sf::Mouse mouse, sf::Event event);
	void buttonAction(int action);
	void draw(sf::RenderWindow* window);

	//_vvv_all_actions_go_here_vvv_\\



};