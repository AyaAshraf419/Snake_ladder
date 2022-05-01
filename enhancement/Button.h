#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Button
{
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	int button_width;
	int button_hight;
public:
	Button(sf::Vector2f,sf::Vector2f,int,sf::Color,sf::Color);		// parameterized constructor
	void setBackColor(sf::Color);									// function to set background color of button
	void drawTo(sf::RenderWindow*);									// function to draw button and text on window
	bool isMouseOver(sf::RenderWindow*);							// function to check if mouse is over on button or not
	bool isClicked(sf::RenderWindow*);								// function to check if button clicked or not
};

