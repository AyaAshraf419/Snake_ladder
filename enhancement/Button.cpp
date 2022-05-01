#include "Button.h"

Button::Button(sf::Vector2f button_size, sf::Vector2f button_position, int charSize, sf::Color button_background, sf::Color button_text_color)
{
	this->button.setSize(button_size);
	this->button.setFillColor(button_background);
	this->button.setPosition(button_position);
	this->button_width = button_size.x;
	this->button_hight = button_size.y;
	if (!this->font.loadFromFile("D:/OpenSans-SemiBoldItalic.ttf"))
		printf("Error!!\n");
	this->text.setFont(this->font);
	this->text.setCharacterSize(charSize);
	this->text.setPosition(this->button.getPosition().x / 2.0f - text.getGlobalBounds().width / 2.0f,
						   this->button.getPosition().y / 2.0f - text.getGlobalBounds().height / 2.0f);
}
void Button::setBackColor(sf::Color color)
{
	this->button.setFillColor(color);
}
void Button::drawTo(sf::RenderWindow* window)
{
	window->draw(this->button);
	window->draw(this->text);
}
bool Button::isMouseOver(sf::RenderWindow* window)
{
	int mouseX = sf::Mouse::getPosition(*window).x;
	int mouseY = sf::Mouse::getPosition(*window).y;
	int btnPosX = button.getPosition().x;
	int btnPosY = button.getPosition().y;
	int btnxPosWidth = button.getPosition().x + this->button_width;
	int btnyPosHeight = button.getPosition().y + this->button_hight;
	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
		return true;
	return false;
}
bool Button::isClicked(sf::RenderWindow* window)
{
	if (this->isMouseOver(window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
	}
	return false;
}