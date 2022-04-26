#pragma once
#ifndef Game_Class
#define Game_Class
#include<SFML\Graphics.hpp>
#include<thread>

#include"C:\Users\DELL\source\repos\sfml\sfml\button11.h"
#define escape 27
#define step 121.2 
#define MAX 30
#define start 1
#define MAX_Dice 6
#define  Image_Width 728
#define Image_Hight 606

class Game
{
private:
	
	sf::VideoMode videomode;
	sf::Event ev;
	sf::CircleShape* player1;
	sf::CircleShape* player2;
	sf::Font font;
	sf::Text text;
	sf::Text text1;
	float player_radius;
	sf::Texture background;
	sf::Sprite* s;
	float player_width;
	float player_height;
	
	// -------- private methods -------- //
	//initialize window
	void Init_Window();
	char intToChar(int);
	//poll event
	void pollEvent();
	//creat player 1 shape
	void CreatShape1();
	void CreatShape2();

public:

	button11* but1;
	sf::RenderWindow Window1;
	sf::RenderWindow* Window=& Window1;
	//defalut constructor
	Game();
	//check window is open
	bool running();
	//update game
	void update();
	//move players
	void move_playe1();
	void move_playe2();
	//rander 
	void rander(int);
	//defalut deconstructor
	sf::Vector2f getplayer1_pos();
	sf::Vector2f getplayer2_pos();
	//mov players to specific cell
	void mov_player1_to(int);
	void mov_player2_to(int);
	void delay(int);
	int dice();
	~Game();
};
#endif // !Game_Class