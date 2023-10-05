#include "Header.h"

UI::UI(std::vector<std::shared_ptr<Object>>& renderList)
{
	//make all the buttons here!
	std::shared_ptr<Button> myButton0 = std::make_shared<Button>(1600.0f, 0.0f, 1.0f, "hello world");
	buttons.emplace_back(myButton0);
	std::shared_ptr<Button> myButton1 = std::make_shared<Button>(1600.0f, 50.0f, 1.0f, "hello world \n this is a second line.");
	buttons.emplace_back(myButton1);
	std::shared_ptr<Button> myButton2 = std::make_shared<Button>(1600.0f, 150.0f, 0.5f, "hello world \n this is a second line. \n and this is an other scale.");
	buttons.emplace_back(myButton2);
	//don't forget to write the button action in the associated function (void buttonAction(int action)).
	for (int i = 0; i < buttons.size(); i++)
	{
		renderList.emplace_back(buttons[i]);
	}
}

//work in progress
int UI::checkButtonsHoverd(sf::Mouse mouse)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		//box collision.
		if (mouse.getPosition().x >= buttons[i]->position.x && mouse.getPosition().x <= (buttons[i]->position.x + buttons[i]->size.x))
		{
			if (mouse.getPosition().y >= buttons[i]->position.y && mouse.getPosition().y <= (buttons[i]->position.y + buttons[i]->size.y))
			{
				
				return i;
			}
			else
			{
				LeftMousebuffer = false;
				LeftMousePressed = false;
			}

		}
		else
		{
			LeftMousebuffer = false;
			LeftMousePressed = false;
		}

	}
	return -1;
}
// work in progress
int UI::checkButtonsPressed(sf::Mouse mouse)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		//box collision.
		
		if (mouse.getPosition().x >= buttons[i]->position.x && mouse.getPosition().x <= (buttons[i]->position.x + buttons[i]->size.x))
		{
			if(mouse.getPosition().y >= buttons[i]->position.y && mouse.getPosition().y <= (buttons[i]->position.y + buttons[i]->size.y))
			{
				if (mouse.isButtonPressed(mouse.Left) && !LeftMousebuffer)
				{
					LeftMousePressed = true;
					LeftMousebuffer = true;
					return i;
				}
				else
				{
					LeftMousebuffer = false;
					LeftMousePressed = false;
				}

			}
			else
			{
				LeftMousebuffer = false;
				LeftMousePressed = false;
			}
		}
		else
		{
			LeftMousebuffer = false;
			LeftMousePressed = false;
		}

	}
	return -1;
}

void UI::buttonAction(int action)
{
	if (action > -1 && !LeftMousebuffer)
	{
		std::cout << "button: " << action << " is pressed." << std::endl;
	}
}

void UI::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		window->draw(buttons[i]->shape);
	}
}