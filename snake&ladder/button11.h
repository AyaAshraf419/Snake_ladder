#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class button11
{
public:
	button11( sf::Vector2f buttonSize, sf::Vector2f buttonPostion, int charSize, sf::Color bgColor) 
	//paramterized constructor to get intial values of thr button like:size,position,coler...etc
	{
		button.setSize(buttonSize);//out vector x,y
		button.setFillColor(bgColor);
		button.setPosition(buttonPostion);//out vector x,y
		// Get these for later use:
		btnWidth = buttonSize.x;
		btnHeight = buttonSize.y;
		pos_x = buttonPostion.x;
		pos_y = buttonPostion.y;
	}

	void setBackColor(sf::Color color);

	void drawTo(sf::RenderWindow& window);

	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(sf::RenderWindow& window);
	// Check if the mouse is clicked on the button:
	bool button_isClicked(sf::RenderWindow& window);

private:
	sf::RectangleShape button;//set button shape
	int btnWidth;
	int btnHeight;
	int pos_x;
	int pos_y;
};

