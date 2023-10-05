#include "Header.h"

void Line::draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

Line::Line(float xPos_, float yPos_, float xSize_, float ySize_, float rotation_)
{
	position = sf::Vector2f(xPos_, yPos_);
	size = sf::Vector2f(xSize_, ySize_);
	rotation = rotation_;
	color = sf::Color(0, 0, 0, 0);
	shape.setPosition(position);
	shape.setSize(size);
	shape.setRotation(rotation);
	shape.setFillColor(color);

}

Line::Line(sf::Vector2f line1, sf::Vector2f line2, float thickness)
{
	bool left = true;
	bool top = true;
	if (line1.x > line2.x) left = false;
	if (line1.y > line2.y) top = false;



	float differanceX = line2.x - line1.x;
	float differanceY = line2.y - line1.y;
	rotation = (float)(atan2(differanceY, differanceX) * 180 / 3.141592653589);

	size.x = (float)sqrt(pow(differanceY, 2) + pow(differanceX, 2));
	size.y = thickness;

	shape.setSize(size);
	shape.setFillColor(color);
	shape.setRotation(rotation);
	shape.setPosition(line1);
	shape.setOrigin(sf::Vector2f(0, size.y / 2));
}