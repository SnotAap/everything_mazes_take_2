#include "Header.h"
void Button::draw(sf::RenderWindow* window)
{
	if (!textOnly)
	{
		window->draw(shape);
	}
	window->draw(text);
}

Button::Button()
{
	position = sf::Vector2f(0, 0);		
	shape.setPosition(position);	
	shape.setFillColor(sf::Color(0, 191, 255, 255));	
	sentence = "not specified";
	text.setString(sentence);
	text.setPosition(position);	
	if (!font.loadFromFile(fontDirectory))
	{

	}	
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setScale(0.5, 0.5);
	size = sf::Vector2f(text.getGlobalBounds().width * 1.1f, text.getGlobalBounds().height * 1.5f);
	shape.setSize(size);
}

Button::Button(float x_, float y_, float scale, std::string sentence_, bool textOnly_)
{	
	position = sf::Vector2f(x_, y_);
	shape.setPosition(position);	
	shape.setFillColor(sf::Color(0, 0, 0, 69));	
	sentence = sentence_;
	text.setString(sentence);
	if (!font.loadFromFile(fontDirectory))
	{

	}
	text.setFont(font);
	text.setPosition(position);
	text.setScale(sf::Vector2f(scale, scale));
	text.setFillColor(sf::Color::Black);		
	size = sf::Vector2f(text.getGlobalBounds().width * 1.1f, text.getGlobalBounds().height * 1.5f);
	shape.setSize(size);	
	shape.setOrigin(size.x/2, size.y/2);
	text.setOrigin(shape.getOrigin().x, shape.getOrigin().y);
	textOnly = textOnly_;
}

Button::~Button()
{

}



