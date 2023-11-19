#pragma once

class Object
{
public:
	sf::Vector2f position;	

	virtual void draw(sf::RenderWindow* window);			//a draw function so objects can be drawn to the screen
};