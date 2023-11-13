#include "Header.h"

void Text::draw(sf::RenderWindow* window)
{
	window->draw(text);
}

Text::Text()
{
	position = sf::Vector2f(0.0f, 0.0f);
	text.setPosition(position);
	scale = sf::Vector2f(1.0f, 1.0f);
	text.setScale(scale);
	sentence = "not defined";
	text.setString(sentence);
	if (!font.loadFromFile(fontDirectory))
	{
		
	}
	text.setFont(font);
	text.setFillColor(color);
}

Text::Text(std::string string, sf::Font& font, sf::Vector2f scale_, sf::Vector2f position_)
{
	position = position_;
	text.setPosition(position);
	scale = scale_;
	text.setScale(scale);
	sentence = string;
	text.setString(sentence);
	text.setFont(font);
	text.setFillColor(color);
}