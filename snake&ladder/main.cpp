#include<iostream>
#include"Game.h"
#include"List.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
	auto s = high_resolution_clock::now();
	Game game;
	List list;
	list.insert_30();
	Node* player1 = list.Get_Head();
	Node* player2 = list.Get_Head();
	
	int pos1 = 0;
	int pos2 = 0;
	int dice_value = 0;
	int control = 0;
	char ch;
	char name1[20];
	char name2[20];
	printf("player 1 name: ");
	std::cin >> name1;
	printf("player 2 name: ");
	std::cin >> name2;
	while (game.running())
	{
		game.rander(dice_value);
	label:
		game.update();
		//printf("Enter\nx          --> exit game\nother char --> continue\n");
		//std::cin >> ch;
		//if (ch == 'x')
			//return 0;
		control % 2 == 0 ? printf("turn of %s\n", name1) : printf("turn of %s\n", name2);
		dice_value = game.dice();
		printf("dice: %d\n", dice_value);
		//player 1
		lxabel_j:
		if (!(control % 2))
		{
			game.update();
			while (!game.but1->button_isClicked(*game.Window))
			{
				game.update();
				if (game.but1->isMouseOver(*game.Window)) {
					game.but1->setBackColor(sf::Color::Red);
				}
				else
				{
					game.but1->setBackColor(sf::Color::Blue);
				}
				game.update();
			}
			if (pos1 + dice_value <= MAX)
			{
				game.update();
				for (int i = 1; i <= dice_value; i++)
				{
					pos1 = list.movement(&player1);
					game.mov_player1_to(pos1);
					game.rander(dice_value);
					game.delay(1);
				}
			}
			else
			{
				game.update();
				printf("Oooops!!\n");
				game.rander(dice_value);
				control = (dice_value == MAX_Dice ? control : control + 1);
				goto label;
			}
			if (pos1 == MAX)
			{
				game.update();
				printf("%s is winning\n", name1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - s);
				cout << "\nTime taken by function : " << duration.count() << " seconds"<<endl;
				return 0;
			}
			if (pos1 == 11 || pos1 == 3 || pos1 == 20 || pos1 == 5 || pos1 == 17 || pos1 == 19 || pos1 == 21 || pos1 == 27)
			{
				game.update();
				pos1 = list.move2(&player1);
				game.mov_player1_to(pos1);
				game.rander(dice_value);
			}
			printf("pos: %d\n", pos1);
		}
		//player 2
		else
		{
			game.update();
			if (pos2 + dice_value <= MAX)
			{
				game.update();

				for (int i = 1; i <= dice_value; i++)
				{
					game.update();
					pos2 = list.movement(&player2);
					game.mov_player2_to(pos2);
					game.rander(dice_value);
					game.delay(1);
				}
			}
			else
			{
				game.update();
				printf("Oooops!!\n");
				game.rander(dice_value);
				control = (dice_value == MAX_Dice ? control : control + 1);	// if reach last raw and 
																			// get numner greater than 30 and dice 6 (extra dice)
				goto label;
			}
			//if win
			if (pos2 == MAX)
			{
				game.update();
				printf("%s is winning\n", name2);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<seconds>(stop - s);
				cout << "\nTime taken by function : " << duration.count()  << " seconds" << endl;
				return 0;
			}
			//if there is snake or ladder
			if (pos2 == 11 || pos2 == 3 || pos2 == 20 || pos2 == 5 || pos2 == 17 || pos2 == 19 || pos2 == 21 || pos2 == 27)
			{
				game.update();
				pos2 = list.move2(&player2);
				game.mov_player2_to(pos2);
				game.rander(dice_value);
			}
			printf("pos: %d\n", pos2);
		}
		//player 1 reach player 2
		if (control % 2 == 0)
		{
			game.update();
			if (pos1 == pos2)
			{
				pos2 = start;
				player2 = list.Get_Head();
				game.mov_player2_to(pos2);
				game.rander(dice_value);
			}
		}
		//player 2 reach player 1
		else
		{
			game.update();
			if (pos1 == pos2)
			{
				pos1 = start;
				player1 = list.Get_Head();
				game.mov_player1_to(pos1);
				game.rander(dice_value);
			}
		}
		game.update();
		control = dice_value == MAX_Dice ? control : control + 1;
		if (player1->next != NULL && player2->next != NULL && pos1 != MAX && pos2 != MAX)
			goto label;
	}
	
	return 0;
	}
