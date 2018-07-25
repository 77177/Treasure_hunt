
#include <iostream>
#include <time.h>
#include <list>
#include <conio.h>

using namespace std;

struct player
{
public:
	int place[2];
	char SAVE;
};


void print_play_field(char field[30][30])
{
	for (int i = 0; i < 30; i++)
	{
		cout << field[i][0] << field[i][1] << field[i][2] << field[i][3] << field[i][4]
			<< field[i][5] << field[i][6] << field[i][7] << field[i][8] << field[i][9]
			<< field[i][10] << field[i][11] << field[i][12] << field[i][13] << field[i][14]
			<< field[i][15] << field[i][16] << field[i][17] << field[i][18] << field[i][19]
			<< field[i][20] << field[i][21] << field[i][22] << field[i][23] << field[i][24]
			<< field[i][25] << field[i][26] << field[i][27] << field[i][28] << field[i][29] << endl;
	}
}



int main()
{
	bool end = false, moved = false;
	srand(time(NULL));
	int g = 0;
	player play, en;
	char field[30][30], choice = 'k';
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			field[i][j] = ' ';
		}
	}

	//SETING UP POSITIONS FOR THE GAME
	play.place[0] = rand() % 30;
	play.place[1] = rand() % 30;
	play.SAVE = field[play.place[0]][play.place[1]];
	field[play.place[0]][play.place[1]] = 'X';
	int a, b;
	do
	{
		a = rand() % 30;
		b = rand() % 30;
	} while (field[a][b] != '-' && b != 29);
	en.place[0] = a;
	en.place[1] = b;
	en.SAVE = field[en.place[0]][en.place[1]];
	field[en.place[0]][en.place[1]] = 'E';
	field[en.place[0]][en.place[1] + 1] = 'S';

	//START INTERFACE
	cout << "/////////////////////////////////////" << endl;
	cout << "TREASURE HUNT GAME" << endl;
	cout << "/////////////////////////////////////" << endl << endl;
	cout << "X - player" << endl;
	cout << "E - Monster" << endl;
	cout << "S - Treasure" << endl;
	cout << "Use WASD to move around" << endl;
	cout << endl << "Press any key to continue..." << endl;
	cin.get();


	do
	{
		system("cls");
		print_play_field(field);

		//CHECK FOR A NEW DIRCETION FOR THE PLAYER TO MOVE
		if (_kbhit() == true)
		{
			choice = _getch();
			char flush = _getch();
			//moved = true;
		}

		//PLAYER MOVE
		switch (choice)
		{
		case 'a':
		{
			field[play.place[0]][play.place[1]] = play.SAVE;
			if (play.place[1] != 0)
			{
				play.place[1] -= 1;
			}
			play.SAVE = field[play.place[0]][play.place[1]];
			field[play.place[0]][play.place[1]] = 'X';
			break;
		}
		case 'd':
		{
			field[play.place[0]][play.place[1]] = play.SAVE;
			if (play.place[1] != 29)
			{
				play.place[1] += 1;
			}
			play.SAVE = field[play.place[0]][play.place[1]];
			field[play.place[0]][play.place[1]] = 'X';
			break;
		}
		case 'w':
		{
			field[play.place[0]][play.place[1]] = play.SAVE;
			if (play.place[0] != 0)
			{
				play.place[0] -= 1;
			}
			play.SAVE = field[play.place[0]][play.place[1]];
			field[play.place[0]][play.place[1]] = 'X';
			break;
		}
		case 's':
		{
			field[play.place[0]][play.place[1]] = play.SAVE;
			if (play.place[0] != 29)
			{
				play.place[0] += 1;
			}
			play.SAVE = field[play.place[0]][play.place[1]];
			field[play.place[0]][play.place[1]] = 'X';
			break;
		}
		}

		//MONSTER AI MOVE
		{
			if (en.place[0] == play.place[0] && en.place[1] > play.place[1])
			{
				field[en.place[0]][en.place[1]] = en.SAVE;
				en.place[1] -= 1;
				en.SAVE = field[en.place[0]][en.place[1]];
				field[en.place[0]][en.place[1]] = 'E';
			}
			else if (en.place[0] == play.place[0] && en.place[1] < play.place[1])
			{
				field[en.place[0]][en.place[1]] = en.SAVE;
				en.place[1] += 1;
				en.SAVE = field[en.place[0]][en.place[1]];
				field[en.place[0]][en.place[1]] = 'E';
			}
			else if (en.place[1] == play.place[1] && en.place[0] > play.place[0])
			{
				field[en.place[0]][en.place[1]] = en.SAVE;
				en.place[0] -= 1;
				en.SAVE = field[en.place[0]][en.place[1]];
				field[en.place[0]][en.place[1]] = 'E';
			}
			else if (en.place[1] == play.place[1] && en.place[0] < play.place[0])
			{
				field[en.place[0]][en.place[1]] = en.SAVE;
				en.place[0] += 1;
				en.SAVE = field[en.place[0]][en.place[1]];
				field[en.place[0]][en.place[1]] = 'E';
			}
			else if (en.place[0] > play.place[0] && en.place[1] > play.place[1])
			{
				int comp_choice;
				comp_choice = rand() % 2;
				switch (comp_choice)
				{
				case 0:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[0] -= 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				case 1:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[1] -= 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				}
			}
			else if (en.place[0] > play.place[0] && en.place[1] < play.place[1])
			{
				int comp_choice;
				comp_choice = rand() % 2;
				switch (comp_choice)
				{
				case 0:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[0] -= 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				case 1:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[1] += 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				}
			}
			else if (en.place[0] < play.place[0] && en.place[1] < play.place[1])
			{
				int comp_choice;
				comp_choice = rand() % 2;
				switch (comp_choice)
				{
				case 0:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[0] += 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				case 1:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[1] += 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				}
			}
			else if (en.place[0] < play.place[0] && en.place[1] > play.place[1])
			{
				int comp_choice;
				comp_choice = rand() % 2;
				switch (comp_choice)
				{
				case 0:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[0] += 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				case 1:
				{
					field[en.place[0]][en.place[1]] = en.SAVE;
					en.place[1] -= 1;
					en.SAVE = field[en.place[0]][en.place[1]];
					field[en.place[0]][en.place[1]] = 'E';
					break;
				}
				}
			}
			if (en.SAVE == 'X' || play.SAVE == 'E' || play.SAVE == 'S')
			{
				end = true;
			}
		}
	} while (end == false);//THE ITERATION PROCEEDS WHILE THE CONDITIONS FOR ENDING AREN'T ACHIEVED
	system("cls");

	if (en.SAVE == 'X' || play.SAVE == 'E')
	{
		field[en.place[0]][en.place[1]] = 'E';
		cout << "You've been eaten up by the monster!" << endl;
	}
	else if (play.SAVE == 'S')
	{
		field[play.place[0]][play.place[1]] = 'S';
		cout << "You've found the treasure!" << endl;
	}
	cin.get();
	return 0;
}

