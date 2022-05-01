#include "Game.h"
#ifdef Snake_Ladder_30
void Game::Init_Window()
{
	srand(time(0));
	this->videomode.width = Window_Width;
	this->videomode.height = Window_Hight;
	this->player_width = Image_Width / 6;
	this->player_height = Image_Hight / 5;
	this->player_radius = Image_Width / 12.0f;
	this->Window = new sf::RenderWindow(this->videomode, "Snake and Ladder", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->CreatShape1();
	this->CreatShape2();
	this->background.loadFromFile("C:/Users/MG/source/repos/SFML/background.jpg");
	this->s = new sf::Sprite(this->background);
	if (!this->font.loadFromFile("E:/fonts/Open_Sans/OpenSans-SemiBoldItalic.ttf"))
		printf("Error!!\n");
	this->text.setFont(this->font);
	this->button1 = new Button({ 100,40 }, { 738,152 }, 10, sf::Color::Red, sf::Color::Black);
	this->button1->setBackColor(sf::Color::Red);
	printf("player 1 name: ");
	std::cin >> this->name1;
	printf("player 2 name: ");
	std::cin >> this->name2;
label:
	printf("\n1. Player vs. Computer\n2. Player 1 vs. Player 2\n");
	std::cin >> this->option;
	if (this->option != 1 && this->option != 2)
	{
		printf("Invalide input!! Enter either 1 or 2\n");
		goto label;
	}
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
			exit(0);
			break;
		case sf::Event::TextEntered:
			printf("%c\n", this->ev.text.unicode);
			if (this->ev.text.unicode == escape)
			{
				this->Window->close();
				exit(0);
			}
		case sf::Event::MouseMoved:
			if (this->button1->isMouseOver(this->Window))
				this->button1->setBackColor(sf::Color::Red);
			else
				this->button1->setBackColor(sf::Color::Blue);
			break;
		}
	}
}
void Game::update()
{
	this->pollEvent();
}   
void Game::rander(int dice_value, int turn)
{

	this->Window->clear(sf::Color::White);
	this->Window->draw(*this->s);
	this->Window->draw(*this->player1);
	this->Window->draw(*this->player2);

	this->button1->drawTo(this->Window);

	this->text.setPosition(753, 153);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("Click");
	this->Window->draw(this->text);

	this->text.setPosition(100.0f , Image_Hight);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("turn of: ");
	this->Window->draw(this->text);

	this->text.setPosition(220.0f, Image_Hight);
	this->text.setFillColor(sf::Color(252,3,119));
	turn % 2 == 0 ? this->text.setString(this->name1) : this->text.setString(this->name2);
	this->Window->draw(this->text);

	this->text.setPosition(480.0f , Image_Hight);
	this->text.setFillColor(sf::Color::Black);
	this->text.setString("Dice Value: ");
	this->Window->draw(this->text);

	this->text.setPosition(650.0f , Image_Hight);
	this->text.setFillColor(sf::Color::Magenta);
	this->text.setString(this->intToChar(dice_value));
	this->Window->draw(this->text);

	
	this->Window->display();
}
void Game::CreatShape1()
{
	this->player1 = new sf::CircleShape(this->player_radius);
	this->player1->setFillColor(sf::Color(0,255,255,255));
	this->player1->setPosition(0, Image_Hight - this->player_height);
}
void Game::CreatShape2()
{
	this->player2 = new sf::CircleShape(player_radius);
	this->player2->setFillColor(sf::Color(0,0,0,255));
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
	this->player1->setPosition(v.x, v.y);
}
void Game::mov_player2_to(int n)
{
	int index = (n % 6 == 0 ? (n / 6) : (n / 6) + 1);
	sf::Vector2f v;
	int w1 = index > 1 ? n - 6 * (index - 1) : n;
	v.x = index % 2 == 1 ? (w1 % 7 - 1) * this->player_width : Image_Width - (w1 % 7) * this->player_width;
	v.y = Image_Hight - index * this->player_height;
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
#endif

