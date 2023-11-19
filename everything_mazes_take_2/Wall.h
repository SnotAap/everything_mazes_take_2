#pragma once

class Wall : public Object
{
public:
	sf::Vector2f size;
	float rotation;
	sf::Color color;
	bool active = false;
	sf::RectangleShape shape;

	Wall(float xPos_, float yPos_, float xSize_, float ySize_, float rotation_);								//a constructor
	Wall(float xPos_, float yPos_, float xSize_, float ySize_, float rotation_, sf::Color color_);				//a constructor which also influences the color of the Wall

	virtual void draw(sf::RenderWindow* window) override;														//a draw function which enables a Wall to be drawn to the screen
};