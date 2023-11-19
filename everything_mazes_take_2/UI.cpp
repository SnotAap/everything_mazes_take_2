#include "Header.h"

bool gridRenderd = false;

UI::UI(std::vector<std::shared_ptr<Object>>& renderList)
{
	//make all the buttons here!
	std::shared_ptr<Button> myButton0 = std::make_shared<Button>(1700.0f, 50.0f, 1.0f, "Generate Grid");
	buttons.emplace_back(myButton0);
	std::shared_ptr<Button> myButton1 = std::make_shared<Button>(1700.0f, 100.0f, 1.0f, "Generate RecursiveMaze");
	buttons.emplace_back(myButton1);
	std::shared_ptr<Button> myButton2 = std::make_shared<Button>(1700.0f, 150.0f, 1.0f, "Generate PrimsMaze");
	buttons.emplace_back(myButton2); 
	std::shared_ptr<Button> myButton3 = std::make_shared<Button>(1700.0f, 200.0f, 1.0f, "Solve");
	buttons.emplace_back(myButton3);
	//don't forget to write the button action in the associated function (void buttonAction(int action)).
	for (int i = 0; i < buttons.size(); i++)
	{
		renderList.emplace_back(buttons[i]);
	}
}

int UI::checkButtonsHoverd(sf::Mouse mouse)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		//box collision.
		if (mouse.getPosition().x >= buttons[i]->position.x - (buttons[i]->size.x/2) && mouse.getPosition().x <= (buttons[i]->position.x + (buttons[i]->size.x/2)))
		{
			if (mouse.getPosition().y >= buttons[i]->position.y && mouse.getPosition().y <= (buttons[i]->position.y + buttons[i]->size.y))
			{				
				buttons[i]->text.setFillColor(sf::Color(128, 128, 128, 255));
				return i;
			}
			else
			{
				buttons[i]->text.setFillColor(sf::Color::Black);
			}			
		}
		else
		{			
			buttons[i]->text.setFillColor(sf::Color::Black);			
		}
	}
	
	return -1;
}
// work in progress
int UI::checkButtonsPressed(sf::Mouse mouse, sf::Event event)
{	
	for (int i = 0; i < buttons.size(); i++)
	{
		//box collision.
		if (mouse.getPosition().x >= buttons[i]->position.x - (buttons[i]->size.x / 2) && mouse.getPosition().x <= (buttons[i]->position.x + (buttons[i]->size.x / 2)))
		{
			if (mouse.getPosition().y >= buttons[i]->position.y && mouse.getPosition().y <= (buttons[i]->position.y + buttons[i]->size.y))
			{			

				if (event.type == sf::Event::MouseButtonPressed)
				{	
					if (event.mouseButton.button == sf::Mouse::Left) {
						buttonAction(i);
						return i;
					}														
				}		
			}			
		}		
	}
	return -1;
}

void UI::buttonAction(int action)
{		
	if (action == 0 && buttons[3]->IsPressed != true)
	{
		gridRenderd = true;
		buttons[action]->IsPressed = true;		
	}	
	else if (buttons[3]->IsPressed != true && gridRenderd == true)
	{		
		buttons[action]->IsPressed = true;
	}
	
}

void UI::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		window->draw(buttons[i]->shape);
	}
}