#include "button11.h"


void button11::setBackColor(sf::Color color) //set button color
{
	button.setFillColor(color);
}

void button11::drawTo(sf::RenderWindow& window) //button drawing 
{
	window.draw(button);
}

// Check if the mouse is within the bounds of the button:
bool button11::isMouseOver(sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x; //get mouse x position
	int mouseY = sf::Mouse::getPosition(window).y;//get mouse y position

	int btnPosX = button.getPosition().x;//get button x position
	int btnPosY = button.getPosition().y;//get button y position

	int btnxPosWidth = button.getPosition().x + btnWidth;
	int btnyPosHeight = button.getPosition().y + btnHeight;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) 
	//check if the mouse with in buttton region
	{
		return true;
	}
	return false;
}
// Check if the mouse is clicked
bool button11::button_isClicked(sf::RenderWindow& window)
{
	// when the mouse became over the button window &clicked return 1
	if (isMouseOver(window))   
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// left mouse button is pressed: shoot
			return 1;
		}
	}
}

