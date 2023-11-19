#pragma once
class Text : public Object
{
public:
	sf::Vector2f position;
	std::string sentence;
	sf::Color color = sf::Color::Black;
	
	sf::Text text;
	sf::Vector2f scale;
	std::string fontDirectory = "..\\content\\arial.ttf";	
	sf::Font font;
	
	
	
	virtual void draw(sf::RenderWindow* window) override;
	Text();
	Text(std::string string, sf::Font& font, sf::Vector2f scale_, sf::Vector2f position_);
	~Text();
	
};