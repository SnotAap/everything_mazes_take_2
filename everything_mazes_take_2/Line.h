#pragma once

class Line : public Object
{
public:
	sf::Vector2f size;
	float rotation;
	sf::Color color;
	sf::RectangleShape shape;

	Line(float xPos_, float yPos_, float xSize_, float ySize_, float rotation_);
	Line(sf::Vector2f line1, sf::Vector2f line2);

	virtual void draw(sf::RenderWindow* window) override; 
};