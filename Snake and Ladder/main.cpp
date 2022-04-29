#include<iostream>
#include"Game.h"
#include"List.h"
#include"Button.h"
#define Snake_Ladder_100
int main()
{
	#ifdef Snake_Ladder_30
	Game game;
	auto start_time = high_resolution_clock::now();
	List list;
	list.insert_30();
	Node* player1 = list.Get_Head();
	Node* player2 = list.Get_Head();
	int pos1 = 0;					
	int pos2 = 0;					
	int dice_value=0;				
	int control = 0;
	auto wait_time = 0;
	while (game.running())
	{
		game.rander(dice_value, control);
	label:
		game.update();
		control % 2 == 0 ? printf("turn of %s\n", game.name1) : printf("turn of %s\n", game.name2);
		dice_value = game.dice();
		printf("dice: %d\n", dice_value);
		//player 1
		if ((control % 2 == 0))
		{
			auto start_wait_time = high_resolution_clock::now();
			while (!game.button1->isClicked(game.Window))		// wait untill press button
			{
				game.update();
			}
			auto end_wait_time = high_resolution_clock::now();
			wait_time+= duration_cast <seconds>(end_wait_time - start_wait_time).count();
			if (pos1 + dice_value <= MAX)
			{
				for (int i = 1; i <= dice_value; i++)
				{
					pos1 = list.movement(&player1);
					game.mov_player1_to(pos1);
					game.rander(dice_value, control);
					game.delay(1);
				}
			}
			else
			{
				printf("Oooops, you exceed Max Value!!\n");									
				game.rander(dice_value, control);
				control = (dice_value == MAX_Dice ? control : control + 1);
				goto label;
			}
			if (pos1 == MAX)
			{
				printf("%s is winning\n", game.name1);
				goto end;
			}
			if (pos1 == 11 || pos1 == 3 || pos1 == 20 || pos1 == 5 || pos1 == 17 || pos1 == 19 || pos1 == 21 || pos1 == 27)
			{	
				pos1 = list.move2(&player1);
				game.mov_player1_to(pos1);
				game.rander(dice_value, control);
			}
			printf("pos: %d\n", pos1);
		}
		//player 2
		else
		{
			auto start_wait_time = high_resolution_clock::now();
			while (!game.button1->isClicked(game.Window) && game.option == 2)
				game.update();
			auto end_wait_time = high_resolution_clock::now();
			wait_time += duration_cast <seconds>(end_wait_time - start_wait_time).count();
			if (pos2 + dice_value <= MAX)
			{
				for (int i = 1; i <= dice_value; i++)
				{
					pos2 = list.movement(&player2);
					game.mov_player2_to(pos2);
					game.rander(dice_value, control);
					game.delay(1);
				}
			}
			else
			{
				printf("Oooops, you exceed Max Value!!\n");
				game.rander(dice_value, control);
				control = (dice_value == MAX_Dice ? control : control + 1);	// if reach last raw and 
																			// get numner greater than 30 and dice 6 (extra dice)
				goto label;
			}
			//if win
			if (pos2 == MAX)
			{
				printf("%s is winning\n", game.name2);
				goto end;
			}
			//if there is snake or ladder
			if (pos2 == 11 || pos2 == 3 || pos2 == 20 || pos2 == 5 || pos2 == 17 || pos2 == 19 || pos2 == 21 || pos2 == 27)
			{
				pos2 = list.move2(&player2);
				game.mov_player2_to(pos2);
				game.rander(dice_value, control);
			}
			printf("pos: %d\n", pos2);
		}
		//player 1 reach player 2
		if (control % 2 == 0)
		{
			if (pos1 == pos2)
			{
				pos2 = start;
				player2 = list.Get_Head();
				game.mov_player2_to(pos2);
				game.rander(dice_value, control);
			}
		}
		//player 2 reach player 1
		else
		{
			if (pos1 == pos2)
			{
				pos1 = start;
				player1 = list.Get_Head();
				game.mov_player1_to(pos1);
				game.rander(dice_value, control);
			}
		}
		control = dice_value == MAX_Dice ? control : control + 1;
		if (player1->next != NULL && player2->next != NULL && pos1 != MAX && pos2 != MAX)
			goto label;
	}
	end:
	auto end_time = high_resolution_clock::now();
	auto ms = duration_cast <seconds>(end_time - start_time).count();
	std::cout << "Total Time " << ms << " seconds\n";
	std::cout << "Waiting Time for players to push button: " << wait_time << " seconds\n";
	std::cout << "Exact Time: " << ms - wait_time << " seconds\n";
	#endif
	#ifdef Snake_Ladder_100
	Game game;
	auto start_time = high_resolution_clock::now();
	List list;
	list.insert_100();
	Node* player1 = list.Get_Head();
	Node* player2 = list.Get_Head();
	int pos1 = 0;
	int pos2 = 0;
	int dice_value = 0;
	int control = 0;
	auto wait_time = 0;
	//list.Display(list.Get_Head());
	while (game.running())
	{
		game.rander(dice_value, control);
	label:
		game.update();
		control % 2 == 0 ? printf("turn of %s\n", game.name1) : printf("turn of %s\n", game.name2);
		dice_value = game.dice();
		printf("dice: %d\n", dice_value);
		//player 1
		if ((control % 2 == 0))
		{
			auto start_wait_time = high_resolution_clock::now();
			while (!game.button1->isClicked(game.Window))		// wait untill press button
			{
				game.update();
			}
			auto end_wait_time = high_resolution_clock::now();
			wait_time += duration_cast <seconds>(end_wait_time - start_wait_time).count();
			if (pos1 + dice_value <= MAX)
			{
				for (int i = 1; i <= dice_value; i++)
				{
					pos1 = list.movement(&player1);
					game.mov_player1_to(pos1);
					game.rander(dice_value, control);
					game.delay(1);
				}
			}
			else
			{
				printf("Oooops, you exceed Max Value!!\n");
				game.rander(dice_value, control);
				control = (dice_value == MAX_Dice ? control : control + 1);
				goto label;
			}
			if (pos1 == MAX)
			{
				printf("%s is winning\n", game.name1);
				goto end;
			}
			if (pos1 == 4 || pos1 == 10 || pos1 == 14 || pos1 == 33 || pos1 == 64 || pos1 == 74 || pos1 == 40 || pos1 == 50 || pos1 == 81 || pos1 == 95 || pos1 == 92) 
			{
				pos1 = list.move2(&player1);
				game.mov_player1_to(pos1);
				game.rander(dice_value, control);
			}
			printf("pos: %d\n", pos1);
		}
		//player 2
		else
		{
			auto start_wait_time = high_resolution_clock::now();
			while (!game.button1->isClicked(game.Window) && game.option == 2)
				game.update();
			auto end_wait_time = high_resolution_clock::now();
			wait_time += duration_cast <seconds>(end_wait_time - start_wait_time).count();
			if (pos2 + dice_value <= MAX)
			{
				for (int i = 1; i <= dice_value; i++)
				{
					pos2 = list.movement(&player2);
					game.mov_player2_to(pos2);
					game.rander(dice_value, control);
					game.delay(1);
				}
			}
			else
			{
				printf("Oooops, you exceed Max Value!!\n");
				game.rander(dice_value, control);
				control = (dice_value == MAX_Dice ? control : control + 1);	// if reach last raw and 
																			// get numner greater than 30 and dice 6 (extra dice)
				goto label;
			}
			//if win
			if (pos2 == MAX)
			{
				printf("%s is winning\n", game.name2);
				goto end;
			}
			//if there is snake or ladder
			if (pos2 == 4 || pos2 == 10 || pos2 == 14 || pos2 == 33 || pos2 == 64 || pos2 == 74 || pos2 == 40 || pos2 == 50 || pos2 == 81 || pos2 == 95 || pos2 == 92)
			{
				pos2 = list.move2(&player2);
				game.mov_player2_to(pos2);
				game.rander(dice_value, control);
			}
			printf("pos: %d\n", pos2);
		}
		//player 1 reach player 2
		if (control % 2 == 0)
		{
			if (pos1 == pos2)
			{
				pos2 = start;
				player2 = list.Get_Head();
				game.mov_player2_to(pos2);
				game.rander(dice_value, control);
			}
		}
		//player 2 reach player 1
		else
		{
			if (pos1 == pos2)
			{
				pos1 = start;
				player1 = list.Get_Head();
				game.mov_player1_to(pos1);
				game.rander(dice_value, control);
			}
		}
		control = dice_value == MAX_Dice ? control : control + 1;
		if (player1->next != NULL && player2->next != NULL && pos1 != MAX && pos2 != MAX)
			goto label;
	}
end:
	auto end_time = high_resolution_clock::now();
	auto ms = duration_cast <seconds>(end_time - start_time).count();
	std::cout << "Total Time " << ms << " seconds\n";
	std::cout << "Waiting Time for players to push button: " << wait_time << " seconds\n";
	std::cout << "Exact Time: " << ms - wait_time << " seconds\n";
	#endif
	return 0;
}