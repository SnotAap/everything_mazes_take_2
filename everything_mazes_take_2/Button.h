#pragma once
class Button : public Object
{
public:
	sf::RectangleShape shape;
	sf::Vector2f size;
	std::string sentence;
	sf::Color color = sf::Color::Black;
	sf::Font font;
	sf::Text text;
	std::string fontDirectory = "..\\content\\arial.ttf";
	bool IsPressed = false;	
	bool textOnly = false;

	Button();
	Button(float x_, float y_, float scale, std::string sentence_, bool textOnly_ = false);
	~Button();
	virtual void draw(sf::RenderWindow* window) override;
};