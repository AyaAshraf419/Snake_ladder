#pragma once
#ifndef Game_Class
#define Game_Class
#include<SFML\Graphics.hpp>		// SFML libray which contain all thing we need in Graphics ^_^
#include"Button.h"				// call Button Class 
#include<thread>				// thread library used to generate delay in game
#include<ctime>					// time library used in generation random values of dice
#include<chrono>				// library to get clock now
using namespace std::chrono;	// to use its functions without library naem in beginning
#define escape 27				// Ascii for Escape button keyboard
#define step 121.2				// step of movement
#define MAX 30					// Max number in snake and ladder board
#define start 1					// start of snake and ladder board
#define MAX_Dice 6				// Maximum number can appear in dice
#define Window_Width 848		// Width of Window
#define Window_Hight 650		// Hight of Window
#define  Image_Width 728		// background image Width
#define Image_Hight 606			// background image Hight

class Game
{
private:
	// -------- private variables -------- //
	sf::VideoMode videomode;		// videomode object
	sf::Event ev;					// object used to deal with any interaction with winodw
	sf::CircleShape* player1;		// player 1 object
	sf::CircleShape* player2;		// player 2 object
	sf::Font font;					// font fot text
	sf::Text text;					// text object
	sf::Texture background;			// backgound image object
	sf::Sprite* s;					// sprite object
	float player_width;				// player width
	float player_height;			// player hight
	float player_radius;			// player radius
	// -------- private functions -------- //
	void Init_Window();				// fun used to initalize all variables
	void pollEvent();				// fun used to detecte when user act with window (ex. exit window or push button)
	void CreatShape1();				// fun to creat shape of player 1
	void CreatShape2();				// fun to creat shape of player 2
	char intToChar(int);			// fun we need to converte 1 digit (0:9) to its equivalent character ('0','9')
public:
	// -------- private variables -------- //
	sf::RenderWindow* Window;		// take object from RenderWindow Class (is SFML library)
	Button* button1;				// take object from Button Class (which we implemented)
	char name1[20];					// var to store name of player 1
	char name2[20];					// var to store name of player 2
	int option;						// var to store game mode (player vs. compyter or player 1 vs. player 2)
	// -------- public functions -------- //
	Game();							// defalut constructor
	bool running();					// check window is open
	void update();					// update game
	void rander(int,int);			// rander function to draw 
	sf::Vector2f getplayer1_pos();	// fun to get position of player 1
	sf::Vector2f getplayer2_pos();	// fun to get position of player 2
	void mov_player1_to(int);		// fun to move player 1 to specific cell
	void mov_player2_to(int);		// fun to move player 2 to specific cell
	void delay(int);				// fun to delay between each movement
	int dice();						// fun to generate dice random values
	~Game();						// deconstructor
};
#endif // !Game_Class