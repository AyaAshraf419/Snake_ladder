#include "Game.h"
using namespace std;
void Game::Init_Window()
{
	this->but1 = new button11( { 100, 40 }, { 738,302 }, 30, sf::Color::Blue);
	srand(time(0));
	this->videomode.width = 848;// 728;
	this->videomode.height = 650;// 606;
	this->player_width = Image_Width/6;
	this->player_height = Image_Hight/5;
	this->player_radius = Image_Width/12.0f;
	this->Window = new sf::RenderWindow(this->videomode, "Snake and Ladder",sf::Style::Titlebar | sf::Style::Close);
	this->CreatShape1();
	this->CreatShape2();
	this->background.loadFromFile("snake&ladder/snake and ladder.png");
	this->s = new sf::Sprite(this->background);
	if(!this->font.loadFromFile("snake&ladder/OpenSans-SemiBoldItalic.ttf"))
		printf("Error!!\n");
	this->text.setFont(this->font);
	this->text1.setFont(this->font);
}
Game::Game()
{
	this->Init_Window();
	printf("Start Game\n");
}
bool Game::running()
{
	return this->Window->isOpen();
}
void Game::pollEvent()
{
	while (this->Window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->Window->close();
			break;
		case sf::Event::TextEntered:
			printf("%c\n", this->ev.text.unicode);
			//A --> 65 , a --> 97 , Escape --> 27
			if (this->ev.text.unicode == escape)
				this->Window->close();
		case sf::Event::MouseMoved:
			if (this->but1->isMouseOver(*this->Window)) {
				this->but1->setBackColor(sf::Color::Red);
			}
			else 
			{
				this->but1->setBackColor(sf::Color::Blue);
			}
			break;
		}
		
	}
}
void Game::update()
{
	this->pollEvent();
}   
void Game::rander(int dice_value)
{
	this->Window->clear(sf::Color::White);
	this->Window->draw(*this->s);
	this->Window->draw(*this->player1);
	this->Window->draw(*this->player2);
	this->text.setPosition((5.0f / 6.0f) * Image_Width/2, Image_Hight);
	this->text1.setPosition(730, 344);
	this->text.setFillColor(sf::Color::Black);
	this->text1.setFillColor(sf::Color::Black);
	this->text.setString("Dice Value: ");
	this->text1.setString(" p1 turn  ");
	this->Window->draw(this->text);
	this->text.setPosition((5.0f / 6.0f) * Image_Width / 2  + 155.0f, Image_Hight);
	this->text.setFillColor(sf::Color::Magenta);
	this->text.setString(this->intToChar(dice_value));
	this->Window->draw(this->text);
	this->Window->draw(this->text1);
	this->but1->drawTo(*this->Window);
	this->Window->display();

}
void Game::CreatShape1()
{
	this->player1 = new sf::CircleShape(this->player_radius);
	this->player1->setFillColor(sf::Color(0,255,255,255));
	sf::Texture b;
	b.loadFromFile("C:/Users/MG/source/repos/SFML/Walk4Frames.png");
	this->player1->setTexture(&b);
	this->player1->setPosition(0, Image_Hight - this->player_height);//H - H/5 = 4/5 H
}
void Game::CreatShape2()
{
	this->player2 = new sf::CircleShape(player_radius);
	this->player2->setFillColor(sf::Color(0,0,0,255));
	sf::Texture b;
	b.loadFromFile("C:/Users/MG/source/repos/SFML/background.jpg");
	this->player2->setTexture(&b);
	this->player2->setPosition(0, Image_Hight - this->player_height);
}
sf::Vector2f Game::getplayer1_pos()
{
	return this->player1->getPosition();
}
sf::Vector2f Game::getplayer2_pos()
{
	return this->player2->getPosition();
}
void Game::mov_player1_to(int n)
{
	n = n > 30 ? 30 : n;
	int index = (n % 6 == 0 ? (n / 6) : (n / 6) + 1);
	sf::Vector2f v;
	int w1 = index > 1 ? n - 6 * (index-1) : n;
	v.x = index % 2 == 1 ? (w1 % 7 -1)*this->player_width : Image_Width - (w1 % 7) * this->player_width;
	v.y = Image_Hight - index*this->player_height;
	//printf("n: %d\nindex: %d\nv.x: %f\nv.y: %f\n", n, index, v.x, v.y);
	this->player1->setPosition(v.x, v.y);
}
void Game::mov_player2_to(int n)
{
	int index = (n % 6 == 0 ? (n / 6) : (n / 6) + 1);
	sf::Vector2f v;
	int w1 = index > 1 ? n - 6 * (index - 1) : n;
	v.x = index % 2 == 1 ? (w1 % 7 - 1) * this->player_width : Image_Width - (w1 % 7) * this->player_width;
	v.y = Image_Hight - index * this->player_height;
	//printf("n: %d\nindex: %d\nv.x: %f\nv.y: %f\n", n, index, v.x, v.y);
	this->player2->setPosition(v.x, v.y);
}
void Game::delay(int sec)
{
	std::this_thread::sleep_for(std::chrono::nanoseconds(10 * sec));
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(sec));
}
int Game::dice()
{
	return ((rand() % 6) + 1);
}
char Game::intToChar(int n)
{
	return n + '0';
}
Game::~Game()
{
	printf("End Game\n");
}
