#pragma once

class Line : public Object
{
public:
	sf::Vector2f size;
	float rotation;
	sf::Color color;
	sf::RectangleShape shape;

	Line(float xPos_, float yPos_, float xSize_, float ySize_, float rotation_);		//constructor
	Line(sf::Vector2f line1, sf::Vector2f line2, float thickness);						//another constructor

	virtual void draw(sf::RenderWindow* window) override;								//a draw function so the line can be drawn on screen
};